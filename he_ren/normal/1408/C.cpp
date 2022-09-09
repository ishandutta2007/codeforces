#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ldb;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	a[0] = 0; a[n+1] = l;
	
	int x = 1, y = n;
	int sx = 1, sy = 1;
	
	ldb cx = 0, cy = l, ans = 0;
	
	while(x <= y)
	{
		ldb tx = (a[x] - cx) / sx;
		ldb ty = (cy - a[y]) / sy;
		ans += min(tx,ty);
		
		if(tx < ty)
		{
			++x;
			cx += tx * sx;
			cy -= tx * sy;
			++sx;
		}
		else
		{
			--y;
			cx += ty * sx;
			cy -= ty * sy;
			++sy;
		}
	}
	ans += (cy - cx) / (sx + sy);
	
	printf("%.20lf\n",(double)ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}