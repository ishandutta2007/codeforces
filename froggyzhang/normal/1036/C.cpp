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
int T,a[22],len;
ll l,r,dp[22][4];
ll dfs(int u,int t,bool up){
	if(t>3)return 0;
	if(u<1)return 1;
	if(dp[u][t]>=0&&!up)return dp[u][t];
	int lim=up?a[u]:9;
	ll tot=0;
	for(int i=0;i<=lim;++i){
		tot+=dfs(u-1,t+(i>0),up&&i==lim);
	}
	if(!up)dp[u][t]=tot;
	return tot;
}
ll Solve(ll n){
	len=0;
	if(!n)a[len=1]=0;
	while(n)a[++len]=n%10,n/=10;
	memset(dp,~0x3f,sizeof(dp));
	return dfs(len,0,true);
}
int main(){
	T=read();
	while(T--){
		ll l=read(),r=read();
		printf("%lld\n",Solve(r)-Solve(l-1));
	}
	return 0;
}