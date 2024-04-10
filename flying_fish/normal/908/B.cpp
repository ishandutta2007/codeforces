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

char a[107][107],b[107];
int ans;
int i,n,m,len;
int addx[4]={0,0,1,-1};
int addy[4]={1,-1,0,0};
bool check(int f0,int f1,int f2,int f3){
	int i,j,x,y;
//	printf("%d %d %d %d\n",f0,f1,f2,f3);
	FOR(x,1,n){
		FOR(y,1,m)
			if (a[x][y]=='S') break;
		if (a[x][y]=='S') break;
	}
	REP(i,len){
		if (b[i]=='0'){
			x+=addx[f0];
			y+=addy[f0];
		}if (b[i]=='1'){
			x+=addx[f1];
			y+=addy[f1];
		}if (b[i]=='2'){
			x+=addx[f2];
			y+=addy[f2];
		}if (b[i]=='3'){
			x+=addx[f3];
			y+=addy[f3];
		}if (a[x][y]=='E') return 1;
		if (a[x][y]!='S'&&a[x][y]!='.') return 0;
	}return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%s",a[i]+1);
	scanf("%s",b);len=strlen(b);
	int i,j,k,l;
	REP(i,4)
		REP(j,4) if (j!=i)
			REP(k,4) if (k!=j&&k!=i)
				REP(l,4) if (l!=i&&l!=j&&l!=k)
					if (check(i,j,k,l)) ans++;
	printf("%d\n",ans);
}
/*
*/