#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

bool can[MAXN];
int a[MAXN];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) can[i] = 1;
	for(int i=1; i<=m; ++i)
	{
		int pos;
		scanf("%d",&pos);
		++pos;
		can[pos] = 0;
	}
	for(int i=1; i<=d; ++i) scanf("%d",&a[i]);
	
	if(!can[1]) return printf("-1"), 0;
	
	static int lst[MAXN];
	for(int i=1; i<=n; ++i)
		lst[i] = can[i]? i: lst[i-1];
	
	ll ans = linf;
	for(int k=1; k<=d; ++k)
	{
		int res = 1, i = 1;
		while(i+k-1 < n)
		{
			if(lst[i+k] <= i){ res=-1; break;}
			++res;
			i = lst[i+k];
		}
		if(res != -1) ans = min(ans, (ll)res * a[k]);
	}
	
	if(ans == linf) printf("-1");
	else printf("%lld",ans);
	return 0;
}