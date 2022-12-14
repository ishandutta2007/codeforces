#include <sstream>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
#include <cassert>
#include <bitset>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)

#define DEBUG
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define deputs(str) fprintf(stderr, "%s\n",str)
#else
#define debug(...)
#define deputs(str)
#endif // DEBUG
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef long long LL;
typedef long long ll;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=998244353;
const LL maxn=1e6+7;
const double pi=acos(-1.0);
const double eps=0.00000001;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a, T b) {
    T ret=1;
    for (; b; b>>=1ll,a=(LL)a*a%M)
        if (b&1) ret=(LL)ret*a%M;
    return ret;
}


const LL MOD=998244353;
const LL g=3;
LL mul(LL x,LL y) {
    return x*y%MOD;
//    return ( x * y - ( long long ) ( x / ( long double ) MOD * y + 1e-3 ) * MOD + MOD ) % MOD ;
}
LL poww(LL a,LL b) {
    LL ret=1;
    for (; b; b>>=1ll,a=mul(a,a))
        if (b&1) ret=mul(ret,a);
    return ret;
}
void ntt(LL *A,int len,int inv) { //
    int i,j,k;
    for (i=1,j=len/2; i<len-1; i++) {
        if (i<j) swap(A[i],A[j]);
        k=len/2;
        while (j>=k) {
            j-=k;
            k/=2;
        }
        if (j<k) j+=k;
    }
    for (i=2; i<=len; i<<=1) {
        LL wn=poww(g,(MOD-1)/i);
        if (inv==-1) wn=poww(wn,MOD-2);
        for (j=0; j<len; j+=i) {
            LL w=1;
            for (k=j; k<(j+i/2); k++) {
                LL a=A[k],b=mul(w,A[k+i/2]);
                A[k]=(a+b)%MOD;
                A[k+i/2]=(a-b+MOD)%MOD;
                w=mul(w,wn);
            }
        }
    }
    if (inv==-1) {
        LL vn=poww(len,MOD-2);
        REP(i,len) A[i]=mul(A[i],vn);
    }
}
LL inv[1000002];//inverse
LL fac[1000002];//Factorial
LL C(int n,int m){
    return fac[n]*inv[m]%M*inv[n-m]%M;
}
LL x1[maxn],x2[maxn];
LL ans[maxn];
int TaskA(){
    int m,i,j,k;
    ll n,ans,ans_1,ans_2,seg;
    scanf("%I64d",&n);ans=0;
//    ans=powMM(3ll,n*n);
//    printf("ans=%I64d\n",ans);
//no row or no col
    FOR(i,1,n) x1[i]=C(n,i)*powMM(3ll,(n-i)*n)%M*powMM(3ll,(ll)i)%M;
//    FOR(i,1,n) printf("%I64d ",x1[i]);puts("");
    ans_1=0;
    seg=1;FOR(i,1,n) ans_1+=x1[i]*seg,seg*=-1;
    ans_1%=M;
    ans+=ans_1*2; ans%=M;
//    printf("ans1=%I64d\n",ans_1);
//have row
    ans_2=0;
    FOR(i,1,n){
        //sigma{C(n,i)*C(n,j)*pow(3,i*j)*pow(-1,i+j)}; i,j!=n
        ll p=powMM(3ll,n-i);
        x1[i]=C(n,i)*(powMM(1-p,n)-powMM(-p,n))%M;
    }
    ans_2=0;
    seg=1;FOR(i,1,n) ans_2+=x1[i]*seg,seg*=-1;
    ans_2%=M;
    if (n&1) ans-=ans_2*3;
    else ans+=ans_2*3;
    ans%=M; ans+=M;ans%=M;
//    printf("%I64d %I64d\n",ans_1,ans_2);
    printf("%I64d\n",ans);
    return 0;
}
void initialize(){
    int i;
    fac[0]=1;
    FOR(i,1,1000000) fac[i]=i*fac[i-1]%M;
    inv[0]=inv[1]=1;
    FOR(i,2,1000000) inv[i]=(M-M/i)*inv[M%i]%M;
    FOR(i,1,1000000) inv[i]=inv[i]*inv[i-1]%M;// inv(n!)
}
int main() {
	int startTime=clock();
	//initialize
	initialize();
	debug("/--- initializeTime: %ld milliseconds ---/\n",clock()-startTime);
	int T=1;
//	scanf("%d",&T);
	startTime=clock();
	while (T--) TaskA();
	debug("/--- computeTime: %ld milliseconds ---/\n",clock()-startTime);
}
/*
500
500
1000000000
*/