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
string s;
int dp[20][5][2];
int sol(int in,int freq,int f){
    if(freq>3) return 0;
    if(in==sz(s)) return 1;
    if(dp[in][freq][f]!=-1) return dp[in][freq][f];
    int ans=0;
    rep(i,0,10){
        if(f || i==s[in]-'0'){
            ans=ans+sol(in+1,freq+!!i,f);   
        }
        else if(i<s[in]-'0'){
            ans=ans+sol(in+1,freq+!!i,1);   
        }
    }
    return dp[in][freq][f]=ans;
}
void solve(){
    string r;
    int l;
    cin>>l>>r;
    l--;
    s=r;
    memset(dp,-1,sizeof dp);
    int ans=sol(0,0,0);
    s=to_string(l);
    memset(dp,-1,sizeof dp);
    ans-=sol(0,0,0);
    cout<<ans<<endl;    
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