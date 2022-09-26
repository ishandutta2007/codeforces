#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define N 35
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
int Q,a[N],b[N],c[N],ans;
int dp[N][2][2][2],t[N][2][2][2];
pair<int,int> dfs(int u,int x,int y,int z){
	if(u<0)return make_pair(1,0);
	int &tp=dp[u][x][y][z];
	int &s=t[u][x][y][z];
	if(~tp){
		ans=(ans+s)%mod;
		return make_pair(tp,s);
	}
	tp=0;
	int pa=(x?a[u]:1);
	int pb=(y?b[u]:1);
	int pc=(z?c[u]:1);
	for(int i=0;i<=pa;++i){
		for(int j=0;j<=pb;++j){
			for(int k=0;k<=pc;++k){
				if((i^j)==k){
					auto [d1,d2]=dfs(u-1,x&(i==pa),y&(j==pb),z&(k==pc));
					s=(s+d2)%mod;
					if(k)s=(s+1LL*(1<<u)*d1)%mod;
					tp=(tp+d1)%mod;
				}
			}
		}
	}	
	ans=(ans+s)%mod;
	return make_pair(tp,s);
}
int Solve(int x,int y,int k){
	if(!x||!y)return 0;
	--x,--y,--k;
	memset(dp,-1,sizeof(dp));
	memset(t,0,sizeof(t));
	ans=0;
	for(int i=0;i<=30;++i){
		a[i]=(x>>i&1);
		b[i]=(y>>i&1);
		c[i]=(k>>i&1);
	}
	auto [A,B]=dfs(30,1,1,1);
	return (A+B)%mod;
}
int main(){
	Q=read();
	while(Q--){
		int l1=read(),l2=read(),r1=read(),r2=read(),k=read();
		int ans=Solve(r1,r2,k)-Solve(l1-1,r2,k)-Solve(r1,l2-1,k)+Solve(l1-1,l2-1,k);
		ans=(ans%mod+mod)%mod;
		printf("%d\n",ans);
	}
	return 0;
}