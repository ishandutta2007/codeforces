#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define gc getchar()
#define pb push_back
#define N 1000000
using namespace std;
int n,m,q,nn,mm,al,u,R,x,y,ff[N][19];
int p[N],ex[N],ey[N],Ex[N],Ey[N],f[N],F[N],ro[N];
int TT[N],h[N],H[N],v[N],g[N],G[N],te[N],dfn[N],nd[N],uz[N];
vector<int>e[N],w[N];
bool cmp(const int &x,const int &y){return dfn[x]<dfn[y];}
int gf(int x){if(g[x]==x)return x;g[x]=gf(g[x]);return g[x];}
int Gf(int x){if(G[x]==x)return x;G[x]=Gf(G[x]);return G[x];}
int Tr(int x){if(te[x]==x)return x;te[x]=Tr(te[x]);return te[x];}
void dfs(int x){int sz=e[x].size()-1;
	dfn[x]=al++;ff[x][0]=f[x];v[x]=1;
	rep(i,1,18)ff[x][i]=ff[ff[x][i-1]][i-1];
	rep(i,0,sz){int tt=e[x][i];
		if(!v[tt]){ro[tt]=ro[x];h[tt]=h[x]+1;f[tt]=x;dfs(tt);}
	}
}
int lca(int x,int y){
	if(h[x]<h[y])swap(x,y);
	dep(i,18,0)if((h[x]-(1<<i))>=h[y])x=ff[x][i];
	dep(i,18,0)if(ff[x][i]!=ff[y][i])x=ff[x][i],y=ff[y][i];
	if(x!=y)x=f[x],y=f[y];return g[x];
}
void DFS(int x){
	int sz=w[x].size()-1;v[x]=1;
	rep(i,0,sz){int tt=w[x][i];
		if(!v[tt]){F[tt]=x;H[tt]=H[x]+1;DFS(tt);}
	}
}
void read(int &x){char c=gc;x=0;
	while(c<'0'||c>'9')c=gc;
	for(;c>='0'&&c<='9';c=gc)x=x*10+c-'0';
	x=(x+R-1)%n+1;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,m){
		read(ex[i]);read(ey[i]);
		e[ex[i]].pb(ey[i]);e[ey[i]].pb(ex[i]);
	}al=0;
	rep(i,1,n)if(!v[i]){h[i]=1;ro[i]=i;f[i]=i;dfs(i);}
	rep(i,1,n)v[i]=0,g[i]=i;
	rep(i,1,m){
		if(f[ey[i]]==ex[i])swap(ex[i],ey[i]);
		if(v[ex[i]]||f[ex[i]]!=ey[i]){
			x=gf(ex[i]);y=gf(ey[i]);
			while(x!=y){
				if(h[x]>h[y]){g[gf(x)]=gf(f[x]);x=gf(x);}
				else{g[gf(y)]=gf(f[y]);y=gf(y);}
			}
		}else v[ex[i]]=1;
	}
	rep(i,1,n)gf(i);
	rep(o,1,q){
		scanf("%d%d",&nn,&mm);al=0;
		rep(i,1,nn){read(p[i]);p[i]=g[p[i]];nd[++al]=p[i];}
		rep(i,1,mm)uz[i]=0;
		rep(i,1,mm){
			read(Ex[i]);read(Ey[i]);
			Ex[i]=g[Ex[i]];Ey[i]=g[Ey[i]];
			nd[++al]=Ex[i];nd[++al]=Ey[i];
		}
		sort(nd+1,nd+al+1,cmp);
		al=unique(nd+1,nd+al+1)-(nd+1);u=al-1;
		rep(i,1,u)nd[++al]=lca(nd[i],nd[i+1]);
		sort(nd+1,nd+al+1,cmp);
		al=unique(nd+1,nd+al+1)-(nd+1);
		rep(i,1,al)TT[nd[i]]=i,te[i]=i;
		rep(i,2,al)if(ro[nd[i]]==ro[nd[i-1]])te[Tr(i)]=Tr(i-1);
		rep(i,1,al){F[i]=0;w[i].clear();}
		rep(i,2,al){
			if(Tr(i)!=Tr(i-1))continue;F[i]=i-1;
			while(lca(nd[i],nd[F[i]])!=nd[F[i]])F[i]=F[F[i]];
			w[i].pb(F[i]);w[F[i]].pb(i);
		}
		rep(i,1,mm){
			x=TT[Ex[i]];y=TT[Ey[i]];
			if(Tr(x)!=Tr(y)){
				w[x].pb(y);w[y].pb(x);
				te[Tr(x)]=Tr(y);uz[i]=1;
			}
		}
		rep(i,1,al)F[i]=0,v[i]=0,G[i]=i,H[i]=0;
		rep(i,1,al)if(!v[i]){H[i]=1;DFS(i);}
		rep(i,1,mm)if(!uz[i]){
			x=Gf(TT[Ex[i]]);y=Gf(TT[Ey[i]]);
			while(x!=y){
				if(H[x]>H[y]){G[Gf(x)]=Gf(F[x]);x=Gf(x);}
				else{G[Gf(y)]=Gf(F[y]);y=Gf(y);}
			}
		}
		u=0;rep(i,2,nn)if(Gf(TT[p[i]])!=Gf(TT[p[1]])){u=1;break;}
		if(u)printf("NO\n");else{printf("YES\n");R=(R+o-1)%n+1;}
	}
}