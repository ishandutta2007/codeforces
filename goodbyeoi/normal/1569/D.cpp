//AFO countdown:11 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e6+10;
int n,m,k,a[M],b[M],t1[M],t2[M],p[M],X[M],Y[M],cnt[M];
vector<int>v1[M],v2[M],v;

struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void add(int x,int k)
	{
		for (int i=x;i<=1e6;i+=lowbit(i))
			c[i]+=k;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=c[i];
		return res;
	}
	int query(int l,int r){return ask(r)-ask(l-1);}
}T1,T2;

signed main()
{
	WT
	{
		n=read(),m=read(),k=read();
		for (int i=1;i<=n;i++)a[i]=read(),t1[a[i]]=1;
		for (int i=1;i<=m;i++)b[i]=read(),t2[b[i]]=1;
		for (int i=1;i<=k;i++)
		{
			int x=read(),y=read();
			X[i]=x,Y[i]=y;p[i]=0;
			if (t1[x]&&t2[y])continue;
			if (t1[x])p[i]=1,T1.add(y,1),v1[x].pb(y);
			else p[i]=2,T2.add(x,1),v2[y].pb(x);
		}
//		for (int i=1;i<=k;i++)cout<<p[i]<<' ';puts("qwq");
		int res=0;
		for (int i=1;i<n;i++)
		{
			int x=T2.query(a[i]+1,a[i+1]-1);
			res+=x*(x-1)/2;//cout<<x<<' ';
		}
		for (int i=1;i<m;i++)
		{
			int x=T1.query(b[i]+1,b[i+1]-1);
			res+=x*(x-1)/2;//cout<<x<<' ';
		}
		for (int i=1;i<=k;i++)
			if (p[i]==1&&v1[X[i]].size()!=0)
			{
				v.clear();
				for (int j=0;j<v1[X[i]].size();j++)
				{
					int tl=1,tr=m,xx=v1[X[i]][j],p;
					while(tl<=tr)
					{
						int Mid=(tl+tr)>>1;
						if (b[Mid]>=xx)p=Mid,tr=Mid-1;
						else tl=Mid+1;
					}
					res+=cnt[p]*(cnt[p]-1)/2,cnt[p]++;
					res-=cnt[p]*(cnt[p]-1)/2;v.pb(p);
				}
				for (int j=0;j<v.size();j++)cnt[v[j]]=0;
				v1[X[i]].clear();
			}
		for (int i=1;i<=k;i++)
			if (p[i]==2&&v2[Y[i]].size()!=0)
			{
				v.clear();
				for (int j=0;j<v2[Y[i]].size();j++)
				{
					int tl=1,tr=n,xx=v2[Y[i]][j],p;
					while(tl<=tr)
					{
						int Mid=(tl+tr)>>1;
						if (a[Mid]>=xx)p=Mid,tr=Mid-1;
						else tl=Mid+1;
					}
					res+=cnt[p]*(cnt[p]-1)/2,cnt[p]++;
					res-=cnt[p]*(cnt[p]-1)/2;v.pb(p);//cout<<p<<' ';
				}
				for (int j=0;j<v.size();j++)cnt[v[j]]=0;
				v2[Y[i]].clear();
			}
		for (int i=1;i<=n;i++)t1[a[i]]=0;
		for (int i=1;i<=m;i++)t2[b[i]]=0;
		for (int i=1;i<=k;i++)
		{
			if (p[i]==1)T1.add(Y[i],-1);
			if (p[i]==2)T2.add(X[i],-1);
		}cout<<res<<endl;
	}
	return 0;
}