#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 5e3 + 5;
const int MAXQ = 5e3 + 5;
const int inf = 0x3f3f3f3f;

int l[MAXQ], r[MAXQ];
int dif[MAXN], sum[MAXN];

int main(void)
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=q; ++i)
		scanf("%d%d",&l[i],&r[i]);
	
	int ans = 0;
	for(int k=1; k<=q; ++k)
	{
		for(int i=1; i<=n; ++i) dif[i] = 0;
		
		for(int i=1; i<=q; ++i) if(i!=k)
			++dif[l[i]], --dif[r[i]+1];
		
		for(int i=1; i<=n; ++i)
			dif[i] += dif[i-1];
		
		for(int i=1; i<=n; ++i)
			sum[i] = sum[i-1] + (dif[i]==1);
		
		int res = 0;
		for(int i=1; i<=n; ++i)
			res += (dif[i]>0);
		
		int mn = inf;
		for(int i=1; i<=q; ++i) if(i!=k)
			mn = min(mn, sum[r[i]] - sum[l[i]-1]);
		
		ans = max(ans, res-mn);
	}
	printf("%d",ans);
	return 0;
}