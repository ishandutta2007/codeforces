#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	map<int, vector<int> > R,C;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			int x;
			scanf("%d",&x);
			R[x].push_back(i);
			C[x].push_back(j);
		}
	}
	
	ll ans = 0;
	auto get = [&] (vector<int> &vec)
	{
		sort(vec.begin(), vec.end());
		ll sum = 0;
		for(int i=0; i<(int)vec.size(); ++i)
		{
			ans += (ll)i * vec[i] - sum;
			sum += vec[i];
		}
	};
	
	for(auto it: R) get(it.second);
	for(auto it: C) get(it.second);
	
	printf("%lld\n",ans);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}