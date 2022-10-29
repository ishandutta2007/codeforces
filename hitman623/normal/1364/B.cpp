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
int n,p[100005],vis[100005];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>p[i];
        vis[i]=1;
    }    
    rep(i,2,n){
        if(p[i-1]<p[i] and p[i]<p[i+1]) vis[i]=0;
        if(p[i-1]>p[i] and p[i]>p[i+1]) vis[i]=0;
    }
    vi res;
    rep(i,1,n+1) if(vis[i]) res.pb(p[i]);
    cout<<sz(res)<<endl;
    for(auto i:res) cout<<i<<" ";
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