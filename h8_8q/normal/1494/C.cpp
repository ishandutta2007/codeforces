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
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
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

const int N=2e5+5;
int t,n,m,p1,p2,a[N],b[N],sum[N],ans1,ans2;

map<int,int> mp;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		ans1=ans2=0;p1=p2=0;
		mp.clear();
		for(int i=1;i<=n;++i)
			a[i]=read(),mp[a[i]]=1;
		for(int i=1;i<=m;++i)
			b[i]=read();
		for(int i=1;i<=m;++i)
			sum[i]=sum[i-1]+mp[b[i]];
		for(int i=1;i<=n;++i)
			if(a[i]<0) p1=i;
			else break;
		for(int i=1;i<=m;++i)
			if(b[i]<0) p2=i;
			else break;
		for(int i=p2;i>=1&&p1!=0;--i)
		{
			int t1=lower_bound(a+1,a+1+n,b[i])-a;
			if(a[t1]>0) continue;
			int t2=upper_bound(b+1,b+1+m,b[i]+(p1-t1))-b-1;
			ans1=max(ans1,t2-i+1+sum[i-1]);
		}
		for(int i=p2+1;i<=m&&p1!=n;++i)
		{
			int t1=upper_bound(a+1,a+1+n,b[i])-a-1;
			if(a[t1]<0) continue;
			int t2=lower_bound(b+1,b+1+m,b[i]-(t1-p1-1))-b;
			ans2=max(ans2,i-t2+1+sum[m]-sum[i]);
		}
		printf("%lld\n",ans1+ans2);
	}
	return 0;
}