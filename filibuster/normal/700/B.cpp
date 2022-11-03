#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/

vector<int> g[N];
bool is[N];
int cnt[N];
li ans = 0;
int k;

void dfs(int v, int par) {
    cnt[v] = is[v];

    for(auto u : g[v])
        if(u != par) {
            dfs(u, v);
            cnt[v] += cnt[u];
        }

//    if(cnt[v] <= k) {
//        ans += cnt[v];
//    } else {
//        ans += min(cnt[v], k - cnt[v]);
//    }
    ans += min(cnt[v], k * 2 - cnt[v]);
}


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n>> k;

    for(int i = 0; i < k * 2; i++) {
        int v;
        cin >> v;

        is[v - 1] = true;
    }

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0);

    cout << ans;
}