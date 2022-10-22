#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

const int Mod=998244353;
namespace modular{
	void Add(int &a,int b){a=a+b>=Mod?a+b-Mod:a+b;}
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;

int n;
#define Maxn 305
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int dep[Maxn],R;
int F[Maxn][Maxn],G[Maxn][Maxn];
int f[Maxn],g[Maxn];
void gao(int u,int t){
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=t)gao(v[i],u);
	F[u][0]=1;G[u][0]=1;int mx=0;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=t){
			int x=v[i];
			rep(j,0,max(mx,dep[v[i]]+1))f[j]=g[j]=0;
			rep(j,0,mx)
				rep(k,0,dep[v[i]]){
					Add(g[max(j,k+1)],mul(G[u][j],G[x][k]));
					Add(f[min(j,k+1)],mul(F[u][j],F[x][k]));
					if(j+k+1<=R){
						Add(f[j],mul(F[u][j],G[x][k]));
						Add(f[k+1],mul(G[u][j],F[x][k]));
					}else{
						Add(g[k+1],mul(F[u][j],G[x][k]));
						Add(g[j],mul(G[u][j],F[x][k]));
					}
				}
			mx=max(mx,dep[v[i]]+1);
			rep(j,0,mx){
				F[u][j]=f[j];
				G[u][j]=g[j];
			}
		}
}

void pre_dfs(int u,int f){
	dep[u]=0;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			pre_dfs(v[i],u);
			dep[u]=max(dep[u],dep[v[i]]+1);
		}
}

int main(){
	rd(n);
	int s,e,res=2;
	rep(i,1,n-1){
		res=add(res,res);
		rd(s);rd(e);
		add_edge(s,e);
	}
	res=mul(res,n);
	pre_dfs(1,0);
	for(R=n;R>=0;--R){
		gao(1,0);
		rep(i,0,dep[1])res=dec(res,F[1][i]);
	}
	rep(i,1,n)res=mul(res,499122177);
	printf("%d\n",res);
	return 0;
}