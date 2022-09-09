#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 8e5 + 50;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll g[MAXN], c[MAXN], dis[MAXN], beg[MAXN];
vector<pii> segs[MAXN];

int dsc[MAXN], dcnt = 0;

int main(void)
{
	int n; ll d;
	scanf("%d%lld",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%lld%lld",&g[i],&c[i]);
	for(int i=1; i<n; ++i)
		scanf("%lld",&dis[i]);
	
	{
		ll cur = 0;
		for(int i=1; i<=n; ++i)
		{
			c[i] = (c[i] + cur) % d;
			cur = (cur + dis[i]) % d;
			beg[i] = (d - c[i]) % d;
		}
	}
	
	for(int i=1; i<=n; ++i)
	{
		int l = (d - c[i]) % d;
		int r = (g[i] + d - c[i]) % d;
		if(r == 0) r = d;
		
		if(l < r)
			segs[i].emplace_back(l, r);
		else
			segs[i].emplace_back(0, r), segs[i].emplace_back(l, d);
		
		for(auto t: segs[i])
			dsc[++dcnt] = t.first, dsc[++dcnt] = t.second - 1;
	}
	
	dsc[++dcnt] = 0;
	dsc[++dcnt] = d;
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	
	static vector<int> eff[MAXN][2];
	for(int i=1; i<=n; ++i)
		for(auto t: segs[i])
		{
			int l = t.first, r = t.second;
			l = lower_bound(dsc+1,dsc+dcnt+1,l) - dsc;
			r = lower_bound(dsc+1,dsc+dcnt+1,r) - dsc;
			if(l >= r) continue;
			
			eff[l][1].emplace_back(i);
			eff[r][0].emplace_back(i);
		}
	
	set<int> q;
	for(int i=1; i<=n+1; ++i)
		q.emplace(i);
	
	static pair<int,ll> f[MAXN], to[MAXN];
	for(int k=1; k<dcnt; ++k)
	{
		for(auto i: eff[k][0])
			q.emplace(i);
		for(auto i: eff[k][1])
			q.erase(i);
		
		auto calc = [&] (int i) -> pair<int,ll>
		{
			int j = *q.lower_bound(i);
			if(j > n) return {j, 0};
			else return {j, (beg[j] - dsc[k] + d) % d};
		};
		
		for(auto i: eff[k][1])
			if(dsc[k] == beg[i])
				to[i] = calc(i);
		f[k] = calc(1);
	}
	
	for(int i=n; i>=1; --i)
		to[i].second += to[to[i].first].second;
	
	ll ans = linf;
	for(int i=1; i<dcnt; ++i)
	{
		f[i].second += to[f[i].first].second;
		ans = min(ans, f[i].second);
	}
	
	for(int i=1; i<n; ++i)
		ans += dis[i];
	printf("%lld\n",ans);
	return 0;
}