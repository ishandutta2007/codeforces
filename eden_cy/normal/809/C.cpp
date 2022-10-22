#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i<=_t;--i)
#define M 35

typedef long long ll;
const int Mod=(int)1e9+7;

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}
struct node{
	ll sum,cnt;
};
node dp[M][2][2][2];
int mark[M][2][2][2];
int A[M],B[M],C[M];
node dfs(int pos,int l1,int l2,int l3) {
	if(pos==-1) return (node){0,1};
	if(mark[pos][l1][l2][l3]) return dp[pos][l1][l2][l3];
	mark[pos][l1][l2][l3]=1;
	int limit=l3?C[pos]:1;
	node res=(node){0,0};
	FOR(i,0,l1?A[pos]:1) {
		FOR(j,0,l2?B[pos]:1) {
			int x=i^j;
			if(x>limit) continue;
			node tmp=dfs(pos-1,l1&&(i==A[pos]),l2&&(j==B[pos]),l3&&(x==limit));
			res.cnt=(res.cnt+tmp.cnt)%Mod;
			res.sum=(res.sum+tmp.sum)%Mod;
			res.sum=(res.sum+(1<<pos)*x%Mod*tmp.cnt%Mod)%Mod;
		}
	}
	return dp[pos][l1][l2][l3]=res;
}
ll solve(int n,int m,int k) {
	memset(mark,0,sizeof(mark));
	n--;m--;k--;
	FOR(i,0,30) {
		A[i]=(n>>i)&1;
		B[i]=(m>>i)&1;
		C[i]=(k>>i)&1;
	}
	node tmp=dfs(30,1,1,1);
	return (tmp.sum+tmp.cnt)%Mod;
}
int main() {
	int n,a,b,c,d,k;
	ll res;
	rd(n);
	FOR(i,1,n) {
		rd(a);rd(b);rd(c);rd(d);rd(k);
		res=solve(c,d,k);
		if(a>1) res-=solve(a-1,d,k);
		if(b>1) res-=solve(c,b-1,k);
		if(a>1&&b>1) res+=solve(a-1,b-1,k);
		res=(res%Mod+Mod)%Mod;
		printf("%lld\n",res);
	}
	return 0;
}