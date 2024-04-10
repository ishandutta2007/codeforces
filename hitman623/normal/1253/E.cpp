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
int n,m,a[100005],dp[88][100005];
vii v;
int go(int pos,int last){
    if(last>m) return 0;
    if(pos==sz(v)) return max(0,m-last+1);
    int &ans=dp[pos][last];
    if(ans!=-1) return ans;
    ans=go(pos+1,last);
    if(v[pos].x-v[pos].y>last) ans=min(ans,go(pos+1,v[pos].x+v[pos].x-last+1)+v[pos].x-v[pos].y-last);
    else ans=min(ans,go(pos+1,v[pos].x+v[pos].y+1));
    return ans;
}
void solve(){
    memset(a,-1,sizeof a);
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    rep(i,0,n){
        int x,s;
        cin>>x>>s;
        a[x]=max(a[x],s);
    }
    rep(i,1,m+1){
        if(a[i]!=-1){
            v.pb({i,a[i]});
        }
    }
    cout<<go(0,1)<<endl;
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