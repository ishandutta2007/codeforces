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
int n,a[300005],g;
int f[20000007],ans=hell;
int vis[20000007];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        g=__gcd(g,a[i]);
        f[a[i]]++;
    }
    for(int i=2*g;i<=15000000;i+=g){
        if(vis[i]) continue;
        int cur=0;
        for(int j=i;j<=15000000;j+=i){
            cur+=f[j];
            vis[j]=1;
        }
        ans=min(ans,n-cur);
    }
    if(ans<n) cout<<ans<<endl;
    else cout<<-1<<endl;
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