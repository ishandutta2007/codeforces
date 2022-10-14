/**
 *    author:  gary
 *    created: 16.01.2022 22:34:03
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
namespace combination
{
    const int MOD=998244353;
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
const int N=1e7+1;
const int B=12252240;
int a[N],x,y,k,M,n,dp[32][18],b[B],pw[20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    genmath();
    cin>>n>>a[0]>>x>>y>>k>>M;
    pw[0]=1;
    rb(i,1,k) pw[i]=1ll*pw[i-1]*n%MOD;
    rb(i,1,n-1) a[i]=(1ll*a[i-1]*x+y)%M;
    int answer=0;
    int coef=1ll*quick(n,k-1)*k%MOD;
    rb(i,1,n){
        b[a[i-1]%B]++;
        int d=a[i-1]-a[i-1]%B;
        add(answer,1ll*d*coef%MOD);
    }
    rl(i,B-1,1){
        memset(dp[(i+1)&31],0,sizeof(dp[(i+1)&31]));
        add(dp[i&31][1],b[i]);
        int tmp=0;
        rb(j,1,k-1){
            add(dp[i&31][j+1],1ll*dp[i&31][j]*(n-1)%MOD);
            add(dp[(i-i%j)&31][j+1],dp[i&31][j]);
            add(tmp,1ll*dp[i&31][j]*pw[k-j]%MOD);
        }
        add(tmp,dp[i&31][k]);
        add(answer,1ll*tmp*i%MOD);
    }
    cout<<answer<<endl;
    return 0;
}