#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int SIZE = 1 << 10;
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

const int MAXN = 1000000;

int from[1 + MAXN], to[1 + MAXN], cost[1 + MAXN], order[1 + MAXN], which[1 + MAXN], number = 0, components = 0;
long long dp[1 + MAXN], add[1 + MAXN];
bool seen[1 + MAXN];
vector<int> g[1 + MAXN], gt[1 + MAXN];
vector<pair<int, int> > dag[1 + MAXN];

void DFS(int node) {
    seen[node] = true;
    for (int i = 0; i < g[node].size(); i++)
        if (!seen[g[node][i]])
            DFS(g[node][i]);
    number++;
    order[number] = node;
}

void AntiDFS(int node) {
    seen[node] = false;
    which[node] = components;
    for (int i = 0; i < gt[node].size(); i++)
        if (seen[gt[node][i]])
            AntiDFS(gt[node][i]);
}

long long Compute(int x) {
    if (!x)
        return 0;
    int left = 1, right = x, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (1LL * middle * (middle + 1) / 2 <= x) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    return 1LL * x * (answer + 1) - (1LL * answer * (answer + 1) * (2 * answer + 1) / 6 + 1LL * answer * (answer + 1) / 2) / 2;
}

long long DP(int node) {
    if (dp[node] != -1)
        return dp[node];
    dp[node] = 0;
    for (int i = 0; i < dag[node].size(); i++) {
        DP(dag[node][i].first);
        dp[node] = max(dp[node], dp[dag[node][i].first] + dag[node][i].second);
    }
    dp[node] += add[node];
    return dp[node];
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read();
    for (int i = 1; i <= m; i++) {
        from[i] = Read();
        to[i] = Read();
        cost[i] = Read();
        g[from[i]].push_back(to[i]);
        gt[to[i]].push_back(from[i]);
    }
    int start = Read();
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        if (!seen[i])
            DFS(i);
    }
    for (int i = n; i >= 1; i--)
        if (seen[order[i]]) {
            components++;
            AntiDFS(order[i]);
        }
    for (int i = 1; i <= m; i++)
        if (which[from[i]] == which[to[i]])
            add[which[from[i]]] += Compute(cost[i]);
        else
            dag[which[from[i]]].push_back(make_pair(which[to[i]], cost[i]));
    printf("%I64d\n", DP(which[start]));
    return 0;
}