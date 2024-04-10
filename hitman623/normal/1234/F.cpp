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
int f[1<<20],dp[1<<20],ans;
void solve(){
    cin>>s;
    rep(i,0,sz(s)){
        int cur=0;
        for(int j=i;j>=0;j--){
            int d=1<<(s[j]-'a');
            if(cur&d) break;
            cur|=d;
            f[cur]=1;
        }
    }
    f[0]=1;
    rep(i,0,1<<20){
        if(f[i]) dp[i]=__builtin_popcount(i);
    }
    rep(j,0,20){
        rep(i,0,1<<20){
            if(i&(1<<j)){
                dp[i]=max(dp[i],dp[i^(1<<j)]);
            }
        }
    }
    rep(i,0,1<<20){
        if(f[i]){
            ans=max(ans,__builtin_popcount(i)+dp[(1<<20)-1-i]);
        }
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