#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 5005
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
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
int n,x[N],m,p[N],c[N],q[N],l,r,t[N];
ll s[N],dp[N][N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		x[i]=read();
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=m;++i){
		p[i]=read(),c[i]=read();
		t[i]=i;
	}
	sort(t+1,t+m+1,[&](int i,int j){return p[i]<p[j];});
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int j=1;j<=m;++j){
		r=0,l=1;
		for(int i=1;i<=n;++i){
			s[i]=s[i-1]+abs(x[i]-p[t[j]]);
		}
		for(int i=0;i<=n;++i){
			while(l<=r&&q[l]<i-c[t[j]])++l;
			while(l<=r&&dp[i][j-1]-s[i]<=dp[q[r]][j-1]-s[q[r]])--r;
			q[++r]=i;
			dp[i][j]=dp[q[l]][j-1]+s[i]-s[q[l]];
		}
	}
	if(dp[n][m]==inf){
		printf("-1\n");return 0;
	}
	printf("%lld\n",dp[n][m]);
	return 0;
}