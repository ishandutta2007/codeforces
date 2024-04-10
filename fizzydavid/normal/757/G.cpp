//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int root,cgo[400111][3],cid[400111],cidtot,cp[400111],clv[400111];
ll tmpa[400111],tmpb[400111];
int tmpc[400111];
struct PersistentTree
{
	int state[200111],go[9000111][3],c[9000111],tot;
	ll a[9000111],b[9000111];
	PersistentTree(){tot=0;}
	int newnode(int p)
	{
		tot++;
		a[tot]=a[p];
		return tot;
	}
	#define ls go[p][0]
	#define ms go[p][1]
	#define rs go[p][2]
	#define tls cgo[t][0]
	#define tms cgo[t][1]
	#define trs cgo[t][2]
	#define pls go[pp][0]
	#define pms go[pp][1]
	#define prs go[pp][2]
	int build(int t)
	{
		int p=++tot;
		a[p]=b[p]=c[p]=0;
		if(tls)ls=build(tls);
		if(tms)ms=build(tms);
		if(trs)rs=build(trs);
		return p;
	}
	void init()
	{
		state[0]=build(root);
	}
	int change(int x,int pp,int t)
	{
//		cout<<"change:"<<x<<" "<<pp<<" "<<t<<endl;
		int p=++tot;
		a[p]=a[pp]+tmpa[t];
		b[p]=b[pp]+tmpb[t];
		c[p]=c[pp]+tmpc[t];
		if(cid[t]!=x)
		{
			if(!tms||x<cid[tms])ls=change(x,pls,tls),ms=pms,rs=prs;
			else if(!trs||x<cid[trs])ls=pls,ms=change(x,pms,tms),rs=prs;
			else ls=pls,ms=pms,rs=change(x,prs,trs);
		}
		else ls=pls,ms=pms,rs=prs;
		return p;
	}
	void query(int x,int p,int t)
	{
		tmpa[t]=a[p];
		tmpb[t]=b[p];
		tmpc[t]=c[p];
		if(cid[t]!=x)
		{
			if(!tms||x<cid[tms])query(x,ls,tls);
			else if(!trs||x<cid[trs])query(x,ms,tms);
			else query(x,rs,trs);
		}
	}
	void newst(int x,int id){state[id]=change(cid[x],state[id-1],root);}
	void queryst(int x,int id){query(cid[x],state[id],root);}
	void out(int p)
	{
		if(!p)return;
		cout<<"out:p="<<p<<" "<<a[p]<<","<<b[p]<<","<<c[p]<<endl;
		out(ls);
		out(ms);
		out(rs);
	}
}A;
int n,q,head[400111],nxt[800111],to[800111],cost[800111],tot=1;
void addedge(int x,int y,int w)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	cost[tot]=w;
	nxt[++tot]=head[y];
	head[y]=tot;
	to[tot]=x;
	cost[tot]=w;
}
int a[400111],sz[400111],tid[400111];
vector<int>tv[200111];
bool occ[400111];
int que[400111],qsz;
ll dis[20][400111];
void dfs(int x,int pre=0)
{
	que[qsz++]=x;
	sz[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==pre||occ[to[i]])continue;
		dfs(to[i],x);
		sz[x]+=sz[to[i]];
	}
}
void dfs2(int x,int lv,ll len=0,int pre=0)
{
	dis[lv][x]=len;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==pre||occ[to[i]])continue;
		dfs2(to[i],lv,len+cost[i],x);
	}
}
int buildtree(int x,int lv=0)
{
//	cout<<"buildtree:"<<x<<" "<<lv<<endl;
	qsz=0;
	dfs(x);
	int p=-1;
	for(int i=0;i<qsz;i++)
	{
		int x=que[i];
		if(sz[x]>qsz/2&&(p==-1||sz[x]<sz[p]))
		{
			p=x;
		}
	}
	if(lv==0)root=p;
//	cout<<"p="<<p<<endl;
	clv[p]=lv;
	cid[p]=++cidtot;
	dfs2(p,lv);
	occ[p]=1;
	for(int i=head[p];i;i=nxt[i])
	{
		if(!occ[to[i]])
		{
			int id=buildtree(to[i],lv+1);
			cp[id]=p;
			if(!cgo[p][0])cgo[p][0]=id;
			else if(!cgo[p][1])cgo[p][1]=id;
			else cgo[p][2]=id;
		}
	}
	return p;
}
void update(int id)
{
	int x=a[id],p=x,lv=clv[x];
//	cout<<"update:"<<id<<" "<<x<<endl;
	while(p)
	{
//		cout<<"p="<<p<<" lv="<<lv<<endl;
		tmpa[p]=dis[lv][x];
		if(lv)tmpb[p]=dis[lv-1][x];else tmpb[p]=0;
		tmpc[p]=1;
		p=cp[p];lv--;
	}
//	for(int i=1;i<=n;i++)cout<<tmpa[i]<<","<<tmpb[i]<<","<<tmpc[i]<<" ";cout<<endl;
	A.newst(x,id);
//	A.out(A.state[id]);
	p=x,lv=clv[x];
}
ll query(int x,int id)
{
//	cout<<"query:"<<x<<" "<<id<<endl;
	A.queryst(x,id);
//	for(int i=1;i<=n;i++)cout<<tmpa[i]<<","<<tmpb[i]<<","<<tmpc[i]<<" ";cout<<endl;
	int p=x,lv=clv[x];
	ll ret=0,pre=0;
	int pcnt=0;
	while(p)
	{
		ret+=dis[lv][x]*(tmpc[p]-pcnt)+tmpa[p]-pre;
//		cout<<tmpc[p]-pcnt<<" "<<dis[lv][x]<<" "<<tmpa[p]-pre<<endl;
		pcnt=tmpc[p];
		pre=tmpb[p];
		p=cp[p];lv--;
	}
	return ret;
}
int main()
{
	getii(n,q);
	int on=n;
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		getiii(x,y,w);
		addedge(i*2-1,i*2,w);
		tv[x].PB(i*2-1);
		tv[y].PB(i*2);
		if(!tid[x])tid[x]=i*2-1;
		if(!tid[y])tid[y]=i*2;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=tid[a[i]];
//		cout<<a[i]<<",";
	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j+1<tv[i].size();j++)
		{
			addedge(tv[i][j],tv[i][j+1],0);
		}
	}
	n=(n-1)*2;
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<i<<":"<<endl;
		for(int j=head[i];j;j=nxt[j])
		{
			cout<<to[j]<<","<<cost[j]<<" ";
		}
		cout<<endl;
	}*/
	buildtree(1);
/*	for(int i=0;i<5;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}*/
	A.init();
	for(int i=1;i<=on;i++)update(i);
	ll lastans=0;
	int mod=(1<<30)-1;
	for(int i=1;i<=q;i++)
	{
		int type;
		geti(type);
		if(type==1)
		{
			int l,r,v;
			getiii(l,r,v);
			l^=lastans;r^=lastans;v^=lastans;
			v=tid[v];
			ll ansr=query(v,r);
			ll ansl=query(v,l-1);
			lastans=ansr-ansl;
			putsi(lastans);
			lastans&=mod;
		}
		else
		{
			int x;
			geti(x);
			x^=lastans;
			swap(a[x],a[x+1]);
			update(x);
		}
	}
	return 0;
}