#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXQ = 3e5 + 5;
const int inf = 0x3f3f3f3f;

struct Query
{
	int id,l,r;
	Query(void){}
	Query(int _id,int _l,int _r): id(_id), l(_l), r(_r) {}
};

ll res[MAXQ];

struct Solver
{
	vector<int> a, b;
	vector<Query> qs;
	void solve(void)
	{
		int n = (int)a.size();
		a.push_back(-inf); b.push_back(-inf);
		vector< vector<Query> > f(n), g(n);
		for(Query x: qs) x.r = min(x.r, n - 1), f[x.l].push_back(x);
		
		vector<int> sta(1, n), val(1, -inf);
		for(int i=n-1; i>=0; --i)
		{
			int pos = lower_bound(val.begin(), val.end(), b[i]) - val.begin();
			pos = sta[pos - 1];
			for(Query x: f[i])
			{
				int id = x.id, l = x.l, r = x.r;
				if(pos > r)
				{
					res[id] = (ll)(r - l + 1) * b[i];
					continue;
				}
				res[id] = (ll)(pos - l) * b[i];
				x.l = pos;
				g[pos].push_back(x);
			}
			while(val.back() >= a[i]) val.pop_back(), sta.pop_back();
			sta.push_back(i); val.push_back(a[i]);
		}
		
		sta = vector<int>(1, n);
		val = vector<int>(1, -inf);
		vector<ll> sum(1, 0);
		for(int i=n-1; i>=0; --i)
		{
			while(val.back() >= a[i])
			{
				val.pop_back(); sta.pop_back(); sum.pop_back();
			}
			sum.push_back((ll)a[i] * (sta.back() - i) + sum.back());
			sta.push_back(i); val.push_back(a[i]);
			
			for(Query x: g[i])
			{
				int id = x.id, r = x.r;
				int pos = lower_bound(sta.begin(), sta.end(), r, greater<int>()) - sta.begin();
				res[id] += sum.back() - sum[pos];
				res[id] += (ll)(x.r - sta[pos] + 1) * val[pos];
			}
		}
	}
}slv[MAXN];

int a[MAXN], f[MAXN];

int main(void)
{
	int n,Q,d;
	scanf("%d%d%d",&n,&Q,&d);
	for(int i=0; i<n; ++i) scanf("%d",&a[i]);
	
	deque<int> q;
	for(int i=0; i<n; ++i)
	{
		while(q.size() && q.front() <= i-d) q.pop_front();
		while(q.size() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		f[i] = a[q.front()];
	}
	
	for(int i=0; i<n; ++i)
	{
		int t = i % d;
		slv[t].a.push_back(f[i]);
		slv[t].b.push_back(a[i]);
	}
	
	for(int i=1; i<=Q; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		--l; --r;
		int t = l % d;
		if(r % d < l % d) r -= d;
		l /= d; r /= d;
		slv[t].qs.emplace_back(i, l, r);
	}
	
	for(int i=0; i<d; ++i) slv[i].solve();
	
	for(int i=1; i<=Q; ++i)
		printf("%lld\n",res[i]);
	return 0;
}