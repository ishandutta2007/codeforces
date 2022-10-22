/**
 *    author:  gary
 *    created: 31.07.2022 21:48:13
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int MOD;
const int MAXN=5000+20;
namespace combination
{
    int fact[MAXN+1],ifact[MAXN+1];
    int quick(int k1,int k2){
		int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
	}
    int inv(int A){return quick(A,MOD-2);}
    void genmath(){
        fact[0]=1;
        rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
        ifact[MAXN]=inv(fact[MAXN]);
        rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
    }
    int comb(int A,int B){
        if(A<0||B<0) return 0;
        if(A<B) return 0;
        return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
    }
    void add(int &A,int B){
        A+=B;
        if(A>=MOD) A-=MOD;
    }
    void sub(int &A,int B){
        A+=MOD-B;
        if(A>=MOD) A-=MOD;
    }
}
using namespace combination;
int k;
int dp[MAXN][MAXN],pw[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k>>MOD;
    genmath();
    rb(i,2,k) dp[i][1]=1;
    rb(j,1,k){
        int sum=0;
        rb(i,1,k){
            if(i>=2) add(sum,dp[i-2][j]);
            add(dp[i][j+1],sum);
        }
    }
    rb(i,0,k) { pw[i][0]=1;rb(j,1,k) pw[i][j]=1ll*pw[i][j-1]*i%MOD;}
    rb(i,1,k) rb(j,1,k) dp[i][j]=1ll*dp[i][j]*ifact[j]%MOD*pw[k-1][j]%MOD*fact[i]%MOD;
    int ans=0;
    rb(h,0,k){
        rb(l,1,k){
            if(k-h-l>=0)
            add(ans,1ll*dp[k-h][l]*pw[k-h-l][h]%MOD*comb(k,h)%MOD);
        }
    }
    cout<<ans<<endl;
    return 0;
}