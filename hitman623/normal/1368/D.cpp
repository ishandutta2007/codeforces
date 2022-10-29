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
int n,f[20],a[200005];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        int x;
        cin>>x;
        rep(j,0,20){
            if((x>>j)&1) f[j]++;
        }
    }
    for(int i=19;i>=0;i--){
        rep(j,0,f[i]){
            a[j]|=(1<<i);
        }
    }
    int ans=0;
    rep(i,0,n) ans+=a[i]*a[i];
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