#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

ll calc(vector<int> &a)
{
	ll sum = 0, mn = 0, res = 0;
	for(int i=0; i<(int)a.size(); ++i)
	{
		sum += a[i];
		mn = min(mn, sum);
		res = max(res, sum - mn);
	}
	return res;
}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i) scanf("%d",&a[i]);
	
	ll sum = 0;
	for(int i=0; i<n; i+=2) sum += a[i];
	
	ll ans = sum;
	
	vector<int> dif;
	for(int i=1; i<n; i+=2) dif.push_back(a[i] - a[i-1]);
	ans = max(ans, sum + calc(dif));
	
	dif.clear();
	for(int i=1; i+1<n; i+=2) dif.push_back(a[i] - a[i+1]);
	ans = max(ans, sum + calc(dif));
	
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}