#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <deque>

using ll = long long;

const int MN = 3e4+10;
const int MC = 5;
const int MQ = 3e5+10;

int N, C, Q, p[MN];
ll ways[MN][MC];

void precmp()
{
	for(int i=0;i<MN;++i) ways[i][0]=1;
	for(int i=0;i<MN;++i)
	{
		ll v=(i>0); // exception for i = 0
		for(int j=1;j<MC;++j)
		{
			v *= i-j;
			v /= j;
			ways[i][j] = ways[i][j-1]+v; // sum (i-1 choose k), k <= j
		}
	}
	//printf("%lld\n", ways[MN-1][MC-1]);
}

struct Action
{
	public:
		int l, c;
		ll k;
};

struct Op
{
	public:
		int l, r; // both inclusive
};

struct Qry
{
	public:
		int id, l;
		ll k;
};

struct Qry2
{
	public:
		int id;
		ll k;
		bool operator < (const Qry2& o) const {return k < o.k;}
};

void solve()
{
	scanf("%d%d%d", &N, &C, &Q);
	for(int i=0;i<N;++i) scanf("%d", p+i);
	std::vector<std::vector<Op> > f(Q);
	std::vector<int> ans(Q), val(Q);
	std::vector<std::vector<Qry> > q(MC);

	for(int i=0;i<Q;++i)
	{
		ll v;
		scanf("%d%lld", &val[i], &v), --v, --val[i];
		if(v >= ways[N][C]) ans[i]=-1;
		else
			q[C].push_back({i, 0, v});
	}

	for(int c=C;c>0;--c)
	{
		//Build table
		std::deque<Action> dq;
		dq.push_back({N, 0, 1ll});
		for(int i=N-1;i>=0;--i)
		{
			std::vector<Action> add;
			for(int j=1;j<=c && i+j < N;++j)
				add.push_back({i, j, ways[N-(i+j)-1][c-j]});
			std::sort(add.begin(), add.end(), [&](const Action& u, const Action& v){return std::abs(p[i+u.c]-p[i]) < std::abs(p[i+v.c]-p[i]);});
			for(const Action& x : add)
				if(p[i+x.c] < p[i])
					dq.push_front(x);
				else
					dq.push_back(x);
		}

		//Handle the fact that starting positions can be offset
		std::vector<ll> pfx(1, 0);
		for(auto it=dq.begin();it != dq.end();++it)
		{
			if(pfx.size() > it->l+2) break;
			while((int)pfx.size() <= it->l+1) pfx.push_back(pfx.back());
			pfx.back() += it->k;
		}
		std::vector<Qry2> qs;
		for(auto x:q[c])
			qs.push_back({x.id, x.k+pfx[x.l]});
		std::sort(qs.begin(), qs.end());

		//Transition all of the queries
		{
			ll pv=0; // note: it's important to not use pfx here
			auto it=dq.begin();
			for(auto x:qs)
			{
				for(;pv+it->k <= x.k;assert(it!=dq.end())) pv+=it++->k;
				f[x.id].push_back({it->l, it->l+it->c});
				x.k -= pv;
				q[c-it->c].push_back({x.id, it->l+it->c+1, x.k});
			}
		}
	}

	for(int i=0;i<Q;++i)
		if(ans[i] != -1)
		{
			ans[i] = p[val[i]];
			for(auto x:f[i])
				if(x.l <= val[i] && val[i] <= x.r)
					ans[i] = p[x.r+x.l-val[i]];
		}

	for(int i=0;i<Q;++i)
		printf("%d\n", ans[i]);
}

int main()
{
	precmp();
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}