#include <cstdio>
#include <algorithm>
#include <vector>
const int MOD = 998244353, inv2 = (MOD + 1) / 2;
typedef std::vector<long long> seg;
struct dat {
	long long val; int len;
	bool operator < (const dat &other) const {
		if (val != other.val)
			return val < other.val;
		return len > other.len;
	}
	bool contain(const dat &other) const {
		if (len < other.len)
			return false;
		return val == other.val >> len << len;
	}
	long long sum() {
		long long l = val % MOD;
		long long r = (val + (1LL << len) - 1) % MOD;
		return (l + r) * (MOD + r - l + 1) % MOD * inv2 % MOD;
	}
} vc[10000000];
int vcnt;

seg makel(long long l, long long r)
{
	seg res;
	for (long long len = 1; l + len <= r + 1; len *= 2)
	{
		res.push_back(l);
		l = l + len & ~len;
	}
	return res;
}

seg maker(long long r, long long l)
{
	seg res;
	for (long long len = 1; l <= r; len *= 2)
	{
		res.push_back(r);
		r = r - len & ~len;
	}
	return res;
}

void read(std::vector<seg> &v)
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		long long l, r; scanf("%lld%lld", &l, &r);
		v.push_back(makel(l, r));
		v.push_back(maker(r, l));
	}
}

void mark(long long x, int y)
{
	long long fill = (1LL << y) - 1;
	vc[vcnt++] = {x & ~fill, y};
}

void solve(const seg &s1, const seg &s2)
{
	for (int i = 0; i < s1.size(); ++i)
	{
		mark(s1[i] ^ s2[0], i);
		if (i < s2.size())
			mark(s1[i] ^ s2[i], i);
	}
}

int main()
{
	std::vector<seg> va, vb;
	read(va);
	read(vb);
	for (seg s1 : va)
		for (seg s2 : vb)
		{
			solve(s1, s2);
			solve(s2, s1);
		}
	std::sort(vc, vc + vcnt);
	long long res = 0;
	dat prv = {0, 0};
	for (int i = 0; i < vcnt; ++i)
		if (!prv.contain(vc[i]))
		{
			res += vc[i].sum();
			prv = vc[i];
		}
	printf("%lld\n", res % MOD);
}