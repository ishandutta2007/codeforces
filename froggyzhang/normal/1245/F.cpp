#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,a[32],b[32];
ll dp[2][2][32];
ll dfs(int u,bool A,bool B){
	if(u<0)return 1;
	if(~dp[A][B][u])return dp[A][B][u];
	int limA=A?a[u]:1;
	int limB=B?b[u]:1;
	ll tot=0;
	for(int i=0;i<=limA;++i){
		for(int j=0;j<=limB;++j){
			if(i&j)continue;
			tot+=dfs(u-1,A&(i==limA),B&(j==limB));
		}
	}
	dp[A][B][u]=tot;
	return tot;
}
ll Solve(ll x,ll y){
	if(x<0||y<0)return 0;
	for(int i=30;i>=0;--i){
		a[i]=(x>>i&1);
		b[i]=(y>>i&1);
	}
	memset(dp,255,sizeof(dp));
	return dfs(30,true,true);
}
int main(){
	T=read();
	while(T--){
		int l=read(),r=read();
		printf("%lld\n",Solve(r,r)-2*Solve(r,l-1)+Solve(l-1,l-1));
	}
	return 0;
}