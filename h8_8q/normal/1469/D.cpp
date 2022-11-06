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
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

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
int t,n,a[N];

vector<pair<int,int> > vec;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();vec.clear();
		for(int i=1;i<=n;++i) a[i]=i;
		for(int i=n-1;i>=3;--i)
		{
			if((int)ceil((a[n]+0.0)/a[i])>=a[i])
				a[n]=(int)ceil((a[n]+0.0)/a[i]),vec.push_back(mp(n,i));
			a[i]=(int)ceil((a[i]+0.0)/a[n]),vec.push_back(mp(i,n));
		}
		while(a[n]!=1)
		{
			a[n]=(int)ceil((a[n]+0.0)/a[2]);
			vec.push_back(mp(n,2));
		}
		printf("%lld\n",vec.size());
		for(int i=0;i<vec.size();++i)
			printf("%lld %lld\n",vec[i].fi,vec[i].se);
	}
	return 0;
}