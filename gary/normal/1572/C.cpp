/**
 *    author:  gary
 *    created: 18.09.2021 22:13:27
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
const int MAXN=3e3+1;
int a[MAXN];
int dp[MAXN][MAXN];
int pre[MAXN];
int fuck[MAXN];
int n;
void solve(){
    scanf("%d",&n);
    rb(i,1,n) fuck[i]=-1;
    rb(i,1,n){
        scanf("%d",&a[i]);
        pre[i]=fuck[a[i]];
        fuck[a[i]]=i;
    }
    rb(i,1,n) dp[i][i]=dp[i][i-1]=dp[i+1][i]=0;
    rb(len,2,n){
        rb(l,1,n-len+1){
            int r=l+len-1;
            dp[l][r]=dp[l][r-1];
            for(int j=pre[r];j>=l;j=pre[j]){
                check_max(dp[l][r],dp[l][j-1]+dp[j+1][r]+1);
            }
        }
    }
    printf("%d\n",n-1-dp[1][n]);
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}