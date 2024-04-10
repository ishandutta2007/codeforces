#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],A,B,b[1000002],fa[1000002],siz[1000002];
char s[1000002];
long long ans;
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Merge(re int x,re int y){
	x=root(x),y=root(y);
	if(x==y)return;
	fa[x]=y,siz[y]+=siz[x];
}
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read(),fa[i]=i,siz[i]=1;
		for(re int i=1;i<=n;++i)b[i]=read(),Merge(a[i],b[i]);
		re int num=0;
		for(re int i=1;i<=n;++i)if(root(i)==i&&siz[i]%2==1)++num;
		num=num+1>>1;
		num=(n+1>>1)-num;
		for(re int i=1;i<=num;++i)ans-=i;
		for(re int i=n;i>n-num;--i)ans+=i;
		printf("%lld\n",ans*2);
	}
}