/**
 *    author:  gary
 *    created: 12.02.2022 22:26:29
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
int n,a[101],mex[101][101],dp[101][101];
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    rb(i,1,n){
        map<int,int> vis;
        int now=0;
        rb(j,i,n){
            vis[a[j]]=1;
            while(vis[now]) now++;
            mex[i][j]=now;
        }
    }
    LL ans=0;
    rb(len,1,n){
        rb(l,1,n-len+1){
            int r=l+len-1;
            dp[l][r]=1+mex[l][r];
            rb(k,l+1,r){
                check_max(dp[l][r],dp[l][k-1]+dp[k][r]);
            }
            // cout<<l<<' '<<r<<" "<<dp[l][r]<<" "<<dp[1][1]<<" "<<<<endl;
            ans+=dp[l][r];
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}