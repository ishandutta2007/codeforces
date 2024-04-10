#include<bits/stdc++.h>
using namespace std;
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
char *TT,*tmo,but[(1<<15)+2];
#define getc() ((TT==tmo&&(tmo=((TT=but)+fread(but,1,1<<15,stdin)),TT==tmo))?-1:*TT++)
inline int rd(){
  int x,c,f=1;while(!isdigit(c=getc()))f=c!='-';x=c-'0';
  while(isdigit(c=getc()))x=x*10+c-'0';return f?x:-x;
}
const int N=5e5+11;
int n,K,m;
int fa[N],f[N],w[N];
int fd(int i){
	return !f[i]?i:f[i]=fd(f[i]);
}
vector<int> g[N],gg[N];
int c[N],d[N],cu;
void dfs(int x){
	//cerr<<x<<endl;
	c[x]=cu;
	foe(i,g[x]){
		if(!c[*i])
		{
			fa[*i]=x;
			d[*i]=d[x]+1;
			w[*i]=gg[x][i-g[x].begin()];
			dfs(*i);
		}
	}
}
void wk(int x,int y,int z){
	x=fd(x),y=fd(y);
		//int cn=0;
		while(x^y){
			//if(++cn<=10)cerr<<x<<" "<<y<<" "<<d[x]<<" "<<d[y]<<endl;
			//if(cn>10)return 0;
			if(d[x]<d[y])swap(x,y);
			w[x]=w[x]?w[x]:z;
			x=f[x]=fd(fa[x]);
		}
}
int U[N],V[N],Z[N],wr;
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	n=rd(),K=rd(),m=rd();
	int i,x,y,z,a,b;
	//for(i=1;i<=n;++i)f[i]=i;
	//for(i=1;i<=n;++i)r[i]=i;

	for(i=1;i<=K;++i){
		x=rd(),y=rd();
		g[x].push_back(y);
		gg[x].push_back(0);
		g[y].push_back(x);
		gg[y].push_back(0);
		x=fd(x),y=fd(y);
		if(x^y)f[x]=y;
	}
	long long ans=0;
	while(m--){
		x=rd(),y=rd(),z=rd();
		a=fd(x),b=fd(y);
		if(a^b)
		{
			g[x].push_back(y);
			gg[x].push_back(z);
			g[y].push_back(x);
			gg[y].push_back(z);
			ans-=z;
			f[a]=b;
		}else{
			U[++wr]=x;
			V[wr]=y;
			Z[wr]=z;
		}
	}
	for(i=1;i<=n;++i)
		if(!c[i])cu=i,dfs(i);
	//cerr<<"ok\n";
	memset(f,0,sizeof f);
	for(i=1;i<=wr;++i)
		wk(U[i],V[i],Z[i]);
	for(i=1;i<=n;++i)
		if(d[i]){
			if(!w[i])
			{
				puts("-1");
				return 0;
			}
			ans+=w[i];
		}
	cout<<ans;
}