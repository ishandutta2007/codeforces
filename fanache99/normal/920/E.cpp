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
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        sign = -1;
        ch = Advance();
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

vector<int> g[1 + MAXN];
vector<int> components;
int dad[1 + MAXN], weight[1 + MAXN], toLeft[1 + MAXN + 1], toRight[1 + MAXN + 1], last[1 + MAXN], touched[1 + MAXN];

void Initialize(int n) {
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        toLeft[i] = i - 1;
        toRight[i] = i + 1;
        weight[i] = 1;
    }
    toLeft[n + 1] = n;
    toRight[0] = 1;
}

int FindDad(int node) {
    if (dad[node] == node)
        return node;
    return dad[node] = FindDad(dad[node]);
}

void Join(int a, int b) {
    a = FindDad(a);
    b = FindDad(b);
    if (rand() % 2) {
        dad[a] = b;
        weight[b] += weight[a];
        toRight[toLeft[a]] = toRight[a];
        toLeft[toRight[a]] = toLeft[a];
    }
    else {
        dad[b] = a;
        weight[a] += weight[b];
        toRight[toLeft[b]] = toRight[b];
        toLeft[toRight[b]] = toLeft[b];
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    srand(time(0));
    int n = Read(), m = Read();
    for (int i = 1; i <= m; i++) {
        int a = Read(), b = Read();
        g[max(a, b)].push_back(min(a, b));
    }
    Initialize(n);
    for (int i = 1; i <= n; i++) {
        for (auto &j : g[i]) {
            int it = FindDad(j);
            if (last[it] != i) {
                last[it] = i;
                touched[it] = 1;
            }
            else
                touched[it]++;
        }
        int p = toRight[0];
        vector<int> now;
        while (p < i) {
            if (last[p] != i || touched[p] != weight[p])
                now.push_back(p);
            p = toRight[p];
        }
        for (auto &it : now)
            Join(i, it);
    }
    for (int i = 1; i <= n; i++)
        if (dad[i] == i)
            components.push_back(weight[i]);
    sort(components.begin(), components.end());
    printf("%d\n", components.size());
    for (auto &it : components)
        printf("%d ", it);
    return 0;
}