#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=55,M=N*(N-1)/2,inf=0x3f3f3f3f;
typedef std::pair<int,int> pi;
struct edge{int v,nxt;}c[M*M];
int front[M],ec;
inline void addedge(int u,int v){c[++ec]=(edge){v,front[u]},front[u]=ec;}
int d[N],_w[N][N],n,k,u[M],v[M],w[M],m;
struct DSU{
	int fa[N];
	DSU(){std::iota(fa,fa+N,0);}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	inline void merge(int x,int y){fa[find(x)]=find(y);}
}T,o;
pi qaq[15];int pos;
bool in[M],inq[M];
int DG[6],dg[N],a[M],_q[1000005],pre[M];
int dis[M],len[M];int _l,_r;
bool extend(){
	memcpy(dg,DG,24),o=T;ec=0;
	for(int i=1;i<=m;++i)pre[i]=0,dis[i]=inf,len[i]=inf,a[i]=in[i]?-w[i]:w[i],front[i]=0;
	for(int i=1;i<=m;++i)if(in[i]){
		++dg[u[i]],++dg[v[i]];
		o.merge(u[i],v[i]);
	}
	_l=1,_r=0;
	for(int i=1;i<=m;++i)if(!in[i]&&o.find(u[i])!=o.find(v[i]))_q[++_r]=i,dis[i]=a[i],len[i]=0,inq[i]=true;
	for(int i=1;i<=m;++i)if(in[i]){
		o=T;
		for(int p=1;p<=m;++p)if(in[p]&&i!=p)o.merge(u[p],v[p]);
		for(int p=1;p<=m;++p)if(!in[p]&&o.find(u[p])!=o.find(v[p]))addedge(i,p);
	}
	for(int i=1;i<=m;++i)if(in[i]){
		--dg[u[i]],--dg[v[i]];
		for(int p=1;p<=m;++p)if(!in[p]){
			if(dg[u[p]]+1<=d[u[p]]&&dg[v[p]]+1<=d[v[p]])addedge(p,i);
		}
		++dg[u[i]],++dg[v[i]];
	}
	while(_l!=_r+1){
		int x=_q[_l++];inq[x]=false;
		for(int _=front[x];_;_=c[_].nxt){
			int v=c[_].v,d=dis[x]+a[v],l=len[x]+1;
			if(dis[v]>d||(dis[v]==d&&len[v]>l)){
				dis[v]=d,len[v]=l,pre[v]=x;
				if(!inq[v])_q[++_r]=v,inq[v]=1;
			}
		}
	}
	int mn1=inf,mn2=inf,a=0;
	for(int i=1;i<=m;++i)if(!in[i]){
		bool flag=(dg[u[i]]+1<=d[u[i]])&&(dg[v[i]]+1<=d[v[i]]);
		if(flag&&(dis[i]<mn1||(dis[i]==mn1&&len[i]<mn2)))mn1=dis[i],mn2=len[i],a=i;
	}
	if(a){
		while(a)in[a]^=1,a=pre[a];
		return true;
	}
	return false;
}
int main(){
	read(n,k);
	memset(d,63,sizeof(d));
	for(int i=1;i<=k;++i)read(d[i]);
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)read(_w[i][j]);
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(j>k)u[++m]=i,v[m]=j,w[m]=_w[i][j];
	for(int i=1;i<=k;++i)for(int j=i+1;j<=k;++j)qaq[pos++]={i,j};
	int ans=1e9;
	for(int st=0;st<1<<pos;++st){
		T=DSU();std::vector<pi> E;for(int i=0;i<pos;++i)if(st>>i&1)E.pb(qaq[i]);
		memset(DG,0,24),memset(in,0,sizeof(in));
		int cnt=0,s=0;bool flag=0;
		for(auto [x,y]:E){
			s+=_w[x][y],++cnt;
			if(T.find(x)==T.find(y))flag=1;
			T.merge(x,y),++DG[x],++DG[y];
		}
		for(int i=1;i<=k;++i)if(DG[i]>d[i])flag=1;
		if(flag)continue;
		while(extend())++cnt;
		if(cnt==n-1){
			for(int i=1;i<=m;++i)if(in[i])s+=w[i];
			ans=std::min(ans,s);
		}
	}
	printf("%d\n",ans);
	return 0;
}