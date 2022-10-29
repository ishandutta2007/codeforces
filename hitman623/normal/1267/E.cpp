#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a[101][101];
vi ans;
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        ans.pb(i);
        rep(j,0,n){
            cin>>a[i][j];
        }
    }
    rep(i,0,n-1){
        vii v;
        vi vis(m,0);
        rep(j,0,m){
            v.pb({a[j][i]-a[j][n-1],j});
        }
        sort(all(v));
        reverse(all(v));
        int s=0;
        rep(j,0,m){
            s+=v[j].x;
            if(s<0) break;
            vis[v[j].y]=1;
        }
        vi rem;
        rep(j,0,m){
            if(vis[j]==0){
                rem.pb(j);
            }
        }
        if(sz(ans)>sz(rem)) ans=rem;
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans) cout<<i+1<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}