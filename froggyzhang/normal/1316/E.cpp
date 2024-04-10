#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,m,K;
ll dp[2][1<<7];
struct Peo{
	array<int,7> c;
	int t;
	friend bool operator < (const Peo &a,const Peo &b){
		return a.t>b.t;	
	}
}a[N];
int main(){
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i){
		a[i].t=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			a[i].c.at(j)=read();
		}
	}
	sort(a+1,a+n+1);
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		memset(dp[i&1],~0x3f,sizeof(dp[i&1]));
		for(int j=0;j<(1<<m);++j){
			if(i<=__builtin_popcount(j)+K){
				dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j]+a[i].t);
			}
			else{
				dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j]);
			}
			for(int k=0;k<m;++k){
				if(j>>k&1){
					dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j^(1<<k)]+a[i].c.at(k));
				}
			}
		}	
	}
	printf("%lld\n",dp[n&1][(1<<m)-1]);
	return 0;
}