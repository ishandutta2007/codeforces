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
const int N = 1e5 + 10;
class Matrix
{
public:
	int a[2][2];
	Matrix()
	{
		MEM(a, 0);
	}
	inline static Matrix ones()
	{
		Matrix ret;
		ret[0][0] = ret[1][1] = 1;
		return ret;
	}
	inline static Matrix E()
	{
		Matrix ret;
		ret[0][0] = ret[0][1] = ret[1][0] = 1;
		return ret;
	}
	bool operator != (Matrix m)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (a[i][j] != m[i][j])
					return true;
			}
		}
		return false;
	}
	Matrix operator + (Matrix b)
	{
		Matrix ret = *this;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				ret[i][j] += b[i][j];
				if (ret[i][j] >= INF) ret[i][j] -= INF;
			}
		}
		return ret;
	}
	Matrix operator *(Matrix b)
	{
		Matrix ret;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					ret[i][j] = (ret[i][j] + 1LL * a[i][k] * b[k][j]) % INF;
				}
			}
		}
		return ret;
	}
	Matrix operator ^(int b)
	{
		Matrix ret;
		ret[0][0] = ret[1][1] = 1;
		Matrix o = *this;
		while (b)
		{
			if (b & 1) ret = ret * o;
			o = o * o;
			b >>= 1;
		}
		return ret;
	}
	int* operator [](int i)
	{
		return a[i];
	}
};
class SegmentTree
{
public:
	int ql, qr;
	Matrix qx;
	Matrix val[N * 4];
	Matrix setv[N * 4];
	void set(int l, int r, Matrix m = Matrix())
	{
		ql = l, qr = r, qx = m;
	}
	void maintain(int o)
	{
		val[o] = val[o << 1] + val[o << 1 | 1];
	}
	void pushdown(int o)
	{
		if (setv[o] != Matrix::ones())
		{
			val[o << 1] = val[o << 1] * setv[o];
			val[o << 1 | 1] = val[o << 1 | 1] * setv[o];
			setv[o << 1] = setv[o << 1] * setv[o];
			setv[o << 1 | 1] = setv[o << 1 | 1] * setv[o];
			setv[o] = Matrix::ones();
		}
	}
	void build(int l, int r, int o = 1)
	{
		setv[o] = Matrix::ones();
		if (l == r)
		{
			int x;
			scanf("%d", &x);
			val[o] = Matrix::E() ^ (x - 1);
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = setv[o] * qx;
			val[o] = val[o] * qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	Matrix query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return val[o];
		}
		pushdown(o);
		Matrix ret;
		int mid = (l + r) >> 1;
		if (ql <= mid) ret = ret + query(l, mid, o << 1);
		if (mid < qr) ret = ret + query(mid + 1, r, o << 1 | 1);
		maintain(o);
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	st.build(1, n);
	while (q--)
	{
		int op, l, r, x;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1)
		{
			scanf("%d", &x);
			st.set(l, r, Matrix::E() ^ x);
			st.update(1, n);
		}
		else
		{
			st.set(l, r);
			printf("%d\n", st.query(1, n)[0][0]);
		}
	}
	return 0;
}