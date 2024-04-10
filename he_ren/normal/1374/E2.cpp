#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct First_K_Container
{
	multiset<pii> lef, rig;
	ll sum;
	inline void insert(pii x)
	{
		if(rig.size() && x >= *rig.begin())
			rig.insert(x);
		else
			lef.insert(x), sum += x.first;
	}
	inline ll get(int k)
	{
		if(k < 0) return linf;
		while((int)lef.size() > k)
		{
			auto it = prev(lef.end());
			sum -= it -> first;
			rig.insert(*it); lef.erase(it);
		}
		while(rig.size() && (int)lef.size() < k)
		{
			auto it = rig.begin();
			sum += it -> first;
			lef.insert(*it); rig.erase(it);
		}
		return (int)lef.size() == k? sum: linf;
	}
}dat;

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	vector<pii> p[2][2];
	for(int i=1; i<=n; ++i)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		p[x][y].emplace_back(t, i);
	}
	
	for(int i=0; i<=1; ++i)
		for(int j=0; j<=1; ++j)
			sort(p[i][j].begin(), p[i][j].end());
	
	pair<ll,int> ans = {linf, -1};
	
	for(pii x: p[0][0]) dat.insert(x);
	vector<pii> lef = p[1][0], rig = p[0][1];
	
	ll lsum = 0, rsum = 0;
	for(pii x: lef) lsum += x.first;
	for(pii x: rig) rsum += x.first;
	
	ll sum = 0;
	for(int i=0; i<=(int)p[1][1].size(); ++i)
	{
		while(lef.size() && (int)lef.size() + i > d)
		{
			lsum -= lef.back().first;
			dat.insert(lef.back()); lef.pop_back();
		}
		while(rig.size() && (int)rig.size() + i > d)
		{
			rsum -= rig.back().first;
			dat.insert(rig.back()); rig.pop_back();
		}
		
		if((int)lef.size() + i >= d && (int)rig.size() + i >= d)
		{
			int rem = m - i - (int)lef.size() - (int)rig.size();
			if(rem >= 0)
				ans = min(ans, {sum + lsum + rsum + dat.get(rem), i});
		}
		
		if(i<(int)p[1][1].size()) sum += p[1][1][i].first;
	}
	
	if(ans.first == linf)
	{
		printf("-1");
		return 0;
	}
	
	{
		int t = max(0, d - (int)ans.second);
		
		vector<pii> vec = p[0][0];
		for(int i=t; i<(int)p[1][0].size(); ++i) vec.push_back(p[1][0][i]);
		for(int i=t; i<(int)p[0][1].size(); ++i) vec.push_back(p[0][1][i]);
		sort(vec.begin(), vec.end());
		
		vector<pii> res = p[1][1];
		res.resize(ans.second);
		for(int i=0; i<t; ++i)
		{
			res.push_back(p[1][0][i]);
			res.push_back(p[0][1][i]);
		}
		
		vec.resize(m - (int)res.size());
		for(pii x: vec) res.push_back(x);
		
		vector<int> id;
		for(pii x: res) id.push_back(x.second);
		sort(id.begin(), id.end());
		
		printf("%lld\n",ans.first);
		for(int x: id) printf("%d ",x);
	}
	return 0;
}