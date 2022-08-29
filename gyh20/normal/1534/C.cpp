#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],fa[400002],vis[400002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
char s[52][52];
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),vis[i]=0,fa[i]=i;
		for(re int i=1;i<=n;++i)b[i]=read();
		for(re int i=1;i<=n;++i)fa[root(a[i])]=root(b[i]);
		ans=0;
		for(re int i=1;i<=n;++i)if(!vis[root(i)])vis[root(i)]=1,++ans;
		printf("%lld\n",ksm(2,ans));
	}
}