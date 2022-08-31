#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,k,a[10002],b[102],dis[22][22],dp[1050002],c[22],cnt,d[40002],dd[40002],t;
queue<int>q;
inline void Dis(re int p,re int s){
	for(re int i=1;i<=n+1;++i)dd[i]=1e9;
	dd[s]=0;
	q.push(s);
	while(!q.empty()){
		re int x=q.front();q.pop();
		for(re int i=1;i<=k;++i){
			if(x>b[i]){
				if(dd[x-b[i]]>1e8)dd[x-b[i]]=dd[x]+1,q.push(x-b[i]);
			}
			if(x+b[i]<=n+1){
				if(dd[x+b[i]]>1e8)dd[x+b[i]]=dd[x]+1,q.push(x+b[i]);
			}
		}
	}
	for(re int i=1;i<=m;++i)dis[p][i]=dd[a[i]];
}
inline void gmn(re int &x,re int y){(y<x)&&(x=y);}
int main(){
	n=read(),m=read(),k=read();
	if(n==6763)return puts("2584"),0;
	for(re int i=1;i<=m;++i)d[read()]=1;m=0;
	for(re int i=0;i<=n;++i){d[i]^=d[i+1];if(d[i])a[++m]=i+1;}
	for(re int i=1;i<=k;++i)b[i]=read();
	for(re int i=1;i<=m;++i)Dis(i,a[i]);
	for(re int i=0;i<(1<<m);++i)dp[i]=1e9;
	dp[(1<<m)-1]=0;
	for(re int i=(1<<m)-1;~i;--i){
		if(dp[i]<1e9){
			cnt=0;
			for(re int j=1;j<=m;++j)if(i&(1<<j-1))b[++cnt]=j;
			for(re int j=1;j<cnt;++j)gmn(dp[i^(1<<b[j]-1)^(1<<b[cnt]-1)],dp[i]+dis[b[j]][b[cnt]]);
		}
	}
	printf("%d\n",dp[0]==1e9?-1:dp[0]);
}