#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 12345;
const int N = 2e2 + 10;
class Matrix
{
	int a[N][N];
	int n;
public:
	Matrix ones(int n)
	{
		Matrix ret(n);
		for (int i = 0; i < n; i++) ret[i][i] = 1;
		return ret;
	}
	Matrix(int n = 0)
	{
		init(n);
	}
	void init(int n)
	{
		this->n = n;
		MEM(a, 0);
	}
	int* operator [] (int i)
	{
		return a[i];
	}
	Matrix operator + (Matrix &m)
	{
		Matrix ret(*this);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] += m[i][j];
				if (a[i][j] >= INF) a[i][j] -= INF;
			}

		}
	}
	Matrix operator *(Matrix &m)
	{
		Matrix ret(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					ret[i][j] = (ret[i][j] + 1LL * a[i][k] * m[k][j]) % INF;
				}
			}
		}
		return ret;
	}
	Matrix operator ^(LL b)
	{
		Matrix ret = ones(n);
		Matrix a = *this;
		while (b)
		{
			if (b & 1) ret = ret * a;
			a = a * a;
			b >>= 1;
		}
		return ret;
	}
};
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int v[N];
int a[N];
int w[N];
int flag[N][N];
int key[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<char, int> mc;
	LL n;
	int m;
	cin >> n >> m;
	vector<pair<char, int>> vp;
	int tot = 1;
	for (int i = 0; i < m; i++)
	{
		char c;
		int x;
		cin >> c >> x;
		mc[c] = 1;
		flag[c][x] = 1;
	}
	for (int i = 'A'; i <= 'Z'; i++)
	{
		int cur = 1;
		for (int j = 1; j < N; j++)
		{
			if (flag[i][j] == 0) continue;
			for (int k = j + j; k < N; k += j) flag[i][k] = 0;
			cur *= j;
			if (vp.empty() || vp.back().first != i) vp.push_back({ i,cur });
			else vp.back().second = cur;
			tot *= j;
		}
		for (int j = 1; j < N; j++)
		{
			if (flag[i][j] == 0) continue;
			for (int k = j; k < N; k += j) flag[i][k] = 1;
			flag[i][0] = 1;
		}
	}
	int sz = 0;
	for (auto &p : vp) v[sz++] = p.second;
	v[sz] = 1;
	w[0] = 1;
	for (int i = 1; i < sz; i++) w[i] = v[i - 1] * w[i - 1];
	vector<int> ans;
	for (int i = 0; i < tot; i++)
	{
		MEM(key, 0);
		int cur = i;
		for (int j = 0; j < sz; j++)
		{
			int x = cur % v[j];
			cur /= v[j];
			if (flag[vp[j].first][x])
				key[vp[j].first] = 1;
		}
		if (count(key, key + N, 1) == mc.size()) ans.push_back(i);
	}
	Matrix b(tot);
	for (int i = 0; i < tot; i++)
	{
		int cur = i;
		for (int j = 0; j < sz; j++)
		{
			int x = cur % v[j];
			cur /= v[j];
			int y = (x + 1) % v[j];
			b[i][i - (x - y)*w[j]]++;
		}
	}
	b = b ^ n;
	int ret = 0;
	for (auto &x : ans)
	{
		ret += b[0][x];
		if (ret >= INF) ret -= INF;
	}
	printf("%d\n", ret);
	return 0;
}