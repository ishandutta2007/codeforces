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
struct SGT
{
	int a[800111],mn[800111];
	#define ls p<<1
	#define rs p<<1|1
	SGT(){memset(a,127,sizeof(a));memset(mn,0,sizeof(mn));}
	void change(int x,int v,int l,int r,int p=1)
	{
		if(x==l&&x==r)
		{
			mn[p]=l;
			a[p]=v;
			return;
		}
		int m=l+r>>1;
		if(x<=m)change(x,v,l,m,ls);
		else change(x,v,m+1,r,rs);
		if(a[ls]<a[rs])mn[p]=mn[ls],a[p]=a[ls];
		else mn[p]=mn[rs],a[p]=a[rs];
	}
	pair<int,int> query(int x,int y,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)return MP(a[p],mn[p]);
		int m=l+r>>1;
		if(x<=m&&m<y)
		{
			pair<int,int> la=query(x,y,l,m,ls),ra=query(x,y,m+1,r,rs);
			if(la.FF<ra.FF)return la;else return ra;
		}
		else if(x<=m)return query(x,y,l,m,ls);
		else return query(x,y,m+1,r,rs);
	}
}a;
int h,w,n;
int row[100111],cl[100111],cr[100111],lim[100111];
vector<int>v;
ll cnt[100111];
int f[100111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void un(int x)
{
	int y=x+1;
	x=gf(x);
	y=gf(y);
	f[x]=y;
}
int tot,nxt[200111],head[200111],id[200111];
pair<int,int> pp[100111];
void add(int x,int i)
{
//	cout<<"add:"<<x<<" "<<i<<endl;
	tot++;
	nxt[tot]=head[x];
	head[x]=tot;
	id[tot]=i;
	a.change(x,row[i],1,w);
}
int main()
{
	getii(h,w);
	geti(n);
	for(int i=1;i<=n;i++)
	{
		getiii(row[i],cl[i],cr[i]);
		geti(lim[i]);
		lim[i]+=row[i];
		pp[i]=MP(row[i],i);
	}
	sort(pp+1,pp+n+1);
	for(int i=1;i<=w+1;i++)f[i]=i;
	row[0]=0;lim[0]=Imx;
	cl[0]=1;cr[0]=w;
	ll ans=0;
	for(int t=n;t>=0;t--)
	{
		int i=pp[t].SS;
//		cout<<"i="<<i<<endl;
		if(lim[i]>h)
		{
			for(int j=gf(cl[i]);j<=cr[i];j=gf(j))
			{
				un(j);
				cnt[i]++;
			}
		}
//		cout<<"cnt[i]="<<cnt[i]<<endl;
		while(true)
		{
			int x=a.query(cl[i],cr[i],1,w).SS,v=head[x];
//			cout<<"x="<<x<<" find:"<<v<<" "<<id[v]<<" "<<nxt[v]<<endl;
			if(!v||row[id[v]]>lim[i])break;
			cnt[i]+=cnt[id[v]];
			head[x]=nxt[v];
			if(id[head[x]])a.change(x,row[id[head[x]]],1,w);
			else a.change(x,Imx,1,w);
		}
		cnt[i]%=mod;
//		cout<<"cnt[i]="<<cnt[i]<<endl;
		if(i==0)break;
		if(cl[i]==1)add(cr[i]+1,i);else add(cl[i]-1,i);
		if(cr[i]==w)add(cl[i]-1,i);else add(cr[i]+1,i);
	}
	cout<<cnt[0]<<endl;
	return 0;
}