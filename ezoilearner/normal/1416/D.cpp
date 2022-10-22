#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,q;
#define Maxn 400010
#define cout cerr
#define FR first
#define SE second
pii edge[Maxn];
int val[Maxn];
int son[Maxn][2],cnt,in[Maxn],out[Maxn],dfk=0;
#define ls son[u][0]
#define rs son[u][1]
int seq[Maxn],a[Maxn];
int fa[Maxn][20];

int go(int k,int t){
	for(int i=19;i>=0;--i)
		if(val[fa[k][i]]>t)k=fa[k][i];
	return k;
}
void Dfs(int u){
	in[u]=++dfk;seq[dfk]=u;
	for(int i=1;i<20;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
	if(ls){
		fa[ls][0]=u;
		Dfs(ls);
	}
	if(rs){
		fa[rs][0]=u;
		Dfs(rs);
	}
	out[u]=dfk;
}
int mx[Maxn<<2],to[Maxn];
void BT(int k,int l,int r){
	if(l==r){
		mx[k]=a[seq[l]];
		return;
	}
	int mid=(l+r)>>1;
	BT(k<<1,l,mid);BT(k<<1|1,mid+1,r);mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
void hh(int k,int l,int r,int pos){
	if(l==r){
		mx[k]=0;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)hh(k<<1,l,mid,pos);
	else hh(k<<1|1,mid+1,r,pos);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
int gao(int k,int l,int r,int L,int R){
	if(l==L&&r==R)return mx[k];
	int mid=(l+r)>>1;
	if(R<=mid)return gao(k<<1,l,mid,L,R);
	else if(mid<L)return gao(k<<1|1,mid+1,r,L,R);
	else return max(gao(k<<1,l,mid,L,mid),gao(k<<1|1,mid+1,r,mid+1,R));
}

int vis[Maxn];
pii E[Maxn];int len=0;
pii qt[500010];
int anc[Maxn];

int getroot(int x){
	if(anc[x]!=x)anc[x]=getroot(anc[x]);
	return anc[x];
}
void Add(int ed,int t){
	int fx=getroot(edge[ed].FR),fy=getroot(edge[ed].SE);
	if(fx==fy)return;
	val[++cnt]=t;
	anc[fx]=anc[fy]=cnt;son[cnt][0]=fx;son[cnt][1]=fy;
}

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

int main(){
	rd(n);rd(m);rd(q);cnt=n;
	for(int i=1;i<=n;++i)rd(a[i]),to[a[i]]=i,val[n]=q+1;
	for(int i=1;i<=m;++i){
		rd(edge[i].FR);rd(edge[i].SE);
		vis[i]=q+1;
	}
	for(int i=1;i<=q;++i){
		rd(qt[i].FR);rd(qt[i].SE);
		if(qt[i].FR==2)E[++len]=pii(qt[i].SE,i),vis[qt[i].SE]=0;
	}
	for(int i=1;i<2*n;++i)anc[i]=i;
	for(int i=1;i<=m;++i)if(vis[i])E[++len]=pii(i,vis[i]);
	for(int i=m;i>=1;--i)Add(E[i].FR,E[i].SE);
	for(int i=cnt;i>=1;--i)
		if(!in[i])Dfs(i);
	BT(1,1,cnt);
	for(int i=1;i<=q;++i)
		if(qt[i].FR==1){
			int u=go(qt[i].SE,i);
			u=gao(1,1,cnt,in[u],out[u]);
			printf("%d\n",u);
			if(u){
				u=to[u];
				hh(1,1,cnt,in[u]);
			}
		}
	return 0;
}