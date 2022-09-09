#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e3 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN], f[MAXN][MAXN], tag[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=n; ++j) f[i][j] = -inf;
	for(int i=0; i<=n; ++i) tag[i] = 0;
	
	int cnt = 0;
	f[0][1] = 0;
	for(int i=1; i<=n; ++i) if(a[i])
	{
		++cnt;
		for(int j=i+a[i]; j<=n; ++j) ++tag[j];
		
		int mx = 0;
		for(int j=i; j<i+a[i]; ++j)
		{
			mx = max(mx, f[i-1][j] + tag[i-1] + 1);
			f[j][i+a[i]] = max(f[j][i+a[i]], mx - tag[j]);
		}
		for(int j=1; j<=n; ++j)
			f[j][i+a[i]] = max(f[j][i+a[i]], f[j-1][i+a[i]] + tag[j-1] - tag[j]);
	}
	
	printf("%d\n",cnt - f[n-1][n] - tag[n-1]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}