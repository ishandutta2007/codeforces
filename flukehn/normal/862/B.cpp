#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1e5+11;
struct Edge{
	int v;
	Edge *nex;
} pl[N<<1],*G[N],*cur=pl;
void ins(int u,int v){
	cur->v=v,cur->nex=G[u],G[u]=cur++;
}
int n;
int vis[N],d[N];
void dfs(int x,int fa=0){
	vis[x] = !vis[fa];
	Es(x,i)if(i->v!=fa){
		dfs(i->v,x);
	}
}
int main(){
	memset(vis,-1,sizeof vis);
	n=rd();
	rep(i,1,n-1){
		int u=rd(),v=rd();
		ins(u,v),ins(v,u);
		d[u]++,d[v]++;
	}
	dfs(1);
	int t1=0,t2=0;
	ll ans=0;
	rep(i,1,n)if(vis[i])t1++;else t2++;
	rep(i,1,n)if(!vis[i]){
		//ans+=t2-d[i];
		ans+=t1-d[i];
	}
	cout<<ans<<endl;
}