//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
const int maxn = 2011;
int n;
int a[maxn];
int g[maxn];
int ans[maxn][maxn];
vector<int> gr[maxn*2];
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	for (int i=0; i<=n; i++) g[i] = 0;
	memset(ans, -1, sizeof(ans));
	for (int i=1; i<=n; i++)
	{
		int cnt0 = n+1-a[i], cnt1 = a[i];
		for (int j=0; j<=2*n; j++) gr[j].clear();
		for (int j=0; j<=n; j++) gr[g[j]].PB(j);
		for (int j=0; j<=n; j++)
		{
			if (gr[j].size()>1)
			{
//				cerr<<"j="<<j<<endl;
				ans[i][gr[j][0]] = 0;
				ans[i][gr[j][1]] = 1;
				cnt0--;
				cnt1--;
				break;
			}
		}
		for (int j=0; j<=n; j++)
		{
			if (ans[i][j]==-1)
			{
				if (cnt0>0) cnt0--, ans[i][j] = 0;
				else cnt1--, ans[i][j] = 1;
			}
		}
		assert(cnt0==0&&cnt1==0);
		vector<pair<int,int> > v;
		for (int j=0; j<=n; j++)
		{
			v.PB(MP(g[j]+ans[i][j]*n, j));
		}
		sort(v.begin(), v.end());
		int t = 0;
		for (int j=0; j<=n; j++)
		{
			if (j>0) t += v[j].FF!=v[j-1].FF;
			g[v[j].SS] = t;
		}
	}
	printf("%d\n", n+1);
	for (int i=0; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			putchar(ans[j][i]+'0');
		}
		puts("");
	}
	return 0;
}