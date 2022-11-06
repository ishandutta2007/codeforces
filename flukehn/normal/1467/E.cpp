#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##_end=b;i<i##_end;++i)
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int mo=1e9+7;
int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
//template<typename T>
void inc(int &x,int y){x=(x+y>=mo?x+y-mo:x+y);}
int ad(int x,int y){return x+y>=mo?x+y-mo:x+y;}
template<typename T>T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
mt19937 rnd(time(0));
 
const int N=2e5+11;
int n,a[N],b[N],c[N];
vector<int> e[N];
int ju[N],sz[N],rt;
int vis[N],g[N],S;
void dfs_rt(int x,int fa){
	sz[x]=1;
	g[x]=0;
	for(int y:e[x])if(!vis[y]&&y!=fa){
		dfs_rt(y,x);
		sz[x]+=sz[y];
		g[x]=max(g[x],sz[y]);
	}
	g[x]=max(g[x],S-sz[x]);
	if(g[x]<g[rt])rt=x;
}
int tmp;
void dfs(int x,int fa){
	if(c[a[x]])tmp=1;
	++c[a[x]];
	for(int y:e[x])if(!vis[y]&&y!=fa){
		dfs(y,x);
	}
	--c[a[x]];
}
void dfs_0(int x,int fa){
	ju[x]=0;
	for(int y:e[x])if(!vis[y]&&y!=fa){
		dfs_0(y,x);
	}
}
void dfs_v(int x,int fa,int v){
	c[a[x]]+=v;
	for(int y:e[x])if(!vis[y]&&y!=fa){
		dfs_v(y,x,v);
	}
}
void dfs_c(int x,int fa){
	if(c[a[x]]) return dfs_0(x,fa);
	++c[a[x]];
	for(int y:e[x])if(!vis[y]&&y!=fa)dfs_c(y,x);
	--c[a[x]];
}
void solve(int x){
	S=sz[x],g[rt=0]=N;
	dfs_rt(x,0);
	//cerr<<x<<" solve "<<rt<<endl;
	x=rt;
	//dfs(x,0);
	//if(c[a[x]]>1)ju[x]=0;
	vis[x]=1;
	int flag=0;
	c[a[x]]=1;
	for(int y:e[x])if(!vis[y]){
		tmp=0;
		dfs(y,x);
		if(tmp){
			if(flag){flag=-1;break;}
			else{flag=y;}
		}
	}
	c[a[x]]=0;
	//For(i,0,n+1)cerr<<c[i]<<" \n"[i==n];
	if(flag<0){
		dfs_0(x,0);
		return;
	}
	dfs_v(x,0,1);
	if(c[a[x]]>1)ju[x]=0;
	if(flag){
		ju[x]=0;
		//cerr<<x<<" flag "<<flag<<endl;
		for(int y:e[x])if(!vis[y]&&y!=flag){
			dfs_0(y,x);
		}
		dfs_v(flag,x,-1);
		dfs_c(flag,x);
		dfs_v(flag,x,1);
	}else{
		for(int y:e[x])if(!vis[y]){
			dfs_v(y,x,-1);
			dfs_c(y,x);
			dfs_v(y,x,1);
		}
	}
	dfs_v(x,0,-1);
	//cerr<<"after "<<x<<endl;
	//For(i,0,n+1)cerr<<c[i]<<" \n"[i==n];
	//for(int y:e[x])if(!vis[y]
	for(int y:e[x])if(!vis[y]){
		solve(y);
	}
}
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n;
	For(i,1,n+1){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	For(i,1,n+1)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	//For(i,1,n+1)cerr<<a[i]<<" \n"[i==n];
	For(i,1,n+1)c[a[i]]++;
	For(i,1,n+1)ju[i]=(c[a[i]]==1);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	For(i,1,n){
		int x,y;
		cin>>x>>y;
		e[x].pb(y);
		e[y].pb(x);
	}
	sz[1]=n;
	solve(1);
	int ans=0;
	For(i,1,n+1){
		ans+=ju[i];
	//	if(ju[i])cerr<<i<<endl;
	}
	cout<<ans<<endl;
}