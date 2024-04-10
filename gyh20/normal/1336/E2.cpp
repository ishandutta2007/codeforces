#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int popcnt(re int x){return __builtin_popcountll(x);}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int Mod(re int x){return x>=M?x-M:x;}
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
int n,m,p[62],ans[62],a[62],num[62],k,C[62][62],oo;
inline void dfs(re int x,re int y){
	if(x==k+1){++num[popcnt(y)];return;}
	dfs(x+1,y),dfs(x+1,y^a[x]);
}
signed main(){
	n=read(),m=read();
	for(re int i=C[0][0]=1;i<=m;++i)
		for(re int j=C[i][0]=1;j<=i;++j)
			C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]);
	for(re int i=1;i<=n;++i){
		re int x=read();
		for(re int j=60;~j;--j)
			if((x>>j)&1){
				if(!p[j]){p[j]=x;++oo;break;}
				x^=p[j];
			}
	}
	for(re int i=60;~i;--i){
		for(re int j=i-1;~j;--j)
			if((p[i]>>j)&1)
				 p[i]^=p[j];
	}
	if(oo<=27){
		for(re int i=60;~i;--i)if(p[i])a[++k]=p[i];
		dfs(1,0);
		for(re int i=0;i<=m;++i){
			re int s=num[i];
			for(re int j=1;j<=n-k;++j)add(s,s);
			printf("%lld ",s);
		}
	}
	else{
		for(re int i=m-1;~i;--i)
			if(!p[i]){
				++k,a[k]=1ll<<i;
				for(re int j=0;j<m;++j)if(p[j]&(1ll<<i))a[k]^=1ll<<j;
			}
		dfs(1,0);
		for(re int i=0;i<=m;++i){
			re int s=0;
			for(re int j=0;j<=m;++j) {
				re int w=0;
				for(re int k=0;k<=i;k+=2)add(w,1ll*C[j][k]*C[m-j][i-k]%M);
				for(re int k=1;k<=i;k+=2)add(w,M-1ll*C[j][k]*C[m-j][i-k]%M);
				add(s,1ll*w*num[j]%M);
			}
			for(re int j=0;j<k;++j)s=1ll*s*(M+1>>1)%M;
			for(re int j=0;j<n-m+k;++j)add(s,s);
			printf("%lld ",s);
		}
		
	}
}