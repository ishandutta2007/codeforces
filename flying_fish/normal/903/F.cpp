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
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
typedef unsigned long long ULL;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+7;
const double eps=0.00000001;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a,T b){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

int n,a1,a2,a3,a4;
int i,j,k;
int a[maxn];
int f[maxn],g[maxn];
int main(){
//	printf("%d",(1<<0)+(1<<1)+(1<<2)+
//				(1<<4)+(1<<5)+(1<<6)+
//				(1<<8)+(1<<9)+(1<<10));
	scanf("%d%d%d%d%d",&n,&a1,&a2,&a3,&a4);
	REP(k,4)REP(i,n){
		char c;
		do c=getchar(); while (c!='.'&&c!='*');
		a[i]=a[i]*2+(c=='*');
	}
//	REP(i,n) printf("%d ",a[i]);puts("");
	REP(i,n){
		REP(j,(1<<16)) g[j]=f[j],f[j]=INF;
		REP(j,(1<<12)) f[j<<4|a[i]]=g[j];
		rREP(j,(1<<16)){
			f[j&(~65535)]=min(f[j&(~65535)],f[j]+a4);
			f[j&(~1911)] =min(f[j&(~1911)] ,f[j]+a3);
			f[j&(~3822)] =min(f[j&(~3822)] ,f[j]+a3);
			f[j&(~51)]   =min(f[j&(~51)]   ,f[j]+a2);
			f[j&(~102)]  =min(f[j&(~102)]  ,f[j]+a2);
			f[j&(~204)]  =min(f[j&(~204)]  ,f[j]+a2);
			f[j&(~1)]    =min(f[j&(~1)]    ,f[j]+a1);
			f[j&(~2)]    =min(f[j&(~2)]    ,f[j]+a1);
			f[j&(~4)]    =min(f[j&(~4)]    ,f[j]+a1);
			f[j&(~8)]    =min(f[j&(~8)]    ,f[j]+a1);
		}
	}printf("%d\n",f[0]);
}
/*
*/