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
string s;
int n,p[3]={0,-1,-1},dp[200005],a[200005];
void solve(){
    cin>>s;
    n=sz(s);
    rep(i,0,n){
        a[i]=s[i]-'0';
        a[i]%=3;
        if(i) a[i]=(a[i-1]+a[i])%3;
    }
    rep(i,0,n){
        dp[i]=dp[i-1];
        if(p[a[i]]!=-1){
            dp[i]=max(dp[i],dp[p[a[i]]]+1);
        }
        p[a[i]]=i;
    }
    cout<<dp[n-1]<<endl;
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