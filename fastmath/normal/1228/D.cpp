#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
const int N = 1e5 + 7;
vector <ii> ed;
set <ii> eds;
set <int> ms;
int ans[N];
void dfs(int u, int c) {
    ans[u] = c;
    ms.erase(u);        
    int v = 0;
    while (1) {
        auto t = ms.upper_bound(v); 
        if (t == ms.end()) break;
        v = *t;
        if (eds.find({u, v}) == eds.end()) dfs(v, c);
    }   
}   
int cnt[3];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        ed.app({u, v});
        eds.insert({u, v}); eds.insert({v, u});
    }   
    for (int i = 1; i <= n; ++i) ms.insert(i);
    int c = 1;
    while (ms.size()) { 
        dfs(*ms.begin(), c);
        ++c;
    }   
    if (c != 4) {
        cout << "-1\n";
        exit(0);
    }   
    for (auto e : ed) {
        if (ans[e.f] == ans[e.s]) {
            cout << "-1\n"; exit(0);
        }   
    }   
    for (int i = 1; i <= n; ++i) ++cnt[ans[i] - 1];
    if (m != cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[0] * cnt[2]) {
        cout << "-1\n";
        exit(0);
    }   
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << '\n';
}