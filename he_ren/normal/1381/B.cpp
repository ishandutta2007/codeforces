#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int MAXM = MAXN * 2;

int p[MAXM];

void solve(void)
{
	int n;
	scanf("%d",&n);
	int m = n*2;
	for(int i=1; i<=m; ++i) scanf("%d",&p[i]);
	
	static vector<int> a;
	a.clear();
	for(int i=1,j=1; i<=m; i=j)
	{
		int mx = p[i];
		while(j<=m && mx>=p[j])
		{
			mx = max(mx, p[j]);
			++j;
		}
		a.push_back(j-i);
	}
	
	static bool f[MAXM][MAXN];
	
	for(int i=0; i<=m; ++i)
		for(int j=0; j<=n; ++j)
			f[i][j] = 0;
	
	f[0][0] = 1;
	for(int i=1; i<=(int)a.size(); ++i)
	{
		for(int j=0; j<=n; ++j)
		{
			f[i][j] = f[i-1][j];
			if(j >= a[i-1]) f[i][j] |= f[i-1][j - a[i-1]];
		}
	}
	if(f[(int)a.size()][n]) printf("Yes\n");
	else printf("No\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}