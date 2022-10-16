#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 200000;

struct Problem {
    int limit;
    int t;
    int id;
    int where;
};

vector<int> solution;
Problem v[1 + MAXN];
int order[1 + MAXN];

bool CompareTime(Problem a, Problem b) {
    return a.t < b.t;
};

bool CompareLimit(Problem a, Problem b) {
    return a.limit < b.limit;
};

int active[1 + 4 * MAXN], sum[1 + 4 * MAXN];
bool out[1 + MAXN];

void Update(int node, int left, int right, Problem b) {
    if (left == right) {
        active[node] = 1;
        sum[node] = b.t;
        out[b.id] = false;
        return;
    }
    int middle = (left + right) / 2;
    if (b.where <= middle)
        Update(2 * node, left, middle, b);
    else
        Update(2 * node + 1, middle + 1, right, b);
    active[node] = active[2 * node] + active[2 * node + 1];
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}

int Query(int node, int left, int right, int howMany) {
    if (left == right)
        return sum[node];
    int middle = (left + right) / 2;
    if (active[2 * node] < howMany)
        return sum[2 * node] + Query(2 * node + 1, middle + 1, right, howMany - active[2 * node]);
    else
        return Query(2 * node, left, middle, howMany);
}

void GetSolution(int n, int x) {
    for (int i = 1; i <= n; i++)
        if (!out[order[i]]) {
            solution.push_back(order[i]);
            x--;
            if (!x)
                return;
        }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &v[i].limit, &v[i].t);
        v[i].id = i;
    }
    sort(v + 1, v + n + 1, CompareTime);
    for (int i = 1; i <= n; i++) {
        v[i].where = i;
        order[i] = v[i].id;
        out[i] = true;
    }
    sort(v + 1, v + n + 1, CompareLimit);
    int answer = 0;
    for (int i = n, j = n; i >= 1; i--) {
        while (j >= 1 && v[j].limit >= i) {
            Update(1, 1, n, v[j]);
            j--;
        }
        if (active[1] < i)
            continue;
        if (Query(1, 1, n, i) <= t) {
            answer = i;
            GetSolution(n, i);
            break;
        }
    }
    printf("%d\n", answer);
    printf("%d\n", solution.size());
    for (auto &it : solution)
        printf("%d ", it);
    return 0;
}