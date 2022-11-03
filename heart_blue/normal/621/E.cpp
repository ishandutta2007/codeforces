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
public:
	int a[N][N];
	int n;
	Matrix(int n = N)
	{
		this->n = n;
		MEM(a, 0);
	}
	static Matrix ones(int n = N)
	{
		Matrix ret(n);
		for (int i = 0; i < n; i++) ret[i][i] = 1;
		return ret;
	}
	int* operator [] (int i)
	{
		return a[i];
	}
	Matrix operator + (Matrix &b)
	{
		Matrix ret;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret[i][j] = a[i][j] + b[i][j];
			}
		}
		return ret;
	}
	Matrix operator * (Matrix &b)
	{
		Matrix ret;
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					ret[i][j] = (ret[i][j] + 1LL * a[i][k] * b[k][j]) % INF;
				}
			}
		}
		return ret;
	}
	Matrix operator ^ (int b)
	{
		Matrix ret = ones();
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
int cnt[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, b, k, x;
	cin >> n >> b >> k >> x;
	Matrix m(x);
	while (n--)
	{
		int c;
		cin >> c;
		cnt[c]++;
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m[i][(i * 10 + j) % x] += cnt[j];
		}
	}
	m = m ^ b;
	cout << m[0][k] << endl;
	return 0;
}