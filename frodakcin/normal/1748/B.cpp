#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>

auto ckmin(auto &a, const auto& b) {return b<a?a=b,1:0;}
auto ckmax(auto &a, const auto& b) {return b>a?a=b,1:0;}

using ll = long long;

const int MN = 1e5+10;
char s[MN];

void solve()
{
	int n;
	scanf("%d", &n);
	std::vector<int> nx[10];
	std::vector<char> a(n);
	scanf(" %s", s);
	for(int i=0;i<n;++i)
		a[i] = s[i] - '0';
	for(int i=0;i<10;++i)
		nx[i].assign(n+1, -1);

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<10;++j)
			nx[j][i+1] = nx[j][i];
		nx[a[i]][i+1] = i;
	}

	int prev[10]; // <= prev
	int max[10]; // >= max
	ll ans=0;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<10;++j)
			prev[j] = nx[j][i];
		std::sort(prev, prev+10, std::greater<int>());

		memset(max, -1, sizeof max);
		for(int j=0;j<10;++j)
		{
			int v=nx[j][i];
			for(int k=1;k<=10;++k)
			{
				if(v != -1)
					v = nx[j][v];
				ckmax(max[k-1], v);
			}
		}

		for(int j=0;j<10;++j)
		{
			int k = max[j];
			if(j+1<10)
				ckmax(k, prev[j+1]);
			//printf("%d %d %d\n", i, prev[j], k);
			if(k<prev[j])
				ans += prev[j]-k;
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;++i)
		solve();
	return 0;
}