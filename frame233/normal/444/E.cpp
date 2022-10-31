#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=3005;typedef long long ll;
struct edge{int u,v,w;inline bool operator < (const edge &o)const{return w<o.w;}}e[N];
int fa[N],siz[N];ll s[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n;read(n);if(n==1)return puts("0"),0;
	for(int i=1;i<n;++i)read(e[i].u,e[i].v,e[i].w);
	std::sort(e+1,e+n);ll sum=0;
	for(int i=1;i<=n;++i)fa[i]=i,siz[i]=1,read(s[i]),sum+=s[i];
	for(int i=1;i<n;++i){
		int u=find(e[i].u),v=find(e[i].v);
		fa[u]=v,siz[v]+=siz[u],s[v]+=s[u];
		if(siz[v]>sum-s[v])return printf("%d\n",e[i].w),0;
	}
	return 0;
}