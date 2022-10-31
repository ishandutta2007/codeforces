#include<cstdio>
#include<cstring>
#include<vector>
#define lowbit(x) ((x)&(-x))
const int N=100005;
typedef long long ll;
int a[N];
std::vector<int> pos[N];
int cnt[N];
struct BIT{
	int c[N],n;
	inline void add(int x,const int &C){for(;x<=n;x+=lowbit(x))c[x]+=C;}
	inline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
int main()
{
// 	freopen("memset.in","r",stdin);
// 	freopen("memset.out","w",stdout);
	int n;
	scanf("%d",&n);
	a[0]=n+1;
	a[n+1]=n+1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	tr.n=n+1;
	for(int i=1;i<=n;++i)
	{
		cnt[i]=1-(a[i-1]<=a[i])-(a[i+1]<a[i]);
		tr.add(a[i],(cnt[i])*(n-a[i]+1));
	}
	ll ans=0;
	for(int l=1;l<=n;++l)
	{
		ans+=tr.sum(n)-tr.sum(l-1);
		for(int i=0;i<(int)pos[l].size();++i)
		{
			tr.add(a[pos[l][i]+1],(n-a[pos[l][i]+1]+1));
			tr.add(a[pos[l][i]-1],(n-a[pos[l][i]-1]+1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}