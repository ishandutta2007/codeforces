#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];
int sum[MAXN], mn[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 0;
	for(int x=-30; x<=30; ++x)
	{
		int tmp=-inf;
		for(int i=1, j=1; i<=n; i=j)
		{
			while(j<=n && (a[j]<=x) == (a[i]<=x)) ++j;
			if(a[i]>x) continue;
			
			sum[i-1] = mn[i-1] = 0;
			for(int k=i; k<j; ++k)
				sum[k] = sum[k-1] + a[k];
			for(int k=i; k<j; ++k)
				mn[k] = min(mn[k-1], sum[k]);
			
			int lst = -1;
			for(int k=i; k<j; ++k)
			{
				if(a[k]==x) lst=k;
				
				if(lst!=-1) chk_max(tmp, sum[k]-mn[lst-1]);
			}
		}
		chk_max(ans, tmp - x);
	}
	printf("%d",ans);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}