#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=300005,dx[]={1,0},dy[]={0,1};typedef std::pair<int,int> pi;
std::vector<int> a[N],nd[N],e[N],G[N];pi t[N];int n,x[N],y[N],L[N],R[N],m,bel[N];
inline int getid(int x,int y){
	int p=std::lower_bound(t+1,t+n+1,(pi){x,y})-t;
	return t[p]!=(pi){x,y}?-1:p;
}
bool vis[N];int siz[N],S,mn,RT,fa[N],cur,dep[N],dis[20][N],p[20][N];
int getS(int x,int fa){int s=1;for(auto v:e[x])if(v!=fa&&!vis[v])s+=getS(v,x);return s;}
void getrt(int x,int fa){
	siz[x]=1;int tmp=0;
	for(auto v:e[x])if(v!=fa&&!vis[v])getrt(v,x),siz[x]+=siz[v],tmp=std::max(tmp,siz[v]);
	tmp=std::max(tmp,S-siz[x]);if(tmp<mn)mn=tmp,RT=x;
}
int _q[N],_l,_r;
void dfs(int x,int fa){
	S=getS(x,0),mn=1e9,getrt(x,0),vis[x=RT]=1,::fa[x]=fa,cur=dep[x]=dep[fa]+1;
	_l=1,_r=0;for(auto it:nd[x])p[cur][it]=t[it].second-L[x]+1,dis[cur][it]=0,_q[++_r]=it;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(auto v:G[x]){
			int o=bel[v];if(vis[o]||p[cur][v])continue;
			dis[cur][v]=dis[cur][x]+1,p[cur][v]=p[cur][x],_q[++_r]=v;
		}
	}
	for(auto v:e[x])if(!vis[v])dfs(v,x);
}
const int NC=N*20;
int ls[NC],rs[NC],mn1[NC],mn2[NC],nc,rt[N];
void Update(int &u,int pos,int C1,int C2,int l,int r){
	if(!u)u=++nc,mn1[u]=C1,mn2[u]=C2;
	else chmin(mn1[u],C1),chmin(mn2[u],C2);
	if(l==r)return;
	int mid=(l+r)>>1;
	pos<=mid?Update(ls[u],pos,C1,C2,l,mid):Update(rs[u],pos,C1,C2,mid+1,r);
}
int ask1(int L,int R,int l,int r,int u){
	if(!u)return 1e9;
	if(L<=l&&r<=R)return mn1[u];
	int mid=(l+r)>>1;
	if(L<=mid&&R>mid)return std::min(ask1(L,R,l,mid,ls[u]),ask1(L,R,mid+1,r,rs[u]));
	return L<=mid?ask1(L,R,l,mid,ls[u]):ask1(L,R,mid+1,r,rs[u]);
}
int ask2(int L,int R,int l,int r,int u){
	if(!u)return 1e9;
	if(L<=l&&r<=R)return mn2[u];
	int mid=(l+r)>>1;
	if(L<=mid&&R>mid)return std::min(ask2(L,R,l,mid,ls[u]),ask2(L,R,mid+1,r,rs[u]));
	return L<=mid?ask2(L,R,l,mid,ls[u]):ask2(L,R,mid+1,r,rs[u]);
}
int main(){
	read(n);for(int i=1;i<=n;++i)read(x[i],y[i]),t[i]={x[i],y[i]},a[x[i]].pb(y[i]);
	std::sort(t+1,t+n+1);int last=-1;
	for(int i=1;i<=n;++i){
		int a=getid(x[i],y[i]);
		for(int dir=0;dir<2;++dir){
			int u=x[i]+dx[dir],v=y[i]+dy[dir],b=getid(u,v);
			if(b!=-1)G[a].pb(b),G[b].pb(a);
		}
	}
	for(int i=1;i<=3e5;++i)if(!a[i].empty()){
		std::sort(a[i].begin(),a[i].end());int p=last+1,tmp=m;
		for(int j=0;j<SZ(a[i]);){
			int k=j;while(k+1<SZ(a[i])&&a[i][k+1]==a[i][k]+1)++k;
			++m,L[m]=a[i][j],R[m]=a[i][k];
			while(j<=k){
				int u=getid(i,a[i][j++]);
				nd[m].pb(u),bel[u]=m;
			}
			if(last!=-1){
				while(p<=tmp&&R[p]<L[m])++p;
				for(int t=p;t<=tmp&&L[t]<=R[m];++t)e[t].pb(m),e[m].pb(t);
			}
		}
		last=tmp;
	}
	dep[0]=-1,dfs(1,0);
	int q,opt,x,y;read(q);
	while(q--){
		read(opt,x,y);
		int id=getid(x,y),cur=bel[id],d,pos;
		if(opt==1){
			while(cur){
				d=dis[dep[cur]][id],pos=p[dep[cur]][id];
				Update(rt[cur],pos,d-pos,d+pos,1,3e5),cur=fa[cur];
			}
		}
		else{
			int ans=1e9;
			while(cur){
				d=dis[dep[cur]][id],pos=p[dep[cur]][id];
				ans=std::min({ans,d+ask1(1,pos,1,3e5,rt[cur])+pos,d+ask2(pos,3e5,1,3e5,rt[cur])-pos}),cur=fa[cur];
			}
			printf("%d\n",ans>=1e8?-1:ans);
		}
	}
	return 0;
}