#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int inf=1e9;
struct edge{
	int nt,t,f,w;
}e[N*N];
int tot,ok[N][N],st[N*N],d[N*N],f[N*N],fr[N*N],v[N*N];
void lk(int x,int y,int f,int w){
	e[++tot]={st[x],y,f,w};st[x]=tot;
	e[++tot]={st[y],x,0,-w};st[y]=tot;
}
void flow(int n){
	for(;;){
		rep(i,2,n)d[i]=inf,f[i]=0,v[i]=0,fr[i]=-1;
		queue<int>q;q.push(1);
		d[1]=0;f[1]=inf;v[1]=1;fr[1]=-1;
		while(!q.empty()){
			int x=q.front();q.pop();v[x]=0;
			for(int i=st[x];~i;i=e[i].nt)if(e[i].f){
				int nw=d[x]+e[i].w,t=e[i].t;
				if(nw<d[t]){
					d[t]=nw;fr[t]=i^1;
					f[t]=min(f[x],e[i].f);
					if(!v[t])q.push(t),v[t]=1;
				}
			}
		}
		if(!f[2])break;
		for(int x=fr[2];~x;x=fr[e[x].t])
			e[x].f+=f[2],e[x^1].f-=f[2];
	}
}
int main(){int n,m;tot=-1;
	scanf("%d%d",&n,&m);
	rep(i,1,n*(n+1)/2+2)st[i]=-1;
	rep(i,1,n)rep(j,1,n)if(i!=j)ok[i][j]=1;
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		ok[y][x]=0;
	}int x=n+2;
	rep(i,1,n)rep(j,0,n-2)lk(i+2,2,1,j);
	rep(i,1,n)rep(j,i+1,n){
		lk(1,++x,1,0);
		if(ok[i][j])lk(x,i+2,1,0);
		if(ok[j][i])lk(x,j+2,1,0);
	}
	flow(n*(n+1)/2+2);x=n+2;
	rep(i,1,n)rep(j,i+1,n){
		++x;ok[i][j]=ok[j][i]=0;
		for(int k=st[x];~k;k=e[k].nt){
			if(e[k].t==i+2&&e[k^1].f)ok[i][j]=1;
			if(e[k].t==j+2&&e[k^1].f)ok[j][i]=1;
		}
	}
	rep(i,1,n){
		rep(j,1,n)printf("%d",ok[i][j]);printf("\n");
	}
}