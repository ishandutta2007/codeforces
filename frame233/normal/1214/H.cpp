#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int n,k;std::vector<int> e[N];int mx,rt,f[N],Fa[N],g[N],col[N];bool mark[N];
void dfs0(int x,int fa,int d){
	if(++d>mx)mx=d,rt=x;
	for(auto v:e[x])if(v!=fa)dfs0(v,x,d);
}
void dfs1(int x,int fa){Fa[x]=fa;for(auto v:e[x])if(v!=fa)dfs1(v,x),f[x]=std::max(f[x],f[v]+1);}
void dfs2(int x,int fa){
	std::vector<int> pre(SZ(e[x])),suf(SZ(e[x]));
	for(int i=0;i<SZ(e[x]);++i)pre[i]=suf[i]=e[x][i]==fa?g[x]:f[e[x][i]]+1;
	for(int i=1;i<SZ(e[x]);++i)pre[i]=std::max(pre[i],pre[i-1]);
	for(int i=SZ(e[x])-2;i>=0;--i)suf[i]=std::max(suf[i],suf[i+1]);
	for(int i=0;i<SZ(e[x]);++i)if(e[x][i]!=fa){
		int v=e[x][i],mx=std::max(i?pre[i-1]:0,i+1<SZ(e[x])?suf[i+1]:0);
		g[v]=mx+1,dfs2(v,x);
	}
}
void dfs3(int x,int fa,int coef){for(auto v:e[x])if(v!=fa&&!mark[v])col[v]=(col[x]+coef)%k,dfs3(v,x,coef);}
int main(){
	read(n,k);for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	if(k==2){
		puts("Yes"),col[1]=0,dfs3(1,0,1);
		for(int i=1;i<=n;++i)printf("%d%c",col[i]+1," \n"[i==n]);
		return 0;
	}
	dfs0(1,0,0);int a=rt;mx=0,dfs0(a,0,0);int b=rt;
	dfs1(a,0),dfs2(a,0);
	for(int i=1;i<=n;++i){
		std::vector<int> all;
		for(auto v:e[i])all.pb(v==Fa[i]?g[i]:f[v]+1);
		std::sort(all.begin(),all.end(),std::greater<int>());
		if(SZ(all)>=3&&all[1]+all[2]+1>=k)return puts("No"),0;
	}
	std::vector<int> vec;for(int i=b,c=0;i;i=Fa[i])vec.pb(i),mark[i]=1,col[i]=c++,c%=k;
	for(int i=0;i<SZ(vec)/2;++i)dfs3(vec[i],0,k-1);
	for(int i=SZ(vec)/2;i<SZ(vec);++i)dfs3(vec[i],0,1);
	puts("Yes");for(int i=1;i<=n;++i)printf("%d%c",col[i]+1," \n"[i==n]);
	return 0;
}