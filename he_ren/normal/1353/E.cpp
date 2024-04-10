#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

char s[MAXN];
int a[MAXN],sum[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	for(int i=1; i<=n; ++i)
		a[i] = s[i]-'0';
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	int ans = max(sum[n]-1, 0);
	for(int k=1; k<=d; ++k)
	{
		static int m, b[MAXN];
		static int pre[MAXN][2];
		
		int rem = sum[n];
		
		m=0;
		for(int i=k; i<=n; i+=d)
			b[++m] = a[i],
			rem -= a[i];
		
		for(int i=1; i<=m; ++i)
		{
			pre[i][0] = pre[i-1][0];
			pre[i][1] = pre[i-1][1];
			++pre[i][b[i]];
		}
		
		int res = min(pre[m][0], pre[m][1]);
		
		int mn = 0;
		for(int i=1; i<=m; ++i)
		{
			int tmp = pre[m][1]-pre[i][1];
			chk_min(res, pre[i][0] + mn + tmp);
			chk_min(mn, pre[i][1] - pre[i][0]);
		}
		
		chk_min(ans, rem + res);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}