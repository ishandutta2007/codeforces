#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=1000005;
std::vector<int> e[N];int f[N],g[N],d[N],d2[N],d3[N],Fa[N];
void dfs1(int x,int fa){
	Fa[x]=fa;if(fa)e[x].erase(std::find(e[x].begin(),e[x].end(),fa));
	for(auto v:e[x])if(v!=fa)dfs1(v,x),f[x]=std::max(f[x],f[v]+1);
}
void dfs2(int x,int fa){
	std::vector<int> pre(SZ(e[x])),suf(SZ(e[x]));
	for(int i=0;i<SZ(e[x]);++i)pre[i]=suf[i]=f[e[x][i]]+1;
	for(int i=1;i<SZ(e[x]);++i)pre[i]=std::max(pre[i],pre[i-1]);
	for(int i=SZ(e[x])-2;i>=0;--i)suf[i]=std::max(suf[i],suf[i+1]);
	for(int i=0;i<SZ(e[x]);++i){
		int v=e[x][i],mx=std::max({g[x],i?pre[i-1]:0,i+1<SZ(e[x])?suf[i+1]:0})+1;
		g[v]=mx,dfs2(v,x);
	}
}
int cnt[N],val1[N],val2[N],h[N];
std::vector<int> v1[N],v2[N];
int main(){
	int n;read(n);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	int ans1=0;for(int i=1;i<=n;++i)chmax(ans1,SZ(e[i])+1);
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;++i){
		std::vector<int> vec;if(i!=1)vec.pb(g[i]);
		for(auto v:e[i])vec.pb(f[v]+1);
		std::sort(vec.begin(),vec.end(),std::greater<int>());
		int cnt=0,mn=1e9;
		for(auto it:vec){
			++cnt,mn=std::min(mn,it+1);
			chmax(d[it],cnt),chmax(d2[mn],cnt);
			mn=std::min(mn,it);
		}
	}
	for(int i=2;i<=n;++i)v1[f[i]+1].pb(Fa[i]),v2[g[i]].pb(i);
	for(int i=n,mx=0;i>=1;--i){
		for(auto it:v1[i]){
			int j=it;++val1[j],++val2[j];mx=std::max(val2[j]+h[j]-1,mx);
			if(j!=1)mx=std::max(val1[j]+val2[Fa[j]]-1,mx),chmax(h[Fa[j]],val1[j]);
		}
		for(auto it:v2[i])++val2[it],mx=std::max(val2[it]+h[it]-1,mx);
		d3[i]=mx;
	}
	for(int i=n;i>=1;--i)chmax(d[i],d[i+1]);
	for(int i=n;i>=1;--i)chmax(d2[i],d2[i+1]);
	for(int i=1;i<=n;++i){
		printf("%d%c",std::max(1,i==1?ans1:i%2?d2[i/2+1]:std::max(d[i/2],d3[i/2]))," \n"[i==n]);
	}
	return 0;
}