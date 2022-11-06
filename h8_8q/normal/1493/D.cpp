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

const int N=2e5+5,mod=1e9+7;
int n,m,q,a[N],sum[N],now[N],ok[N],nnum[N],ans=1;

map<int,int> mp[N];
multiset<int> num[N];

signed main()
{
	n=read();q=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		int tmp=a[i];
		for(int j=2;j*j<=tmp;++j)
			while(tmp%j==0)
			{
				if(mp[i][j]==0) nnum[j]++;
				else num[j].erase(num[j].find(mp[i][j]));
				mp[i][j]++;
				num[j].insert(mp[i][j]);
				while(nnum[j]==n&&now[j]<*num[j].begin())
					ans*=j,ans%=mod,now[j]++;
				tmp/=j;
			}
		if(tmp!=1)
		{
			if(mp[i][tmp]==0) nnum[tmp]++;
			else num[tmp].erase(num[tmp].find(mp[i][tmp]));
			mp[i][tmp]++;
			num[tmp].insert(mp[i][tmp]);
			while(nnum[tmp]==n&&now[tmp]<*num[tmp].begin())
				ans*=tmp,ans%=mod,now[tmp]++;
		}
	}
	while(q--)
	{
		int x=read(),y=read();
		for(int i=2;i*i<=y;++i)
			while(y%i==0)
			{
				if(mp[x][i]==0) nnum[i]++;
				else num[i].erase(num[i].find(mp[x][i]));
				mp[x][i]++;
				num[i].insert(mp[x][i]);
				while(nnum[i]==n&&now[i]<*num[i].begin())
					ans*=i,ans%=mod,now[i]++;	
				y/=i;
			}
		if(y!=1)
		{
			if(mp[x][y]==0) nnum[y]++;
			else num[y].erase(num[y].find(mp[x][y]));
			mp[x][y]++;
			num[y].insert(mp[x][y]);
			while(nnum[y]==n&&now[y]<*num[y].begin())
				ans*=y,ans%=mod,now[y]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}