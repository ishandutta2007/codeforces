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
int t,n,m,k,sum[N],ans[N],num[N];

vector<int> v[N],vv[N],vvv[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=m;++i)
		{
			k=read();
			for(int j=1;j<=k;++j)
			{
				int p=read();
				v[p].push_back(i);
				vvv[i].push_back(p);
				if(k==1)
				{
					sum[p]++;
					vv[p].push_back(i);
				}
				num[p]++;
			}
		}
		int fl=1,ok=0,mx=(int)ceil(m/2.0);
		for(int i=1;i<=n;++i)
			if(num[i]>=mx)
			{
				fl=0;
				if(sum[i]<=mx)
				{
					int tmp=0;
					for(int j=0;j<vv[i].size();++j)
						ans[vv[i][j]]=i,tmp++;
					for(int j=0;j<=v[i].size()&&tmp<mx;++j)
						if(!ans[v[i][j]]) ans[v[i][j]]=i,tmp++;
					for(int j=1;j<=m;++j)
						if(!ans[j])
						{
							if(vvv[j][0]==i)
								ans[j]=vvv[j][1];
							else ans[j]=vvv[j][0];
						}
					ok=1;break;
				}
			}
		if(!ok)
		{
			if(fl)
			{
				for(int i=1;i<=m;++i)
					ans[i]=vvv[i][0];
				ok=1;
			}
			else printf("NO\n");
		}
		if(ok)
		{
			printf("YES\n");
			for(int i=1;i<=m;++i)
				printf("%lld ",ans[i]);
			printf("\n");
		}
		for(int i=1;i<=n;++i)
		{
			sum[i]=0,num[i]=0;
			v[i].clear();
			vv[i].clear();
		}
		for(int i=1;i<=m;++i)
			ans[i]=0,vvv[i].clear();
	}
	return 0;
}