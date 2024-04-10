#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[MAXN];
ll sum[MAXN];

void solve(void)
{
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sum[n+1] = -linf;
	for(int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];
	
	int ans = 0;
	int ansl = -1, ansr = -1;
	
	vector<int> sta(1, n+1);
	vector<ll> val(1, sum[n+1]);
	for(int i=n; i>=1; --i)
	{
		while(sta.size() && sum[i] <= sum[sta.back()]) sta.pop_back();
		val.resize(sta.size());
		sta.push_back(i);
		val.push_back(sum[i]);
		
		// sum[r] - sum[l-1] < -s
		ll need = sum[i-1] - s;
		int pos = lower_bound(val.begin(), val.end(), need) - val.begin() - 1;
		int cur = sta[pos] - 1 - i + 1;
		
		if(cur > ans)
		{
			ans = cur;
			ansl = i; ansr = sta[pos] - 1;
		}
	}
	
	if(ans != 0)
		printf("%d %d\n",ansl,ansr);
	else
		printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}