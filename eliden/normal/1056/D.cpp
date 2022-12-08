#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i,0,n-1) {
        int u,v;
        cin >> u;
        --u;
        v = i+1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> f(n+1);
    vector<int> par(n,-1);
    function<int(int u)> dfs = [&](int u) {
        bool leaf = true;
        int s = 0;
        for(int v:g[u]) {
            if(v!=par[u]) {
                leaf = false;
                par[v] = u;
                s+=dfs(v);
            }
        }
        if(leaf) ++s;
        ++f[s];
        return s;
    };
    dfs(0);
    //rep(i,1,n+1) debug(f[i]);
    int j=0;
    ll sum = 0;
    rep(i,1,n+1) {
        while(sum<i) {
            ++j;
            ll x = f[j];
            sum += x;
        }
        cout << j << " ";
    }
    cout << "\n";
}