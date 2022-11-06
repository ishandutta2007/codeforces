#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define lowbit(x) (x&(-x))
#define lc (x<<1)
#define rc (x<<1|1)
#define max Max
#define min Min
#define abs Abs

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=3e5+5;
int t,n,a[N],b[N],c[N],d[N],pos[N],st[N][21],vis[N],ppp;

//>=2min{bi+ci-1}-1

//=1bi,ci>1 bi+ci-2  

inline int query(int l,int r);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			vis[i]=0,d[i]=1e18,pos[i]=0;
		for(int i=1;i<=n;++i)
			a[i]=read(),st[i][0]=a[i],vis[a[i]]++;
		for(int j=1;j<=20;++j)
			for(int i=1;i+(1<<j)-1<=n;++i)
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		for(int i=1;i<=n;++i)
		{
			int l=1,r=i;b[i]=1;
			while(l<=r)
			{
				int mid=((l+r)>>1);
				if(query(mid,i)==a[i]) r=mid-1,b[i]=i-mid+1;
				else l=mid+1;
			}
				
			l=i,r=n;c[i]=1;
			while(l<=r)
			{
				int mid=((l+r)>>1);
				if(query(i,mid)==a[i]) l=mid+1,c[i]=mid-i+1;
				else r=mid-1;
			}
				
			d[a[i]]=min(d[a[i]],b[i]+c[i]-1);
			if(pos[a[i]]==0)
				pos[a[i]]=i;
		}
		int flag=1;ppp=0;
		for(int i=1;i<=n;++i)
		{
			if(vis[i]>=2)
			{
				flag=0;
				ppp=max(ppp,d[i]-1);
			}
			else if(vis[i]==1&&b[pos[i]]>1&&c[pos[i]]>1)
				ppp=max(ppp,d[i]-1);
			else if(vis[i]==0)
				ppp=max(ppp,n-i+1);
		}
		printf("%lld",flag);
		for(int i=2;i<=n;++i)
			if(i<=ppp) printf("0");
			else printf("1");
		printf("\n");
	}
	return 0;
}

inline int query(int l,int r)
{
	int k=log2(r-l+1);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}