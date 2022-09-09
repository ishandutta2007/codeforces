#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;

void solve(void)
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	
	int ans = inf, ansi = -1, ansd;
	
	for(int i=1; i<=y-x; ++i)
		if((y-x)%i == 0)
		{
			int dif = (y-x)/i;
			if(i+1 > n) continue;
			
			int len = min((x-1)/dif, n-(i+1));
			int fir = x - dif * len;
			
			int lst = fir + n * dif;
			if(lst < ans)
			{
				ans = lst;
				ansi = fir;
				ansd = dif;
			}
		}
	for(int i=1; i<=n; ++i)
		printf("%d ",ansi + (i-1) * ansd);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}