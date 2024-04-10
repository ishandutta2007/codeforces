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
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 200000;

vector<pair<int, long long> > g[1 + MAXN];
long long cost[1 + MAXN], answer[1 + MAXN];
priority_queue<pair<long long, int> > Heap;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        long long c;
        scanf("%d%d%I64d", &a, &b, &c);
        c *= 2;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &cost[i]);
        answer[i] = cost[i];
        Heap.push(make_pair(-cost[i], i));
    }
    while (!Heap.empty()) {
        int node = Heap.top().second;
        long long now = -Heap.top().first;
        Heap.pop();
        if (now != answer[node])
            continue;
        for (auto &it : g[node])
            if (answer[it.first] > answer[node] + it.second) {
                answer[it.first] = answer[node] + it.second;
                Heap.push(make_pair(-answer[it.first], it.first));
            }
    }
    for (int i = 1; i <= n; i++)
        printf("%I64d ", answer[i]);
    return 0;
}