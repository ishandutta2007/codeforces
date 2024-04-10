#include<bits/stdc++.h>
using namespace std;
#define N 300030
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
int n,a[N],b[N],lg[N];
ll dp[N],f[N][20],pre[N];
void Insert(int x){
	f[x][0]=dp[x];
	for(int j=1;j<=19&&x+(1<<j)-1<=n+1;++j){
		f[x][j]=max(f[x][j-1],f[x+(1<<j-1)][j-1]);
	}
}
inline ll Query(int l,int r){
	int k=lg[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int st[N],top;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	for(int i=2;i<=n+1;++i){
		lg[i]=lg[i>>1]+1;
	}
	dp[n+1]=0;
	Insert(n+1);
	st[0]=n+1;
	pre[0]=-1e18;
	for(int i=n;i>=1;--i){
		while(top&&a[i]<a[st[top]])--top;
		st[++top]=i;
		dp[i]=pre[top]=max(pre[top-1],Query(i+1,st[top-1])+b[i]);
		Insert(i);
	}
	printf("%lld\n",dp[1]);
	return 0;
}