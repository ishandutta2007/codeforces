#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	while(n>=1 && a[n] == n) --n;
	
	ldb ans = 1;
	for(int i=1; i<=m; ++i)
	{
		int r;
		db p;
		scanf("%d%lf",&r,&p);
		if(r >= n) ans *= (1 - p);
	}
	
	if(!n) printf("1\n");
	else printf("%.20lf\n",(db)(1 - ans));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}