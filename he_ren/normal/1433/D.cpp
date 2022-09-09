#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;

pii a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].first),
		a[i].second = i;
	
	bool flag = 1;
	for(int i=2; i<=n; ++i)
		if(a[i].first != a[i-1].first)
		{
			flag = 0;
			break;
		}
	if(flag){ printf("NO\n"); return;}
	printf("YES\n");
	
	sort(a+1,a+n+1);
	
	int lst = -1;
	for(int i=1; i<=n; ++i)
		if(a[i].first != a[1].first)
		{
			printf("%d %d\n",a[i].second,a[1].second),
			lst = a[i].second;
		}
	
	for(int i=2; i<=n; ++i)
		if(a[i].first == a[1].first)
			printf("%d %d\n",a[i].second,lst);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}