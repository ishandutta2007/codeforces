#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;

int a[MAXN], b[MAXM];
int f[MAXN][MAXM];

int suma[MAXN], sumb[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i) suma[i] = suma[i-1] + a[i];
	for(int i=1; i<=m; ++i) sumb[i] = sumb[i-1] + b[i];
	
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=m; ++j)
		{
			f[i][j] = max(0, suma[i] + sumb[j]);
			if(i) f[i][j] = max(f[i][j], f[i-1][j]);
			if(j) f[i][j] = max(f[i][j], f[i][j-1]);
		}
	printf("%d\n",f[n][m]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}