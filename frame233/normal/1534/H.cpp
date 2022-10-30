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
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=100005;
typedef std::pair<int,int> pi;
std::vector<int> e[N];
int dp[N];
inline int ask(int r){
	printf("? %d\n",r),fflush(stdout);
	int x;read(x);return x;
}
void dfs1(int x,int fa){
	std::vector<int> all;
	for(auto v:e[x])if(v!=fa)dfs1(v,x),all.pb(dp[v]);
	std::sort(all.begin(),all.end(),std::greater<int>());
	dp[x]=fa?1:0;
	if(fa)for(int i=0;i<SZ(all);++i)chmax(dp[x],all[i]+i);
	else{
		for(int i=1;i<SZ(all);++i)chmax(dp[x],all[i]+i-1);
		dp[x]+=all[0];
	}
}
int g[N],DP[N],pre[N],suf[N];
void dfs2(int x,int fa){
	if(fa){
		std::vector<int> all={g[x]};
		for(auto v:e[x])if(v!=fa)all.pb(dp[v]);
		std::sort(all.begin(),all.end(),std::greater<int>());
		for(int i=1;i<SZ(all);++i)chmax(DP[x],all[i]+i-1);
		DP[x]+=all[0];
	}
	else DP[x]=dp[x];
	std::vector<int> all;
	for(auto v:e[x])all.pb(v==fa?g[x]:dp[v]);
	std::sort(all.begin(),all.end(),std::greater<int>());
	std::vector<int> pre(SZ(all)),suf(SZ(all));
	for(int i=0;i<SZ(all);++i){
		if(i)pre[i]=pre[i-1];
		chmax(pre[i],all[i]+i);
	}
	for(int i=SZ(all)-1;i>=0;--i){
		if(i+1<SZ(all))suf[i]=suf[i+1];
		chmax(suf[i],all[i]+i);
	}
	for(auto v:e[x])if(v!=fa){
		int id=std::lower_bound(all.begin(),all.end(),dp[v],std::greater<int>())-all.begin();
		g[v]=std::max(1,std::max(id?pre[id-1]:0,id+1<SZ(suf)?suf[id+1]-1:0));
		dfs2(v,x);
	}
}
int A,B,dep[N];
int dfs3(int x,int fa){
	dep[x]=dep[fa]+1;
	std::vector<pi> all;
	for(auto v:e[x])if(v!=fa)all.pb({dp[v],v});
	if(all.empty()){
		int tmp=ask(x);
		if(tmp==x)(A?B:A)=x;
		return tmp;
	}
	int cnt=fa?1:2;
	std::sort(all.begin(),all.end(),std::greater<pi>());
	for(auto [val,v]:all){
		int o=dfs3(v,x);
		if(dep[o]<dep[x])return o;
		if(dep[o]>dep[x]&&!--cnt)return o;
	}
	return (A?B:A)=x;
}
int main(){
	int n;read(n);
	if(n==1){
		printf("%d\n",0),fflush(stdout);
		printf("! %d %d\n",1,1),fflush(stdout);
		return 0;
	}
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs1(1,0),dfs2(1,0);
	printf("%d\n",*std::max_element(DP+1,DP+n+1)),fflush(stdout);
	int rt;read(rt);
	dfs1(rt,0),dfs3(rt,0);
	if(!B)B=A;
	printf("! %d %d\n",A,B),fflush(stdout);
	return 0;
}