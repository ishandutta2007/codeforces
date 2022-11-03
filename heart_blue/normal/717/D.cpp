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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 128;
class Matrix
{
public:
	double a[N][N];
	int n;
	void toOne(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
		{
			a[i][i] = 1;
		}
	}
	void zero(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = 0;
			}
		}
	}
	void init(vector<double> &v)
	{
		v.size();
		zero(N);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				a[i][i^j] += v[j];
			}
		}
	}

	Matrix operator + (Matrix &m)
	{
		Matrix ma;
		ma.n = m.n;
		for (int i = 0; i < ma.n; i++)
		{
			for (int j = 0; j < ma.n; j++)
			{
				ma.a[i][j] = a[i][j] + m.a[i][j];
			}
		}
		return ma;
	}
	Matrix operator *(Matrix &m)
	{
		Matrix ma;
		ma.n = 0;
		ma.zero(n);
		for (int k = 0; k < ma.n; k++)
		{
			for (int i = 0; i < ma.n; i++)
			{
				for (int j = 0; j < ma.n; j++)
				{
					ma.a[i][j] += a[i][k] * m.a[k][j];
				}
			}
		}
		return ma;
	}
	Matrix operator ^(int x)
	{
		Matrix ret;
		ret.zero(this->n);
		ret.toOne(this->n);
		Matrix o = *this;
		while (x)
		{
			if (x & 1) ret = ret * o;
			o = o*o;
			x >>= 1;
		}
		return ret;
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	m++;
	vector<double> v(m);
	for (auto &x : v) cin >> x;
	Matrix ma;
	ma.init(v);
	ma = ma^n;
	printf("%.15f\n", 1 - ma.a[0][0]);

	return 0;
}