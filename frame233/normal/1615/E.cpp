#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
std::vector<int> e[N];int len[N],son[N];
std::priority_queue<int> q;
void dfs1(int x,int fa){
	len[x]=1;
	for(auto v:e[x])if(v!=fa){
		dfs1(v,x);
		if(len[v]+1>len[x])len[x]=len[v]+1,son[x]=v;
	}
}
void dfs2(int x,int fa,int rest){
	if(son[x])dfs2(son[x],x,rest+1);else q.push(rest);
	for(auto v:e[x])if(v!=fa&&v!=son[x])dfs2(v,x,1);
}
int main(){
	int n,k;read(n,k);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	int cnt=0;for(int i=2;i<=n;++i)cnt+=SZ(e[i])==1;
	dfs1(1,0),dfs2(1,0,1);int c=0;ll ans=-1e18;
	while(SZ(q)<=n)q.push(0);
	for(int i=0;i<=k;++i){
		int lim=n-c,tmp=std::min(lim,n/2);
		ans=std::max(ans,1LL*(n-i-tmp)*(i-tmp));
		c+=q.top();q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}