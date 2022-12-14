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

int n,m;
vector<string> V;
int main(){
	int i;
	int h1,a1,c1;
	int h2,a2;
	scanf("%d%d%d",&h1,&a1,&c1);
	scanf("%d%d",&h2,&a2);
	while (h2>0){
		if (h1-a2<=0&&h2-a1>0){
			V.push_back("HEAL");
			h1+=c1;
		}else{
			V.push_back("STRIKE");
			h2-=a1;
		}
		h1-=a2;
//		printf("%d %d\n",h1,h2);
	}
	printf("%d\n",V.size());
	for (string s:V) cout<<s<<"\n";
}
/*
*/