#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 505

typedef long long ll;
const int Mod=(int)1e9+7;

//struct node{
//	int x,y,z;
//	bool operator <(const node &s) const{
//		if(x!=s.x) return x<s.x;
//		else if(y!=s.y) return y<s.y;
//		else return z<s.z;
//	}
//};
//map<node,ll> dp;

//ll dfs(int x1,int y1,int x2,int y2) {
//	if(pic[x1][y1]!=pic[x2][y2]) return 0;
//	if(x1>x2 || y1>y2) return 0;
//	if(x1==x2 && y1==y2) return 1;
//	if(x1==x2 && y1+1==y2) return 1;
//	if(y1==y2 && x1+1==x2) return 1;
//	node state=(node){x1,y1,x2};
//	if(dp[state]) return dp[state]-1;
//	ll res=0;
//	res+=dfs(x1+1,y1,x2-1,y2);
//	res+=dfs(x1+1,y1,x2,y2-1);
//	res+=dfs(x1,y1+1,x2-1,y2);
//	res+=dfs(x1,y1+1,x2,y2-1);
//	dp[state]=res+1;
//	return res;
//}

void Add(ll &x,ll y) {x=(x+y)%Mod;}

char pic[M][M];
ll dp[2][M][M];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%s",pic[i]+1);
	
	if(pic[1][1]!=pic[n][m]) {
		puts("0");
		return 0;
	}
	int cur=1;
	dp[1][1][n]=1;
	
	FOR(s,2,(n+m)>>1) {
		cur^=1;
		memset(dp[cur],0,sizeof(dp[cur]));
		FOR(x1,1,s)
			DOR(x2,n,n-s+1){
				int y1=s+1-x1;
				int y2=n+m+1-s-x2;
				if(x1>x2 || y1>y2) continue;
				if(pic[x1][y1]==pic[x2][y2]) {
					Add(dp[cur][x1][x2],dp[cur^1][x1][x2]);
					Add(dp[cur][x1][x2],dp[cur^1][x1][x2+1]);
					Add(dp[cur][x1][x2],dp[cur^1][x1-1][x2]);
					Add(dp[cur][x1][x2],dp[cur^1][x1-1][x2+1]);
				}
			}
	}
	ll res=0;
	if((n+m)&1) {
		FOR(i,1,n) {
			Add(res,dp[cur][i][i]);
			Add(res,dp[cur][i][i+1]);
		}
	} else {
		FOR(i,1,n) Add(res,dp[cur][i][i]);
	}
	printf("%lld\n",res);
	return 0;
}