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
int n,m,k;
string s;
int f[26];

bool check(){
    vi dp(k+1,0);
    dp[0]=1;
    rep(j,0,26){
        for(int w=k;w>=0;w--){
            if(dp[w]) dp[w+f[j]]=1;
        }
    }
    rep(i,0,k+1){
        if(dp[i] and i>=m and sz(s)-i>=n) return 1;
    }
    return 0;
}
void solve(){
    int ans=hell;
    cin>>n>>m>>k;
    cin>>s;
    memset(f,0,sizeof f);
    for(auto i:s){
        f[i-'A']++;
    }
    if(check()){
        cout<<0<<endl;
        return;
    }
    rep(i,0,26){
        vi dp(k+1,0);
        dp[0]=1;
        rep(j,0,26){
            if(i==j) continue;
            for(int w=k;w>=0;w--){
                if(dp[w]) dp[w+f[j]]=1;
            }
        }
        rep(j,0,k+1){
            if(dp[j]){
                int N=min(n,j),M=min(m,sz(s)-j-f[i]);
                if(N<0 or M<0) continue;
                if(N+M+f[i]>=n+m){
                    int x=n-N,y=m-M;
                    ans=min(ans,x*y);
                }
            }
        }
    }
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