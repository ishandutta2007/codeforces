#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 35 + 5;
const int MAXS = 1<<(MAXN>>1);

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int n,m,a[MAXN],f[MAXS],fcnt=0,g[MAXS],gcnt=0;
#define bit(s,x) (((s)>>(x))&1)

inline void add(int &a,int b){ a+=b; if(a>=m) a-=m;}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), a[i]%=m;
	
	int l1=(n+1)>>1, maxs=1<<l1;
	for(int s=0; s<maxs; ++s)
	{
		int sum=0;
		for(int i=1; i<=l1; ++i)
			if(bit(s, i-1)) add(sum, a[i]);
		f[++fcnt]=sum;
	}
	sort(f+1,f+fcnt+1);
	
	int l2=n>>1, maxt=1<<l2;
	for(int t=0; t<maxt; ++t)
	{
		int sum=0;
		for(int i=l1+1; i<=n; ++i)
			if(bit(t, i-l1-1)) add(sum, a[i]);
		g[++gcnt]=sum;
	}
	sort(g+1,g+gcnt+1);
	
	int ans=0;
	for(int i=1; i<=fcnt; ++i)
	{
		int x=lower_bound(g+1,g+gcnt+1,m-f[i])-g-1;
		chk_max(ans, f[i]+g[x]);
	}
	printf("%d",ans);
	return 0;
}