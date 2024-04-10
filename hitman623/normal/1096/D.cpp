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
#define hell        1e17
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[100005];
string s;
int dp[100005][16];
int sol(int pos,int mask){
    if(mask==15) return hell;
    if(pos==n) return 0;
    int &ans=dp[pos][mask];
    if(ans!=-1) return ans;
    ans=a[pos]+sol(pos+1,mask);
    if(s[pos]=='h') ans=min(ans,sol(pos+1,mask|1));
    else if(s[pos]=='a') ans=min(ans,sol(pos+1,(mask&1)?(mask|2):mask));
    else if(s[pos]=='r') ans=min(ans,sol(pos+1,(mask&2)?(mask|4):mask));
    else if(s[pos]=='d') ans=min(ans,sol(pos+1,(mask&4)?(mask|8):mask));
    else ans=min(ans,sol(pos+1,mask));
    return ans;
}
void solve(){
    memset(dp,-1,sizeof dp);
    cin>>n>>s;
    rep(i,0,n) cin>>a[i];
    cout<<sol(0,0)<<endl;
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