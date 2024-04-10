/**
 *    author:  gary
 *    created: 06.09.2022 22:26:30
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
namespace combination
{
    const int MOD=998244353;
    const int MAXN=1e6;
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
} // namespace combination
using namespace combination;
int f[MAXN];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    genmath();
    while (t--){
        int n;
        cin>>n;
        int ans=0;
        f[0]=1;
        rb(i,1,n){
            f[i]=f[i-1];
            if(i>1)
            add(f[i],1ll*(i-1)*f[i-2]%MOD);
        }
        rb(i,0,n/4){
            int cntpair=i*2;
            int bow=cntpair+1;
            int coef=comb(n-2*cntpair+bow-1,bow-1);
            coef=1ll*coef*comb(cntpair,cntpair/2)%MOD;
            coef=1ll*coef*fact[cntpair/2]%MOD;
            // coef=1ll*coef*quick((MOD+1)/2,cntpair/2)%MOD;
            coef=1ll*coef*f[n-i*4]%MOD;
            add(ans,coef);
        }
        cout<<ans<<endl;
    }
    return 0;
}