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
int n,a[1001],ans[1001];
vi f[33];
void solve(){
    memset(ans,0,sizeof ans);
    rep(i,2,33) f[i].clear();
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1){
        rep(j,2,32){
            if(a[i]%j==0){
                f[j].pb(i);
                break;
            }
        }
    }
    int cnt=1;
    rep(i,2,32){
        if(!sz(f[i])) continue;
        int ff=0;
        for(auto j:f[i]){
            if(!ans[j]){
                ans[j]=cnt;
                ff=1;
            }
        }
        if(ff) cnt++;
    }
    cout<<cnt-1<<endl;
    rep(i,1,n+1) cout<<ans[i]<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}