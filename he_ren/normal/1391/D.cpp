#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXM = 3 + 2;
const int ALL = (1<<3) + 5;
const int inf = 0x3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

inline int num1(int x)
{
	int res = 0;
	while(x)
		res += (x&1),
		x>>=1;
	return res;
}

bool check(int mask,int i)
{
	return (num1(mask&3)&1) == (i&1) && (num1(mask>>1)&1) == (i>>1);
}

int a[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(min(n,m) >= 4) return printf("-1"), 0;
	if(min(n,m) <= 1) return printf("0"), 0;
	
	for(int i=1; i<=n; ++i)
	{
		static char s[MAXN];
		scanf("%s",s+1);
		for(int j=1; j<=m; ++j)
		{
			if(n >= m) a[i] |= s[j]<<(j-1);
			else a[j] |= s[j]<<(i-1);
		}
	}
	if(n < m) swap(n,m);
	
	if(m == 2)
	{
		int ans = inf;
		for(int k=0; k<=1; ++k)
		{
			int res = 0;
			for(int i=1; i<=n; i+=2)
				if((num1(a[i])&1) != k) ++res;
			for(int i=2; i<=n; i+=2)
				if((num1(a[i])&1) != !k) ++res;
			ans = min(ans, res);
		}
		printf("%d",ans);
		return 0;
	}
	
	int ans = inf;
	for(int k=0; k<=3; ++k)
	{
		int res = 0;
		for(int i=1; i<=n; i+=2)
			if(!check(a[i], k)) ++res;
		for(int i=2; i<=n; i+=2)
			if(!check(a[i], 3^k)) ++res;
		ans = min(ans, res);
	}
	printf("%d",ans);
	return 0;
}