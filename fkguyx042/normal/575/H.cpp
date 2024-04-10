#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define CH (ch=getchar())
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,V)     for(__typeof(*V.begin()) i:  V)
#define For(i,a,b)   for(int i=(int)a;i<=(int)b;i++)
#define Rep(i,a,b)   for(int i=(int)a;i< (int)b;i++)
#define Forn(i,a,b)  for(int i=(int)a;i>=(int)b;i--)
#define pend(x)      ((x)=='\n'||(x)=='\r'||(x)=='\t'||(x)==' ')
using namespace std;
typedef	double		db;
typedef	long long	ll;
const	int	N=2000005;
const	int mo=1000000007;
const	int inf=(int)1e9;

inline int IN(){
	char ch;CH; int f=0,x=0;
	for(;pend(ch);CH); if(ch=='-')f=1,CH;
	for(;!pend(ch);CH) x=x*10+ch-'0';
	return (f)?(-x):(x);
}

int Pow(int x,int y,int p){
	int A=1;
	for(;y;y>>=1,x=(ll)x*x%p) if(y&1) A=(ll)A*x%p;
	return A;
}

int n,fac[N],fac_inv[N];

int main(){
	fac[0]=fac_inv[0]=fac_inv[1]=1;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	For(i,2,N-1) fac_inv[i]=1ll*fac_inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) fac_inv[i]=1ll*fac_inv[i]*fac_inv[i-1]%mo;
	
	int n=IN()+1;
	printf("%d\n",(1ll*fac[2*n]*fac_inv[n]%mo*fac_inv[n]%mo+mo-1)%mo);
}