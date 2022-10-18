#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a, b;
vector<int> g[100105];
int cnt[2];

void dfs(int v, int clr, int p = -1) {
    ++cnt[clr];
    clr ^= 1;
    for (int to : g[v])
        if (to != p)
            dfs(to, clr, v);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    cout << ll(cnt[0]) * ll(cnt[1]) - (n - 1) << endl;

    return 0;
}