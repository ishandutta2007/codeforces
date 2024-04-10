#include <bits/stdc++.h>

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

const int MAXN = 500000;
const long long INF = 1000000000000000000LL;

vector<int> g[1 + MAXN];
long long best = INF;
long long dp[1 + MAXN];
int n, weight[1 + MAXN];

inline bool Compare(const int &a, const int &b) {
    return weight[a] > weight[b];
}

struct Line {
    int a;
    long long b;

    long long Evaluate(int x) {
        return 1LL * a * x + b;
    }
};

long long Intersection(Line a, Line b) {
    long long answer =  (b.b - a.b) / (a.a - b.a) + 1;
    return answer;
}

Line Deque[1 + MAXN];
int start, finish;

void Add(Line d) {
    if (d.a == Deque[finish].a)
        if (d.b >= Deque[finish].b)
            return;
        else
            finish--;
    while (finish - start + 1 >= 2 && Intersection(Deque[finish], Deque[finish - 1]) >= Intersection(d, Deque[finish]))
        finish--;
    finish++;
    Deque[finish] = d;
}

long long Query(int x) {
    while (finish - start + 1 >= 2 && Intersection(Deque[finish], Deque[finish - 1]) > x)
        finish--;
    return Deque[finish].Evaluate(x);
}

void DFS(int node, int father) {
    for (int i = 0; i < g[node].size(); i++)
        if (g[node][i] == father) {
            swap(g[node][i], g[node].back());
            g[node].pop_back();
            break;
        }
    weight[node] = 1;
    if (g[node].empty()) {
        dp[node] = 1;
        return;
    }
    dp[node] = INF;
    for (auto &son : g[node]) {
        DFS(son, node);
        weight[node] += weight[son];
    }
    for (auto &son : g[node])
        dp[node] = min(dp[node], dp[son] + 1LL * (weight[node] - weight[son]) * (weight[node] - weight[son]));
    sort(g[node].begin(), g[node].end(), Compare);
    start = finish = 1;
    Deque[1] = {2 * weight[g[node][0]], -2LL * n * weight[g[node][0]] + dp[g[node][0]] + 1LL * weight[g[node][0]] * weight[g[node][0]]};
    for (int i = 1; i < g[node].size(); i++) {
        int x = g[node][i];
        best = min(best, 1LL * n * n + dp[x] - 2LL * n * weight[x] + 1LL * weight[x] * weight[x] + Query(weight[x]));
        Add({2 * weight[x], -2LL * n * weight[x] + dp[x] + 1LL * weight[x] * weight[x]});
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (n == 2) {
        printf("2\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 1) {
            DFS(i, 0);
            printf("%I64d\n", 1LL * n * (n - 1) / 2 + 1LL * n * (n - 1) / 2 - (best - n) / 2);
            return 0;
        }
    return 0;
}