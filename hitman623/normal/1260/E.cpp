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
#define hell        100000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[1<<19],w=-1,p[20],dp[(1<<18)+1][20];
int go(int pos,int e){
    if(n-pos>p[e]) return hell;
    if(p[e]>=n-w) return 0;
    int &ans=dp[pos][e];
    if(ans!=-1) return ans;
    return ans=min(go(pos-1,e+1)+a[pos],go(pos-1,e));
}
void solve(){
    memset(dp,-1,sizeof dp);
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        if(a[i]==-1) w=i;
    }
    p[1]=n/2;
    rep(i,2,20) p[i]=p[i-1]/2;
    rep(i,2,20) p[i]+=p[i-1];
    cout<<go(n,0)<<endl;
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