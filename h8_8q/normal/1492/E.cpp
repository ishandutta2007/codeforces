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
#define id(x,y) ((x-1)*m+y)

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

const int N=250005;
int n,m,a[N],b[N];

map<int,int> mp;

void dfs(int u);

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[id(i,j)]=read();
	for(int i=1;i<=m;++i)
	{
		int mx=0;
		mp.clear();
		for(int j=1;j<=n;++j)
		{
			mp[a[id(j,i)]]++;
			if(mp[a[id(j,i)]]>mx)
				mx=mp[a[id(j,i)]],b[i]=a[id(j,i)];
		}
	}
	dfs(1);
	printf("No\n");
	return 0;
}

void dfs(int u)
{
	for(int i=1;i<=n;++i)
	{
		vector<int> v;
		for(int j=1;j<=m;++j)
			if(a[id(i,j)]!=b[j])
				v.push_back(j);
		if(v.size()>2)
		{
			if(v.size()>6-u)
				return;
			for(int j=0;j<v.size();++j)
			{
				int tmp=b[v[j]];
				b[v[j]]=a[id(i,v[j])];
				dfs(u+1);
				b[v[j]]=tmp;
			}
			return;
		}
	}
	printf("Yes\n");
	for(int i=1;i<=m;++i)
		printf("%lld ",b[i]);
	exit(0);
}