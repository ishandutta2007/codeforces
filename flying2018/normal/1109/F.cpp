#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define M 2010
using namespace std;
int num[N],nxt[N<<2],to[N<<2],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
int id[M][M];
const int ux[5]={0,1,0,-1},
		  uy[5]={1,0,-1,0};
struct LCT{
	int ch[N][2],fa[N],tag[N],cnt;
	bool not_root(int u){return ch[fa[u]][0]==u || ch[fa[u]][1]==u;}
	void set_tag(int u){swap(ch[u][0],ch[u][1]);tag[u]^=1;}
	void push_down(int u)
	{
		if(!tag[u]) return;
		tag[u]=false;
		set_tag(ch[u][0]);
		set_tag(ch[u][1]);
	}
	void rotate(int u)
	{
		int f=fa[u],ff=fa[f];
		int k=ch[f][1]==u,v=ch[u][!k];
		if(not_root(f)) ch[ff][ch[ff][1]==f]=u;
		ch[u][!k]=f;
		ch[f][k]=v;
		if(v)fa[v]=f;
		fa[f]=u;
		fa[u]=ff;
	}
	int ton[N],top;
	void push_all(int u)
	{
		top=0;
		while(not_root(u)) ton[++top]=u,u=fa[u];
		ton[++top]=u;
		for(;top;top--) push_down(ton[top]);
	}
	void splay(int u)
	{
		push_all(u);
		while(not_root(u))
		{
			int f=fa[u],ff=fa[f];
			if(not_root(f)) rotate((ch[ff][0]==f)^(ch[f][0]==u)?u:f);
			rotate(u);
		}
	}
	void access(int x)
	{
		for(int y=0;x;y=x,x=fa[x])
		splay(x),ch[x][1]=y;
	}
	void make_root(int x)
	{
		access(x);
		splay(x);
		set_tag(x);
	}
	void split(int x,int y)
	{
		make_root(x);
		access(y);
		splay(y);
	}
	int find_root(int x)
	{
		access(x);
		splay(x);
		while(ch[x][0]) push_down(x),x=ch[x][0];
		splay(x);
		return x;
	}
	bool link(int u,int v)
	{
		make_root(u);
		if(find_root(v)==u) return false;
		fa[u]=v;
		return true;
	}
	void cut(int u,int v)
	{
		make_root(u);
		if(find_root(v)!=u || fa[v]!=u || ch[v][0]) return;
		fa[v]=0,ch[u][1]=0;
	}
}t0;
int val[N<<2],tv[N<<2],tag[N<<2];
void update(int u)
{
	tv[u]=0,val[u]=min(val[u<<1],val[u<<1|1]);
	tv[u]=(int)(val[u]==val[u<<1])*tv[u<<1]+(int)(val[u]==val[u<<1|1])*tv[u<<1|1];
}
void build(int u,int l,int r)
{
	val[u]=0,tv[u]=r-l+1;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
}
void set_tag(int u,int v){tag[u]+=v,val[u]+=v;}
void push_down(int u){if(tag[u]) set_tag(u<<1,tag[u]),set_tag(u<<1|1,tag[u]),tag[u]=0;}
void insert(int u,int l,int r,int L,int R,int v)
{
	if(L<=l && r<=R){set_tag(u,v);return;}
	push_down(u);
	int mid=(l+r)>>1;
	if(L<=mid) insert(u<<1,l,mid,L,R,v);
	if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
	update(u);
}
int rres,rcnt;
int answer(int u,int l,int r,int L,int R)
{
	if(L<=l && r<=R){return val[u]==1?tv[u]:0;}
	push_down(u);
	int mid=(l+r)>>1,ans=0;
	if(L<=mid) ans+=answer(u<<1,l,mid,L,R);
	if(R>mid) ans+=answer(u<<1|1,mid+1,r,L,R);
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		scanf("%d",&id[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int _=0;_<4;_++)
			{
				int x=i+ux[_],y=j+uy[_];
				if(x<1 || y<1 || x>n || y>m || id[x][y]>id[i][j]) continue;
				add(id[x][y],id[i][j]),add(id[i][j],id[x][y]);
			}
	int r=0,t=n*m;
	long long ans=0;
	build(1,1,t);
	for(int l=1;l<=t;l++)
	{
		for(int u=r+1;u<=t;u++)
		{
			bool can=true;
			for(int i=head[u];i;i=nxt[i])
			{
				int v=to[i];
				if(v<u && v>=l && !t0.link(v,u)){can=false;break;}
			}
			for(int i=head[u];i;i=nxt[i])
			{
				int v=to[i];
				if(v>=u || v<l) continue;
				t0.cut(v,u);
			}
            if(!can) break;
            r=u;
			int tot=0;
			for(int i=head[u];i;i=nxt[i])
			{
				int v=to[i];
				if(v<u && v>=l) t0.link(v,u),++tot;
			}
            insert(1,1,t,r,r,r-l+1);
            insert(1,1,t,r,t,-tot);
		}
		ans+=answer(1,1,t,l,r);
        for(int i=head[l];i;i=nxt[i])
        {
        	int v=to[i];
        	if(v<=r && v>l) t0.cut(v,l),insert(1,1,t,v,t,1);
		}
		insert(1,1,t,l,r,-1);
	}
	printf("%lld\n",ans);
	return 0;
}