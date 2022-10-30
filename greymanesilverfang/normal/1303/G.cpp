#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>
#include <vector>
const int N = 2e5;
bool chk[N];
int a[N], sz[N];
long long len[N], sum[N], pre[N], suf[N];
std::vector<int> adj[N];

void dfs_sz(int u, int p = 0)
{
	sz[u] = 1;
	for (int v : adj[u])
		if (!chk[v] && v != p)
		{
			dfs_sz(v, u);
			sz[u] += sz[v];
		}
}

void centroid(int &u)
{
	dfs_sz(u);
	int target = sz[u] / 2;
	while (true)
	{
		down:
		for (int v : adj[u])
			if (!chk[v] && sz[v] < sz[u] && sz[v] > target)
			{
				u = v;
				goto down;
			}
		break;
	}
}

struct data
{
#define pll std::pair<long long,long long>
	std::vector<pll> *query, *hull;
	long long root, ans;
	data(int root)
	{
		query = new std::vector<pll>();
		hull = new std::vector<pll>();
		this->root = root;
		this->ans = root;
	}
	data(const data& other) : data(other.root)
	{
		query->insert(query->begin(), other.query->begin(), other.query->end());
		hull->insert(hull->begin(), other.hull->begin(), other.hull->end());
		ans = other.ans;
	}
	~data()
	{
		delete query;
		delete hull;
	}
	bool ccw(const pll &a, const pll &b, const pll &c)
	{
		return (a.first - b.first) * (a.second - c.second) - (a.first - c.first) * (a.second - b.second) >= 0;
	}
	void make_hull()
	{
		std::vector<pll> tmp;
		for (pll p : *hull)
		{
			while (tmp.size() >= 1 && tmp.back().second <= p.second)
				tmp.pop_back();
			while (tmp.size() >= 2 && ccw(tmp[tmp.size() - 2], tmp.back(), p))
				tmp.pop_back();
			tmp.push_back(p);
		}
		std::swap(tmp, *hull);
	}
	void print_debug(const char *s)
	{
		printf("debug %s\n", s);
		printf("queries:\n");
		for (pll p : *query)
			printf("(%lld,%lld) ", p.first, p.second);
		printf("\n");
		printf("hull:\n");
		for (pll p : *hull)
			printf("(%lld,%lld) ", p.first, p.second);
		printf("\n");
		printf("ans: %lld\n", ans);
	}
	void init()
	{
		std::sort(query->begin(), query->end());
		std::sort(hull->begin(), hull->end());
		make_hull();
		// print_debug("init");
	}
	long long slope(const pll &a, const pll &b)
	{
		return (a.second - b.second) / (b.first - a.first);
	}
	void solve(const std::vector<pll> &query, const std::vector<pll> &hull)
	{
		int i = 0, n = query.size(), j = 0, m = hull.size();
		while (i < n)
		{
			while (j < m - 1 && slope(hull[j], hull[j + 1]) < query[i].first)
				++j;
			ans = std::max(ans, query[i].first * hull[j].first + query[i].second + hull[j].second);
			++i;
		}
	}
	void merge(std::vector<pll> &v1, std::vector<pll> &v2)
	{
		std::vector<pll> tmp(v1.size() + v2.size());
		std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), tmp.begin());
		std::swap(tmp, v1);
		v2.clear();
	}
	data& operator + (data& other)
	{
		ans = std::max(ans, other.ans);
		solve(*query, *other.hull);
		solve(*other.query, *hull);
		merge(*query, *other.query);
		merge(*hull, *other.hull);
		make_hull();
		// print_debug("merge");
		return *this;
	}
	bool operator < (const data& other) const
	{
		return hull->size() < other.hull->size();
	}
#undef pll
};

void dfs(data &d, int u, int p = 0)
{
	d.query->emplace_back(sum[u] + d.root, pre[u]);
	d.ans = std::max(d.ans, pre[u] + sum[u] + d.root);
	d.hull->emplace_back(len[u], suf[u]);
	d.ans = std::max(d.ans, suf[u] + len[u] * d.root);
	for (int v : adj[u])
		if (!chk[v] && v != p)
		{
			len[v] = len[u] + 1;
			sum[v] = sum[u] + a[v];
			pre[v] = pre[u] + len[u] * a[v];
			suf[v] = suf[u] + sum[v];
			dfs(d, v, u);
		}
}

data get_data(int u, int p)
{
	data res(a[p]);
	len[u] = 2;
	sum[u] = a[u];
	pre[u] = a[u];
	suf[u] = a[u];
	dfs(res, u);
	res.init();
	return res;
}

long long solve(int u)
{
	centroid(u);
	chk[u] = true;
	// printf("solve at centroid %d\n", u);
	std::multiset<data> set;
	for (int v : adj[u])
		if (!chk[v])
			set.insert(get_data(v, u));
	while (set.size() > 1)
	{
		data x = *set.begin();
		set.erase(set.begin());
		data y = *set.begin();
		set.erase(set.begin());
		set.insert(x + y);
	}
	long long res = set.empty() ? a[u] : set.begin()->ans;
	for (int v : adj[u])
		if (!chk[v])
			res = std::max(res, solve(v));
	return res;
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	printf("%lld\n", solve(1));
}