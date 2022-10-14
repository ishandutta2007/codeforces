/**
 *    author:  gary
 *    created: 04.07.2022 22:26:13
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int maxp[5000000+20];
bool vis[5000000+20];
int a[1000000+10];
int dp[5000000+20];
bool in[5000000+20];
void solve(){
    int n,m;
    cin>>n>>m;
    rb(i,1,m) in[i]=0;
    int mx=1;
    rb(i,1,n) cin>>a[i],check_max(mx,maxp[a[i]]),in[a[i]]=1;
    rb(i,1,m) dp[i]=-INF;
    rb(i,1,mx) dp[i]=i;
    rb(i,1,mx){
        for(int j=i;j<=m;j+=i){
            check_max(dp[j],min(i,dp[j/i]));
        }
    }
    multiset<int> se;
    rb(i,1,m) if(in[i]) se.insert(dp[i]);
    int ans=INF;
    for(int i=mx;i<=m;){
        check_min(ans,i-*se.begin());
        i++;
        for(int j=i;j<=m;j+=i){
            int old=dp[j];
            check_max(dp[j],min(i,dp[j/i]));
            if(j==i) dp[j]=i;
            if(in[j]&&dp[j]!=old) se.erase(se.find(old)),se.insert(dp[j]);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    rb(i,1,5e6) maxp[i]=1;
    rb(i,2,5e6){
        if(!vis[i]){
            for(int j=i;j<=5e6;j+=i){
                maxp[j]=i;
                vis[j]=1;
            }
        }
    }
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}