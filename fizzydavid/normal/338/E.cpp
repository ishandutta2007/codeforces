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
	int mn,dlt;
	node(){mn=dlt=0;}
};
int ia[150011];
struct FruitCandy
{
	node a[600011];
	int n;
	#define ls p<<1
	#define rs p<<1|1
	void build(int l,int r,int p)
	{
		if(l==r)
		{
			a[p].mn=ia[l];
			return;
		}
		int m=l+r>>1;
		build(l,m,ls);
		build(m+1,r,rs);
		a[p].mn=min(a[ls].mn,a[rs].mn);
	}
	void pushdown(int p)
	{
		if(a[p].dlt!=0)
		{
			a[ls].dlt+=a[p].dlt;
			a[rs].dlt+=a[p].dlt;
			a[ls].mn+=a[p].dlt;
			a[rs].mn+=a[p].dlt;
			a[p].dlt=0;
		}
	}
	void Build(int N)
	{
		n=N;
		build(1,n,1);
	}
	int x,y,v;
	void add(int l,int r,int p)
	{
		if(x<=l&&r<=y)
		{
			a[p].dlt+=v;
			a[p].mn+=v;
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)add(l,m,ls);
		if(m<y)add(m+1,r,rs);
		a[p].mn=min(a[ls].mn,a[rs].mn);
	}
	void Add(int X,int Y,int V)
	{
		x=X;y=Y;v=V;
		if(x>y)return;
		add(1,n,1);
	}
	int Query(){return a[1].mn;}
}sgt;
int n,len,h;
int b[150011],a[150011];
int main()
{
	getiii(n,len,h);
	for(int i=1;i<=len;i++)
	{
		geti(b[i]);
		b[i]=h-b[i];
	}
	sort(b+1,b+len+1);
	for(int i=1;i<=len;i++)ia[i]=-(len-i+1);
	sgt.Build(len);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		a[i]=upper_bound(b+1,b+len+1,a[i])-b-1;
	}
	for(int i=1;i<=len;i++)sgt.Add(1,a[i],1);
	int ans=sgt.Query()>=0;
	for(int i=len+1;i<=n;i++)
	{
		sgt.Add(1,a[i],1);
		sgt.Add(1,a[i-len],-1);
		ans+=sgt.Query()>=0;
	}
	cout<<ans<<endl;
	return 0;
}