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
const ll Lbg=2e18;
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
const int msk=1023;
int na[1000111],b[msk+1];
int id[1000111],nid[1000111];
void kotori_sort(int a[],int n)
{
	for(int i=1;i<=n;i++)id[i]=i,a[i]+=500000;
	for(int tt=0;tt<1;tt++)
	{
		memset(b,0,sizeof(b));
		int tmp=0;
		for(int i=1;i<=n;i++)b[(a[i]>>tmp)&msk]++;
		for(int i=1;i<=msk;i++)b[i]+=b[i-1];
		for(int i=n;i>=1;i--)
		{
			int x=(a[i]>>tmp)&msk;
			nid[b[x]]=id[i];
			na[b[x]--]=a[i];
		}
		memset(b,0,sizeof(b));
		tmp=10;
		for(int i=1;i<=n;i++)b[(na[i]>>tmp)&msk]++;
		for(int i=1;i<=msk;i++)b[i]+=b[i-1];
		for(int i=n;i>=1;i--)
		{
			int x=(na[i]>>tmp)&msk;
			id[b[x]]=nid[i];
			a[b[x]--]=na[i];
		}
	}
	for(int i=1;i<=n;i++)a[i]-=500000;
}
int ia[500111];
struct FruitCandy
{
	struct node
	{
		int mn,lazy;
	}a[2000111];
	int n;
	#define ls p<<1
	#define rs p<<1|1
	void pushdown(int p,bool f)
	{
		int lz=a[p].lazy;
		a[p].lazy=0;
		if(lz!=0&&f)
		{
			a[ls].lazy+=lz;a[ls].mn+=lz;
			a[rs].lazy+=lz;a[rs].mn+=lz;
		}
	}
	void build(int l,int r,int p)
	{
		if(l==r)
		{
			a[p].mn=ia[l];
			a[p].lazy=0;
			return;
		}
		int m=l+r>>1;
		build(l,m,ls);
		build(m+1,r,rs);
		a[p].mn=min(a[ls].mn,a[rs].mn);
	}
	void Build(int N)
	{
		n=N;
		build(1,n,1);
	}
	int x,y,v;
	void add(int l,int r,int p)
	{
		pushdown(p,l<r);
		if(x<=l&&r<=y)
		{
			a[p].lazy+=v;
			a[p].mn+=v;
			return;
		}
		int m=l+r>>1;
		if(x<=m)add(l,m,ls);
		if(m<y)add(m+1,r,rs);
		a[p].mn=min(a[ls].mn,a[rs].mn);
	}
	void Add(int X,int Y,int V)
	{
//		cout<<"Add:"<<X<<","<<Y<<" "<<V<<endl;
		x=X;y=Y;v=V;
		add(1,n,1);
	}
	int Querymn(){return a[1].mn;}
}sgt;
int n,A[500111],a[500111],ans[500111];
int pre[500111],nxt[500111];
bool isd[500111];
void linkdel(int x){pre[nxt[x]]=pre[x];nxt[pre[x]]=nxt[x];isd[x]=1;}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
	}
	kotori_sort(a,n);
	for(int i=1;i<=n;i++)
	{
		A[id[i]]=i;
		if(i>1)pre[i]=i-1;
		if(i<n)nxt[i]=i+1;
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;i++)cout<<A[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
	{
		ia[i]=a[i]-i;
	}
	sgt.Build(n);
	int it=1,itp=1;
	for(int i=n;i>=1;i--)
	{
		while(it<=n&&isd[it])it++;
		while(itp+a[it]<=0)
		{
			sgt.Add(it,it,mod);
			sgt.Add(it+1,n,1);
			it=nxt[it];
			itp++;
		}
//		cout<<"i="<<i<<" itp="<<itp<<" it="<<it<<endl;
		if(it>=1&&it<=n)
		{
			int mn=sgt.Querymn();
//			cout<<"mn="<<mn<<" pos="<<min(-(itp-1),mn)<<" "<<i-itp+1<<" "<<itp-1<<endl;
			ans[i]=min(-(itp-1),mn)+i-itp+1;
		}
		else ans[i]=-i;
		int x=A[i];
//		cout<<"delete:"<<x<<endl;
		if(x<it)itp--;
		else
		{
			sgt.Add(x,x,mod);
			sgt.Add(x+1,n,1);
		}
		linkdel(x);
	}
	for(int i=1;i<=n;i++)putsi(ans[i]);
	return 0;
}