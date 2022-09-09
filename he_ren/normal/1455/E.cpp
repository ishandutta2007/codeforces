#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n = 4;
pii p[10];

inline ll get_ans(void)
{
	ll res = (ll)abs(p[1].first) + abs(p[1].second) + abs(p[2].first) + abs(p[3].second);
	
	static int a[10];
	a[1] = p[2].second; a[2] = p[3].first; a[3] = p[4].first; a[4] = p[4].second;
	
	sort(a+1,a+4+1);
	int len = a[2];
	
	res += (ll)(len - a[2]) + (len - a[1]) + (a[3] - len) + (a[4] - len);
	return res;
}

void solve(void)
{
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+n+1);
	
	ll ans = linf;
	do
	{
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
			{
				int x = p[i].first, y = p[j].second;
				for(int k=1; k<=n; ++k)
					p[k].first -= x, p[k].second -= y;
				
				ans = min(ans, get_ans());
				for(int k=1; k<=n; ++k) p[k].first = -p[k].first;
				ans = min(ans, get_ans());
				
				for(int k=1; k<=n; ++k)
					p[k].first = -p[k].first + x,
					p[k].second += y;
			}
	}while(next_permutation(p+1,p+n+1));
	
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}