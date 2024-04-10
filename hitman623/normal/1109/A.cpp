#include <bits/stdc++.h>

#define int         long long
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
int n,a[300005],ans,f[1<<20][2];
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i],a[i]^=a[i-1];
    rep(i,0,n+1) f[a[i]][i%2]++;
    rep(i,0,1<<20){
        ans+=f[i][0]*(f[i][0]-1)/2;
        ans+=f[i][1]*(f[i][1]-1)/2;
    }
    cout<<ans<<endl;
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