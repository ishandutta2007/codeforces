#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN][MAXM], b[MAXM];
int id[MAXM];

inline bool cmp(int x,int y){ return b[x] > b[y];}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	
	for(int i=1; i<=m; ++i) b[i] = inf, id[i] = i;
	for(int i=1; i<=n; ++i, putchar('\n'))
	{
		sort(a[i]+1,a[i]+m+1);
		sort(id+1,id+m+1,cmp);
		
		static int tmp[MAXM];
		for(int j=1; j<=m; ++j)
			tmp[id[j]] = a[i][j];
		for(int j=1; j<=m; ++j)
			a[i][j] = tmp[j];
		
		for(int j=1; j<=m; ++j) printf("%d ",a[i][j]);
		for(int j=1; j<=m; ++j)
			b[j] = min(b[j], a[i][j]);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}