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

const int N=2.5e6+5;
int n,a[N],sum1[N],sum2[N],sum3[N],sum4[N],tag[N],num[N],now,p1,p2;

pair<int,int> b[N];

vector<pair<int,int> > ve[N];

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		b[i]=mp(a[i],i);
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;++i)
	{
		if(!sum1[b[i].fi])
			sum1[b[i].fi]=i;
		else if(!sum2[b[i].fi])
		{
			sum2[b[i].fi]=i;
			if(!p1) p1=b[i].fi;
			else if(!p2) p2=b[i].fi;
		}
		else if(!sum3[b[i].fi])
			sum3[b[i].fi]=i;
		else if(!sum4[b[i].fi])
		{
			sum4[b[i].fi]=i;
			if(!p1) p1=b[i].fi;
			else if(!p2) p2=b[i].fi;
		}
	}
	if(p1&&p2)
	{
		if(p1==p2) 
		{
			printf("YES\n");
			printf("%d %d %d %d\n",b[sum1[p1]].se,b[sum2[p1]].se,b[sum3[p1]].se,b[sum4[p1]].se);
			return 0;
		}
		printf("YES\n");
		printf("%d %d %d %d\n",b[sum1[p2]].se,b[sum2[p1]].se,b[sum1[p1]].se,b[sum2[p2]].se);
		return 0;
	}
	if(n<=4000)
	{
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				ve[b[j].fi-b[i].fi].push_back(mp(i,j));
		for(int i=1;i<=2500000;++i)
			if(ve[i].size()>=2)
			{
				int j=1;
				while(j<ve[i].size()&&(ve[i][0].fi==ve[i][j].fi||ve[i][0].fi==ve[i][j].se||ve[i][0].se==ve[i][j].fi||ve[i][0].se==ve[i][j].se))
					++j;
				if(j==ve[i].size()) continue;
				printf("YES\n");
				printf("%d %d %d %d\n",b[ve[i][0].fi].se,b[ve[i][j].se].se,b[ve[i][0].se].se,b[ve[i][j].fi].se);
				return 0;
			}
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=2500000;++i)
	{
		p1=p2=0;
		for(int j=1;j<=n&&b[j].fi+i<=2500000;++j)
			if(!tag[j]&&sum1[b[j].fi+i])
			{
				if(tag[sum1[b[j].fi+i]])
				{
					if(sum2[b[j].fi+i]&&!tag[sum2[b[j].fi+i]])
					{
						if(!p1) p1=j,tag[sum1[b[j].fi+i]]=1;
						else if(!p2) p2=j,tag[sum1[b[j].fi+i]]=1;
					}
					continue;
				}
				if(!p1) p1=j,tag[sum1[b[j].fi+i]]=1;
				else if(!p2) p2=j,tag[sum1[b[j].fi+i]]=1;
			}
		if(p1&&p2)
		{
			printf("YES\n");
			printf("%d %d %d %d\n",b[p1].se,b[sum1[b[p2].fi+i]].se,b[p2].se,b[sum1[b[p1].fi+i]].se);
			return 0;
		}
		if(p1) tag[sum1[b[p1].fi+i]]=0;
		if(p2) tag[sum1[b[p2].fi+i]]=0;
	}
	printf("NO\n");
	return 0;
}