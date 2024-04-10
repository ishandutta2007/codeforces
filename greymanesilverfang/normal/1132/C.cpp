#include <algorithm>
#include <iostream>
const int N = 5005;
int n, q, l[N], r[N], f[N], len[N];
struct TQuery {
	int l, r, id;
	TQuery(int _l = 0, int _r = 0, int _id = 0) : l(_l), r(_r), id(_id) {}
} lq[N], rq[N];

int solve(int id)
{
	int res = 0, cur = 0;
	for (int i = 1; i <= n; ++i)
		res += !!(cur += f[i]);
	for (int i = 0; i < q; ++i)
	{
		if (i == id) continue;
		len[i] = r[i] - l[i] + 1;
	}
	int max = 0;
	for (int i = 0; i < q; ++i)
	{
		if (lq[i].id == id) continue;
		len[lq[i].id] -= std::max(0, max - lq[i].l + 1);
		max = std::max(max, lq[i].r);
	}
	int min = N;
	for (int i = 0; i < q; ++i)
	{
		if (rq[i].id == id) continue;
		len[rq[i].id] -= std::max(0, rq[i].r - min + 1);
		min = std::min(min, rq[i].l);
	}
	int solo = N;
	for (int i = 0; i < q; ++i)
	{
		if (i == id) continue;
		solo = std::min(solo, std::max(0, len[i]));
	}
	return res - solo;
}

int main()
{
	std::cin >> n >> q;
	for (int i = 0; i < q; ++i)
	{
		std::cin >> l[i] >> r[i];
		lq[i] = rq[i] = TQuery(l[i], r[i], i);
		++f[l[i]], --f[r[i] + 1];
	}
	std::sort(lq, lq + q, [](TQuery l, TQuery r){
		return l.l < r.l;
	});
	std::sort(rq, rq + q, [](TQuery l, TQuery r){
		return l.r > r.r;
	});
	int res = 0;
	for (int i = 0; i < q; ++i)
	{
		--f[l[i]], ++f[r[i] + 1];
		res = std::max(res, solve(i));
		++f[l[i]], --f[r[i] + 1];
	}
	std::cout << res;
	return 0;
}