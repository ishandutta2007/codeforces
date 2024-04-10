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

int n,m,r,k;
struct node{
	int x,y;double get;
	node(int _x,int _y):x(_x),y(_y){
		if (min(x,n-r+1)-max(x-r,0)<0) get=0;
		else if (min(y,m-r+1)-max(y-r,0)<0) get=0;
		else get=1.0*(min(x,n-r+1)-max(x-r,0))*(min(y,m-r+1)-max(y-r,0));
	}
	bool operator<(const node &A)const{
		if (get!=A.get) return get<A.get;
		if (x!=A.x) return x<A.x;
		return y<A.y;
	}
};
set<node> S;
priority_queue<node> Q;
void ins(int i,int j){
	if (i<1||i>n) return;
	if (j<1||j>m) return;
//	printf("%d %d %lf\n",i,j,node(i,j).get);
	if (S.count(node(i,j))) return;
	S.insert(node(i,j));
	Q.push(node(i,j));
}
double ans;
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&k);
	int i,j;
	int mini=min(r,n-r+1),maxi=max(r,n-r+1);
	int minj=min(r,m-r+1),maxj=max(r,m-r+1);
	ins(r,r);
//	FOR(i,mini,maxi)
//		FOR(j,minj,maxj){
//			if (k) ans+=node(i,j).get,k--;
//			else return 0*printf("%lf\n",ans/((n-r+1)*(m-r+1)));
//			S.insert(node(i,j));
//			printf("i,j:%d %d,%lf\n",i,j,node(i,j).get);
//		}
//	printf("%lf  %lf\n",ans,1.0*(n-r+1)*(m-r+1));
//	FOR(i,mini,maxi) ins(i,minj-1),ins(i,maxj+1);
//	FOR(i,minj,maxj) ins(mini-1,i),ins(maxi+1,i);
	while (k--&&Q.size()){
		node x=Q.top();Q.pop();
		ans+=x.get;
//		printf("X : %d %d %lf\n",x.x,x.y,x.get);
		ins(x.x+1,x.y);
		ins(x.x-1,x.y);
		ins(x.x,x.y-1);
		ins(x.x,x.y+1);
	}
//	printf("%lf  %lf\n",ans,1.0*(n-r+1)*(m-r+1));
	printf("%.10lf\n",ans/(1ll*(n-r+1)*(m-r+1)));
}
/*
*/