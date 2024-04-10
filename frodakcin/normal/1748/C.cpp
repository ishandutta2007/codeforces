#include <cstdio>
#include <map>
#include <vector>

template<typename T> bool ckmin(T &a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T &a, const T& b) {return b>a?a=b,1:0;}

using ll = long long;

void solve()
{
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	for(int i=0;i<n;++i)
		scanf("%d", &a[i]);

	int ans=0;
	ll p=0;
	int i=0;
	for(;i<n;++i)
	{
		if(a[i] == 0)
			break;
		p += a[i];
		if(p == 0)
			++ans;
	}

	std::map<ll, int> map;
	for(;i<n;++i)
	{
		if(a[i] == 0)
		{
			if(!map.empty())
			{
				int max = 0;
				for(auto const& it:map)
					ckmax(max, it.second);
				ans += max;
			}
			map.clear();
			++map[p=0];
		}
		else
		{
			p += a[i];
			++map[p];
		}
	}
	if(!map.empty())
	{
		int max = 0;
		for(auto const& it:map)
			ckmax(max, it.second);
		ans += max;
	}
	printf("%d\n", ans);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}