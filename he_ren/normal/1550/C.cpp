#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	set<pii> s;
	auto chk_ge = [&] (int k)
	{
		vector<int> p;
		auto it = s.end();
		while(p.size() < 3 && it != s.begin() && prev(it) -> first >= k)
			p.push_back((--it) -> second);
		if(p.size() == 3) return false;
		if(p.size() <= 1) return true;
		sort(p.begin(), p.end());
		return a[p[0]] < a[p[1]];
	};
	auto chk_le = [&] (int k)
	{
		vector<int> p;
		auto it = s.begin();
		while(p.size() < 3 && it != s.end() && it -> first <= k)
			p.push_back((it++) -> second);
		if(p.size() == 3) return false;
		if(p.size() <= 1) return true;
		sort(p.begin(), p.end());
		return a[p[0]] > a[p[1]];
	};
	
	ll ans = 0;
	for(int i=1,j=1; i<=n; s.erase(make_pair(a[i], i)), ++i)
	{
		while(j<=n && chk_ge(a[j]) && chk_le(a[j]))
			s.emplace(a[j], j), ++j;
		ans += j-i;
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