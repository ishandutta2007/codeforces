#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
int a[N];std::vector<int> e[N];
struct node{int val,id;inline bool operator < (const node &o)const{return val<o.val;}};
ll dp[N][2];int V,M,dfn[N],siz[N],id;node mx[N<<2];
void DFS(int x,int fa){
	dfn[x]=++id,siz[x]=1;
	for(auto v:e[x])if(v!=fa)DFS(v,x),siz[x]+=siz[v];
}
void build(int n){for(M=1;M<=n+2;M<<=1);}
void upd(int x,int v){mx[x+M]={v,x};for(x+=M,x>>=1;x;x>>=1)mx[x]=std::max(mx[x<<1],mx[x<<1|1]);}
node ask(int s,int t){
	node ans={0,0};
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)ans=std::max(ans,mx[s^1]);
		if(t&1)ans=std::max(ans,mx[t^1]);
	}
	return ans;
}
void dfs(int x,int fa){
	bool leaf=1;for(auto v:e[x])if(v!=fa)leaf=0,dfs(v,x);
	if(leaf)dp[x][0]=a[x],dp[x][1]=V,upd(dfn[x],a[x]);
	else{
		dp[x][1]=2e18;for(auto v:e[x])if(v!=fa)dp[x][1]=std::min(dp[x][1]+dp[v][0],dp[x][0]+dp[v][1]),dp[x][0]+=dp[v][0];
		node tmp=ask(dfn[x],dfn[x]+siz[x]-1);if(a[x]>tmp.val)upd(tmp.id,a[x]),dp[x][0]+=a[x]-tmp.val;
	}
}
ll f[3];
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	int rt=std::max_element(a+1,a+n+1)-a;V=a[rt];
	DFS(rt,0),build(n),dfs(rt,0);
	f[0]=0,f[1]=2e18,f[2]=2e18;
	for(auto v:e[rt])f[2]=std::min(f[2]+dp[v][0],f[1]+dp[v][1]),f[1]=std::min(f[1]+dp[v][0],f[0]+dp[v][1]),f[0]+=dp[v][0];
	printf("%lld\n",std::min(f[2],f[1]+V));
	return 0;
}