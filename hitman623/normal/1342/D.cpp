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
int n,k,c[200005],f[200005];
vi res[200005];
void solve(){
    cin>>n>>k;
    rep(i,1,n+1){
        int x;
        cin>>x;
        f[x]++;
    }
    rep(i,1,k+1) cin>>c[i];
    for(int i=k-1;i>=1;i--) f[i]+=f[i+1];
    int ans=0;
    rep(i,1,k+1){
        ans=max(ans,(f[i]+c[i]-1)/c[i]);
    }
    cout<<ans<<endl;
    int cur=0;
    for(int i=k;i>=1;i--){
        rep(j,0,f[i]-f[i+1]){
            res[cur].pb(i);
            cur=(cur+1)%ans;
        }
    }
    rep(i,0,ans){
        cout<<sz(res[i])<<" ";;
        for(auto j:res[i]) cout<<j<<" ";
        cout<<endl;
    }
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