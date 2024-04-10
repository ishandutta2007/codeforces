#include <cstdio>
#include <vector>
#include <set>
const int N = 4e5, INF = 1e9;
int n, k;
int l[N], r[N];

struct seg {
	int l, r, t;
	bool operator < (const seg &other) const {
		return r <= other.r;
	}
};

struct dat {
	int id; long long val;
};
std::vector<dat> mod[N];

void prep()
{
	std::set<seg> s;
	s.insert({1, INF, 0});
	for (int i = 1; i <= n; ++i)
	{
		auto p = s.lower_bound({l[i], l[i], -1});
		auto q = s.upper_bound({r[i], r[i], -1});
		seg tp = *p, tq = *q++;
		for (auto it = p; it != q; s.erase(it++))
			mod[i].push_back({it->t, it->l - it->r});
		if (tp.l < l[i])
		{
			mod[i].push_back({tp.t, l[i] - tp.l});
			s.insert({tp.l, l[i], tp.t});
		}
		if (r[i] < tq.r)
		{
			mod[i].push_back({tq.t, tq.r - r[i]});
			s.insert({r[i], tq.r, tq.t});
		}
		mod[i].push_back({i, r[i] - l[i]});
		s.insert({l[i], r[i], i});
	}
}

void solve(int lim, long long &cnt, long long &sum)
{
	cnt = sum = 0;
	std::vector<long long> val(1, INF - 1);
	long long len = 0, pre = 0;
	for (int i = 1, j = 1; i <= n; ++i)
	{
		val.push_back(0);
		for (dat d : mod[i])
		{
			val[d.id] += d.val;
			if (d.id >= j)
				len += d.val;
			else
				pre += d.val * d.id;
		}
		while (i >= j && len >= lim)
		{
			len -= val[j];
			pre += val[j] * j;
			++j;
		}
		cnt += j - 1;
		sum += pre + len * (j - 1);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &l[i], &r[i]);
	prep();
	int l = 1, r = INF;
	long long cnt, sum;
	while (l <= r)
	{
		int m = (l + r) / 2;
		solve(m, cnt, sum);
		if (cnt < k)
			r = m - 1;
		else 
			l = m + 1;
	}
	solve(r, cnt, sum);
	printf("%lld\n", sum - (cnt - k) * r);
}