#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5,M=205;
int t,n,q,a[N],b[N],m,nm[N];

vector<int> sm[M];
multiset<int> hv;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();q=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		m=0;int tmp=n;
		for(int i=2;i*i<=n;++i)
			if(tmp%i==0)
			{
				b[++m]=n/i;
				while(tmp%i==0)
					tmp/=i;
			}
		if(tmp!=1) b[++m]=n/tmp;
		sort(b+1,b+1+m);
		hv.clear();
		for(int i=1;i<=m;++i)
		{
			sm[i].clear();
			for(int j=0;j<b[i];++j)
				nm[j]=0;
			for(int j=1;j<=n;++j)
				nm[j%b[i]]+=a[j];
			for(int j=0;j<b[i];++j)
			{
				sm[i].push_back(nm[j]);
				hv.insert(nm[j]*b[i]);
			}
		}
		write(*prev(hv.end()));puts("");
		while(q--)
		{
			int x=read(),v=read();
			for(int i=1;i<=m;++i)
			{
				hv.erase(hv.find(sm[i][x%b[i]]*b[i]));
				sm[i][x%b[i]]-=a[x]-v;
				hv.insert(sm[i][x%b[i]]*b[i]);
			}
			a[x]=v;
			write(*prev(hv.end()));puts("");
		}
	}
	return 0;
}