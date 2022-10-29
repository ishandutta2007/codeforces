// #inclusion_exclusion

#include <cstdio>
#include <iostream>
const int N = 1e6, INF = 1e9+7;
long long s[3][N], f[N];

void mod(long long &x)
{
	if (x > INF)
		x -= INF;
	if (x < 0)
		x += INF;
}

int read_int()
{
	int res = 0, digit_cnt = 0;
	while (true)
	{
		char c = getchar();
		if ('0' <= c && c <= '9')
			res = res * 10 + c - '0', ++digit_cnt;
		else if (digit_cnt > 0)
			break;
	}
	return res;
}

long long pow(long long base, int exp)
{
	long long res = 1;
	while (exp > 0)
	{
		if (exp & 1)
			res = res * base % INF;
		base = base * base % INF;
		exp /= 2;
	}
	return res;
}

int main()
{
	int n = read_int();
	for (int i = 1; i <= n; ++i)
	{
		int val = read_int();
		for (int t = 0; t < 3; ++t)
			mod(s[t][val] += pow(val, t));
	}
	for (int depth = 0; depth < 6; ++depth)
		for (int val = N - 1; val >= 0; --val)
			if (val / pow(10, depth) % 10 < 9)
				for (int t = 0; t < 3; ++t)
					mod(s[t][val] += s[t][val + pow(10, depth)]);
	for (int val = 0; val <= N - 1; ++val)
		f[val] = pow(2, s[0][val]) * (pow(s[1][val], 2) + s[2][val]) % INF * 250000002 % INF;
	for (int depth = 0; depth < 6; ++depth)
		for (int val = 0; val <= N - 1; ++val)
			if (val / pow(10, depth) % 10 < 9)
				mod(f[val] -= f[val + pow(10, depth)]);
	long long res = 0;
	for (int val = 0; val <= N - 1; ++val)
		res ^= f[val] * val;
	std::cout << res;
	return 0;
}