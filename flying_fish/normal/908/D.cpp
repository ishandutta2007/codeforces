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

int k,i,j;
LL pa,pb;
LL fa,fb;
LL f[1007][1007];//(ab)num,a_num
LL ans;
int main(){
	scanf("%d%d%d",&k,&pa,&pb);
	fa=pa*powMM(pa+pb,M-2)%M;
	fb=pb*powMM(pa+pb,M-2)%M;
	LL P=pa*powMM(pb,M-2)%M;
	f[0][1]=1;
	FOR(i,0,k-1){
		FOR(j,1,k-1){
			(f[i][j+1]+=fa*f[i][j])%=M;
			if (i+j<k) (f[i+j][j]+=fb*f[i][j])%=M;
			else (ans+=(i+j)*fb%M*f[i][j])%=M;
		}(ans+=f[i][k]*(i+k+P))%=M;
	}// 
	printf("%I64d\n",ans);
}
/*
*/