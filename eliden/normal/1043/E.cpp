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
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    rep(i,0,n) cin >> x[i] >> y[i];
    vector<vector<int>> adj(n);
    rep(i,0,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //ll sumx = 0;
    vector<pair<ll,int>> ord;
    rep(i,0,n) ord.emplace_back(x[i]-y[i],i);
    sort(all(ord));
    vector<int> pos(n);
    rep(i,0,n) pos[ord[i].second] = i;
    vector<ll> ans(n);
    vector<ll> sumlx(n), sumry(n);
    rep(i,0,n-1) sumlx[i+1] = sumlx[i]+x[ord[i].second];
    for(int i=n-1;i>0;--i) sumry[i-1] = sumry[i]+y[ord[i].second];
    rep(ii,0,n) {
        int j = ord[ii].second;
        int numl = ii, numr = n-(ii+1);
        for(int i:adj[j]) {
            if(pos[i]<ii) {
                --numl;
                ans[j]-=x[i];
            }
            else {
                --numr;
                ans[j]-=y[i];
            }
        }
        ans[j] += numl*y[j] + numr*x[j]+sumlx[ii]+sumry[ii];
    }
    rep(i,0,n) cout << ans[i] << " ";
    cout<<endl;
}