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
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
class Matrix
{
private:
	int a[N][N];
	int n;
public:
	Matrix(int n = 0)
	{
		init(n);
	}
	void init(int n)
	{
		this->n = n;
		MEM(a, 0);
	}
	void all(int x)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = x;
			}
		}
	}
	int* operator [] (int i)
	{
		return a[i];
	}
	static Matrix ones(int n)
	{
		Matrix ret(n);
		for (int i = 0; i < n; i++) ret[i][i] = 1;
		return ret;
	}
	Matrix operator +(Matrix &m)
	{
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
	Matrix operator *(Matrix &m)
	{
		Matrix ret(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					ret[i][j] += 1LL * a[i][k] * m[k][j] % INF;
					if (ret[i][j] >= INF) ret[i][j] -= INF;
				}
			}
		}
		return ret;
	}
	Matrix operator ^(LL b)
	{
		Matrix ret = ones(n);
		Matrix o = *this;
		while (b)
		{
			if (b & 1) ret = ret * o;
			o = o * o;
			b >>= 1;
		}
		return ret;
	}
};
int id(char c)
{
	if (islower(c)) return c - 'a';
	else return c - 'A' + 26;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	int m, k;
	cin >> n;
	cin >> m >> k;
	Matrix ans(m);
	ans.all(1);
	while (k--)
	{
		string s;
		cin >> s;
		int x = id(s[0]), y = id(s[1]);
		ans[x][y] = 0;
	}
	ans = ans ^ (n - 1);
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res += ans[i][j];
			if (res >= INF) res -= INF;
		}
	}
	cout << res << endl;
	return 0;
}