#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

void solve(void)
{
	int n;
	scanf("%d",&n);
	vector<int> a, b;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(x >= 0) a.push_back(x);
		else b.push_back(-x);
	}
	
	ll ans = -linf;
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=1; i<=5 && i <= (int)b.size(); i+=2)
	{
		if(5-i > (int)a.size()) continue;
		
		ll res = 1;
		for(int j=0; j<5-i; ++j)
			res *= a[j];
		for(int j=0; j<i; ++j)
			res *= -b[j];
		ans = max(ans, res);
	}
	
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=0; i<=5 && i <= (int)b.size(); i+=2)
	{
		if(5-i > (int)a.size()) continue;
		
		ll res = 1;
		for(int j=0; j<5-i; ++j)
			res *= a[j];
		for(int j=0; j<i; ++j)
			res *= -b[j];
		ans = max(ans, res);
	}
	
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}