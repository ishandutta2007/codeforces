#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
const int MOD = 1e9+7;

struct seg {
	int l, r;
	bool operator < (const seg &other) const {
		return r < other.r;
	}
};

int mod(int x)
{
	return x < MOD ? x : x - MOD;
}

int pow2(int p)
{
	long long res = 1, base = 2;
	while (p > 0)
	{
		if (p & 1) res = res * base % MOD;
		base = base * base % MOD;
		p /= 2;
	}
	return res;
}

int main()
{
	int k, n, m; scanf("%d%d%d", &k, &n, &m);
	std::vector<seg> va, vb;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int l, r; scanf("%d%d", &l, &r);
		va.push_back({l, r});
		v.push_back(l - 1);
		v.push_back(r);
	}
	for (int i = 0; i < m; ++i)
	{
		int l, r; scanf("%d%d", &l, &r);
		vb.push_back({l, r});
		v.push_back(l - 1);
		v.push_back(r);
	}
	std::sort(va.begin(), va.end());
	std::sort(vb.begin(), vb.end());
	v.push_back(0);
	v.push_back(k);
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	std::queue<int> fa, fb;
	long long sa = 0, sb = 0, s = 1;
	int ia = 0, ib = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		// add
		fa.push(mod(sb + s));
		fb.push(mod(sa + s));
		s = (sa + sb + s) * (pow2(v[i] - v[i - 1]) - 2) % MOD;
		sa = mod(sa + fa.back());
		sb = mod(sb + fb.back());
		// purge
		while (ia < va.size() && v[i] == va[ia].r)
		{
			while (v[i - fa.size()] < va[ia].l)
			{
				sa = mod(sa + MOD - fa.front());
				fa.pop();
			}
			++ia;
		}
		while (ib < vb.size() && v[i] == vb[ib].r)
		{
			while (v[i - fb.size()] < vb[ib].l)
			{
				sb = mod(sb + MOD - fb.front());
				fb.pop();
			}
			++ib;
		}
	}
	printf("%lld\n", (sa + sb + s) % MOD);
}