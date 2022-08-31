#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[500002],b[500002],t,ans,p[500002],fa[500002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
const int M=1000000007;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
int main(){         
	n=read(),m=read();
	for(re int i=1;i<=m;++i)fa[i]=i;
	for(re int i=1;i<=n;++i){
		re int x=read();
		if(x==1)a[i]=read();
		else a[i]=read(),b[i]=read();
		a[i]=root(a[i]),b[i]=root(b[i]);
		if(a[i]==b[i])continue;
		if(a[i]<b[i])swap(a[i],b[i]);
		if(b[i])fa[a[i]]=b[i];
		else fa[a[i]]=0;
		p[a[i]]=i;
	}
	for(re int i=1;i<=m;++i)if(p[i])++ans;
		printf("%d %d\n",ksm(2,ans),ans);
		sort(p+1,p+m+1);
	for(re int i=1;i<=m;++i)if(p[i])printf("%d ",p[i]);
}