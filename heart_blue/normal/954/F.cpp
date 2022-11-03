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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

class Matrix
{
	int a[3][3];
	int sz;
public:
	int size()
	{
		return sz;
	}
	Matrix(int n = 3)
	{
		sz = n;
		MEM(a, 0);
	}
	int* operator [](int i)
	{
		return a[i];
	}
	static Matrix ones(int n = 3)
	{
		Matrix ret(n);
		for (int i = 0; i < n; i++) ret[i][i] = 1;
		return ret;
	}
	void init(int n = 3)
	{
		sz = n;
	}
	Matrix operator *(Matrix& m)
	{
		int n = m.size();
		Matrix ret(n);
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					ret[i][j] = (ret[i][j] + 1LL * a[i][k] * m[k][j]) % INF;
				}
			}
		}
		return ret;
	}
	Matrix operator +(Matrix& m)
	{
		int n = m.size();
		Matrix ret(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret[i][j] = a[i][j] + m[i][j];
				if (ret[i][j] >= INF) ret[i][j] -= INF;
			}
		}
		return ret;
	}
	Matrix operator ^(LL b)
	{
		Matrix ret = ones(sz);
		Matrix A = *this;
		while (b)
		{
			if (b & 1) ret = ret * A;
			A = A * A;
			b >>= 1;
		}
		return ret;
	}
	Matrix powsum(int b)
	{
		Matrix ret(sz);
		Matrix A = ones(sz);
		for (int i = 30; i >= 0; i--)
		{
			ret = ret * A + ret;
			A = A * A;
			if (b >> i & 1)
			{
				A = A * (*this);
				ret = ret * (*this) + (*this);
			}
		}
		return ret;
	}
};
map<LL, map<int, int>> mc;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	Matrix key = Matrix::ones(3);
	Matrix A = key;
	int n;
	LL m;
	scanf("%d%lld", &n, &m);
	mc[1];
	mc[m];
	for (int i = 1; i <= n; i++)
	{
		int o;
		LL l, r;
		scanf("%d%lld%lld", &o, &l, &r);
		mc[l][o]++;
		mc[r][o]--;
	}
	LL cur = 1;
	map<LL, int> sum;

	for (auto& p : mc)
	{
		LL x = p.first;
		auto v = p.second;
		for (int i = 0; i <= 4; i++)
			sum[i] += v[i];
		key = (A ^ (x - cur)) * key;
		cur = x;
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				if (abs(i - j) <= 1 && sum[i] == 0 && sum[j] == 0)
				{
					A[i - 1][j - 1] = 1;
				}
				else
					A[i - 1][j - 1] = 0;
			}
		}
	}
	LL res = key[1][1];
	printf("%lld\n", res);

	return 0;
}