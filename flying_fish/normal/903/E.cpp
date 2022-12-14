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
//
int n,k,m;
char s[maxn];
int pos[maxn][4];
int now[6];
bool mark[maxn],MARK;
bool check(int x,int y){//change x|y
	int i,j;
	FOR(i,1,k){
		int size=0;
		REP(j,6) now[i]=-1;
		REP(j,4){
			int t=pos[i][j];
			if (t!=-1&&t!=x&&t!=y)
				if (s[i*n+t]!=s[t])
					now[size++]=t;
		}
		if (s[i*n+x]!=s[x]) now[size++]=x;
		if (s[i*n+y]!=s[y]) now[size++]=y;
//		printf("%d:",i);for (int t:now) printf("%d ",t);puts("");
		if (size==0&&MARK) continue;
		if (size!=2) return 0;
		if (s[i*n+now[0]]!=s[now[1]]||
			s[i*n+now[1]]!=s[now[0]]) return 0;
	}
	return 1;
}
int main(){
	int i,j;
	scanf("%d%d",&k,&n);
	scanf("%s",s);k--;
	REP(i,n){
		if (mark[s[i]]) MARK=1;
		mark[s[i]]=1;
	}
	FOR(i,1,k){
		scanf("%s",s+i*n);
		int k=0;
		pos[i][0]=pos[i][1]=pos[i][2]=pos[i][3]=-1;
		REP(j,n) if (s[j+i*n]!=s[j]){
			if (k==4) return 0*puts("-1");
			pos[i][k++]=(j);
		}
	}
	REP(i,n){
		rep(j,i+1,n){
			swap(s[i],s[j]);
//			printf("%s\n",s);
			if (check(i,j)){
				s[n]='\0';
				return 0*printf("%s",s);
			}swap(s[i],s[j]);
		}
	}
//	puts("NO");
	puts("-1");
}
/*
*/