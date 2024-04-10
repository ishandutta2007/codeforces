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
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=2e5+11;
struct Edge{
	int v,id;
	Edge *nex;
} pl[N<<1],*cur=pl,*G[N];
void ins(int u,int v,int id){
	cur->v=v,cur->id=id;
	cur->nex=G[u],G[u]=cur++;
}
int wx[N],wy[N],n,m;
int f[N],vis[N],g[N];
void dfs(int x){
	vis[x]=1;
	Es(x,i)if(!vis[i->v]){
		dfs(i->v);
		if(f[i->v]){
			f[i->v]=0;
			f[x]^=1;
			g[i->id]^=1;
		}
	}
}
int q[N];
int main(){
	n=rd(),m=rd();
	rep(i,1,m){
		wx[i]=rd(),wy[i]=rd();
		ins(wx[i],wy[i],i),ins(wy[i],wx[i],i);
		f[wx[i]] ^= 1;
	}
	rep(i,1,n)if(!vis[i])dfs(i);
	int ans=m;
	rep(i,1,n)if(f[i])ans--;
	printf("%d\n",ans>>1);
	rep(x,1,n){
		int cnt=0;
		Es(x,i)if((wy[i->id]!=x)^g[i->id]){
			q[++cnt]=(wx[i->id]^wy[i->id]^x);
		}
		for(int i=1;i<cnt;i+=2){
			printf("%d %d %d\n",q[i],x,q[i+1]);
		}
	}
}