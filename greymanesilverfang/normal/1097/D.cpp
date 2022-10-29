#include <algorithm>
#include <iostream>
#include <vector>
#define mod(x) ((x) %= INF)
#define mul(x, y) (1LL * (x) * (y) % INF)
#define C(n, k) mul(F[n], mul(invF[(n) - (k)], invF[k]))
#define invC(n, k) mul(invF[n], mul(F[(n) - (k)], F[k]))
#define candy(n, k) C((n) + (k) - 1, n)
#define invcandy(n, k) invC((n) + (k) - 1, n)
const int N = 1e4+1, INF = 1e9+7;
int inv[N], F[N], invF[N], e[N], f[N][50];
std::vector<std::pair<int,int>> d; 
std::vector<std::vector<int>> p;

int DFS(int k, int base = 0)
{
	if (base < d.size())
	{
		int res = 0;
		for (e[base] = 0; e[base] <= d[base].second; ++e[base])
			mod(res += DFS(k, base + 1));
		return res;
	}
	int res = 1;
	for (base = 0; base < d.size(); ++base)
		res = mul(res, mul(p[base][e[base]], f[base][d[base].second - e[base]]));
	return res;
}

void add_divisor(long long &n, long long x)
{
	d.push_back(std::make_pair(x % INF, 0));
	p.push_back(std::vector<int>(1, 1));
	while (n % x == 0)
	{
		++d.back().second;
		p.back().push_back(mul(p.back().back(), d.back().first));
		n /= x;
	}
}

void dp(int base, int lim, int k)
{
	f[base][0] = 1;
	for (int i = 1; i <= k; ++i)
		for (int exp = 0; exp <= lim; ++exp)
		{
			f[base][exp] = mul(f[base][exp], inv[lim - exp + 1]);
			if (exp > 0)
				mod(f[base][exp] += f[base][exp - 1]);
		}
}

int main()
{
	inv[1] = 1;
	for (int i = 2; i < N; ++i)
		inv[i] = mul(INF - INF / i, inv[INF % i]);
	F[0] = invF[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		F[i] = mul(F[i - 1], i);
		invF[i] = mul(invF[i - 1], inv[i]);
	}
	long long n; std::cin >> n;
	for (int i = 2; i <= n / i; ++i)
		if (n % i == 0)
			add_divisor(n, i);
	if (n > 1)
		add_divisor(n, n);
	int k; std::cin >> k;
	int cnt = 0;
	for (std::pair<int,int> p : d)
		dp(cnt++, p.second, k);
	std::cout << DFS(k);
	return 0;
}