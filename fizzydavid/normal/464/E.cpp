//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
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
struct node
{
	int hs,tl,tr;
};
int zeror,pw2[100111];
struct SGT
{
	int N;
	node a[10000111];
	int tot;
	#define ls a[p].tl
	#define rs a[p].tr
	int newnode(int pp)
	{
		int p=++tot;
		a[p].hs=a[pp].hs;
		a[p].tl=a[pp].tl;
		a[p].tr=a[pp].tr;
		return p;
	}
	int build(int l,int r)
	{
		int p=newnode(0);
		if(l<r)
		{
			int m=l+r>>1;
			ls=build(l,m);
			rs=build(m+1,r);
		}
		return p;
	}
	#define check(tmp) tmp=tmp<p?newnode(tmp):tmp
	bool compare(int p1,int p2,int l,int r)
	{
//		cout<<"compare:"<<p1<<" "<<p2<<" "<<l<<","<<r<<" "<<a[p1].hs<<" "<<a[p2].hs<<" "<<a[a[p1].tl].hs<<" "<<a[a[p2].tl].hs<<endl;
		if(l+26>=r||a[p1].hs==0||a[p2].hs==0)return a[p1].hs<a[p2].hs;
		int m=l+r>>1;
		if(a[a[p1].tr].hs==a[a[p2].tr].hs)return compare(a[p1].tl,a[p2].tl,l,m);
		else return compare(a[p1].tr,a[p2].tr,m+1,r);
	}
	bool Compare(int p1,int p2){return compare(p1,p2,0,N);}
	void update(int p,int lsz)
	{
		a[p].hs=(a[ls].hs+1ll*pw2[lsz]*a[rs].hs)%mod;
	}
	bool add(int x,int l,int r,int p)
	{
		if(l==r)
		{
			a[p].hs^=1;
			return a[p].hs==0;
		}
		bool ret;
		int m=l+r>>1;
		if(x<=m)
		{
			if(add(x,l,m,check(ls)))
			{
				if(a[rs].hs==(pw2[r-m]+mod-1)%mod)rs=0,ret=1;
				else add(m+1,m+1,r,check(rs)),ret=0;
			}
			else ret=0;
		}
		else ret=add(x,m+1,r,check(rs));
		update(p,m-l+1);
		return ret;
	}
	void Add(int x,int p)
	{
		add(x,0,N,p);
	}
	void Init()
	{
		N=100020;
		tot=0;
		a[0].hs=a[0].tl=a[0].tr=0;
		int p=build(0,N);
		zeror=p;
	}
}A;
int n,m;
int h[200111],hn;
vector<pair<int,int> >con[100111];
int disr[100111],id[10000111],pre[100111];
void insert(int x)
{
	int p=++hn;
	h[p]=x;
	while(p>1&&A.Compare(h[p],h[p>>1]))
	{
		swap(h[p],h[p>>1]);
		p=p>>1;
	}
}
int top(){return h[1];}
void pop()
{
	h[1]=h[hn--];
	h[hn+1]=0;
	int p=1;
	while(h[p<<1])
	{
		if(h[p<<1|1]==0||A.Compare(h[p<<1],h[p<<1|1]))
		{
			if(A.Compare(h[p<<1],h[p]))
			{
				swap(h[p],h[p<<1]);
				p=p<<1;
			}
			else break;
		}
		else
		{
			if(A.Compare(h[p<<1|1],h[p]))
			{
				swap(h[p],h[p<<1|1]);
				p=p<<1|1;
			}
			else break;
		}
	}
}
bool vis[100111];
vector<int>route;
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	pw2[0]=1;
	for(int i=1;i<=100100;i++)pw2[i]=1ll*pw2[i-1]*2%mod;
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		getiii(x,y,c);
		con[x].PB(MP(y,c));
		con[y].PB(MP(x,c));
	}
	A.Init();
	int S,T;
	getii(S,T);
	memset(disr,-1,sizeof(disr));
	disr[S]=A.newnode(zeror);
	id[disr[S]]=S;
	insert(disr[S]);
	while(hn)
	{
		int u=id[top()];pop();
		if(vis[u])continue;
//		cout<<"dijkstra:"<<u<<" "<<A.a[disr[u]].hs<<endl;
		vis[u]=1;
		if(u==T)
		{
			putsi(A.a[disr[u]].hs);
//			return 0;
			int p=T;
			while(p!=S)route.PB(p),p=pre[p];
			route.PB(S);
			reverse(route.begin(),route.end());
			putsi(route.size());
			for(auto x:route)puti(x);
			return 0;
		}
		for(auto e:con[u])
		{
			int v=e.FF,c=e.SS;
			if(vis[v])continue;
			int tmp=A.newnode(disr[u]);
			A.Add(c,tmp);
			if(disr[v]==-1||A.Compare(tmp,disr[v]))
			{
				disr[v]=tmp;
				id[tmp]=v;
				insert(tmp);
				pre[v]=u;
			}
		}
	}
	puts("-1");
	return 0;
}