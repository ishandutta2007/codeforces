//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int MAXLOG = 19;

int v[1 + MAXN], bit, sum[1 + MAXN], dp[1 + MAXN][2];
vector<int> g[1 + MAXN];
long long total = 0;

void Precompute(int node, int father) {
    sum[node] = sum[father] ^ v[node];
    for (auto &son : g[node])
        if (son != father)
            Precompute(son, node);
}

void DFS(int node, int father) {
    long long add = 0;
    int preffix[2] = {0, 0};
    dp[node][0] = dp[node][1] = 0;
    if (sum[node] & (1 << bit))
        preffix[1]++;
    else
        preffix[0]++;
    if (v[node] & (1 << bit))
        add++;
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            if (v[node] & (1 << bit))
                add = add + 1LL * preffix[0] * dp[son][0] + 1LL * preffix[1] * dp[son][1];
            else
                add = add + 1LL * preffix[1] * dp[son][0] + 1LL * preffix[0] * dp[son][1];
            preffix[0] += dp[son][0];
            preffix[1] += dp[son][1];
        }
    dp[node][0] = preffix[0];
    dp[node][1] = preffix[1];
    total += add;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    Precompute(1, 0);
    long long answer = 0;
    for (bit = 0; bit <= MAXLOG; bit++) {
        total = 0;
        DFS(1, 0);
        answer = answer + total * (1 << bit);
    }
    cout << answer << "\n";
    return 0;
}