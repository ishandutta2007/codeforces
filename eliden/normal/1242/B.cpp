#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    rep(i,0,m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> scratch(n);
    set<int> left;
    rep(i,0,n) left.insert(i);
    function<void(int)> dfs = [&](int u) {
        for(int v:g[u]) scratch[v] = true;
        set<int> next;
        vector<int> todo;
        for(int x:left) {
            if(scratch[x]) {
                next.insert(x);
            }
            else todo.push_back(x);
        }
        left = next;
        for(int v:g[u]) scratch[v] = false;
        for(int x:todo) dfs(x);
    };
    int ans = -1;
    rep(u,0,n) if(left.count(u)) {
        ++ans;
        left.erase(u);
        dfs(u);
    }
    cout<<ans<<endl;
}