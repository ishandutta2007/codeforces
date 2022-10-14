/**
 *    author:  gary
 *    created: 22.01.2022 22:10:22
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
const int MAXN=2e3+1;
int n,m,k;
namespace combination
{
    const int MOD=1e9+7;
    const int MAXN=200000;
    int fact[MAXN+1],ifact[MAXN+1];
    int quick(int k1,int k2){
		int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
	}
    int inv(int A){return quick(A,MOD-2);}
    void genmath(){
        fact[0]=1;
        rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
        ifact[MAXN]=inv(fact[MAXN]);
        // cout<<fact[MAXN]<<endl;
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
} // namespace combination
using namespace combination;
int dp[2002][2002];
void solve(){
    cin>>n>>m>>k;
    rb(i,0,n){
        rb(j,0,m){
            dp[i][j]=0;
        }
    }
    rb(i,0,n){
        rb(j,0,n){
            if(i==0){
                dp[i][j]=0;
                continue;
            }
            if(j==0){
                dp[i][j]=0;
                continue;
            }
            if(i==j){
                dp[i][j]=1ll*k*i%MOD;
                continue;
            }
            int kk=(dp[i-1][j]-dp[i-1][j-1]+MOD)%MOD;
            kk=(1ll*kk*(MOD+1)/2)%MOD;
            dp[i][j]=dp[i-1][j]-kk+MOD;
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[n][m]<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}