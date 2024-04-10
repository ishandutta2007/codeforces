#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    ll ans = 0;
    rep(i,0,n) {
        cin >> c[i];
        ans += c[i];
    }
    vector<int> deg(n);
    vector<vector<int>> g(n);
    rep(i,0,m) {
        int u, v;
        cin>>u>>v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    int s;
    cin >> s;
    --s;
    deg[s]+=5;
    queue<int> q;
    rep(i,0,n) if(deg[i]==1) q.push(i);
    //debug(ans);
    vector<ll> save(n);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        ans -= c[i];
        deg[i] = 0;
        //debug(i);
        save[i] += c[i];
        for(int j:g[i]) {
            --deg[j];
            if(deg[j]==1) {
                q.push(j);
            }
            if(deg[j]>0) {
                //debug(j);
                save[j] = max(save[j],save[i]);
            }
        }
        save[i] = 0;
    }
    ll best=0;
    rep(i,0,n) best=max(best,save[i]);
    ans += best;
    cout<<ans<<endl;
}