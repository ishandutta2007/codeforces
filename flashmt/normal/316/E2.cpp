#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;
const int N = 200200, BASE = int(1e9);

int fib[N];

struct segmentTree
{
	int low, high, mid;
	pair <long long,long long> s;
	segmentTree *L, *R;
	
	segmentTree(int _low, int _high)
	{
		low = _low; high = _high; mid = (low + high) / 2;
		s = make_pair(0, 0);
		if (low < high)
		{
			L = new segmentTree(low, mid);
			R = new segmentTree(mid + 1, high);
		}
	}
	
	pair <long long,long long> mergeChild(pair <long long,long long> L, pair <long long,long long> R, int shift)
	{
		long long u = (L.first + R.first * fib[shift] + R.second * fib[shift - 1]) % BASE;
		long long v = (L.second + R.first * fib[shift - 1] + R.second * (shift > 1 ? fib[shift - 2] : 0)) % BASE;
		return make_pair(u, v);
	}
	
	void setVal(int x, int v)
	{
		if (low == high) s.first = v;
		else
		{
			if (x <= mid) L -> setVal(x, v);
			else R -> setVal(x, v);
			s = mergeChild(L -> s, R -> s, mid + 1 - low);
		}
	}
	
	pair <long long,long long> query(int x, int y)
	{
		if (low == x && high == y) return s;
		if (y <= mid) return L -> query(x, y);
		if (mid < x) return R -> query(x, y);
		return mergeChild(L -> query(x, mid), R -> query(mid + 1, y), mid + 1 - x);
	}		
};

int main()
{
	int n, m, x, y, t;
	
	fib[0] = fib[1] = 1;
	for (int i = 2; i < N; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % BASE;
	
	cin >> n >> m;
	segmentTree segtree(1, n);
	for (int i = 1; i <= n; i++) scanf("%d", &x), segtree.setVal(i, x);
	
	while (m--)
	{
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) segtree.setVal(x, y);
		if (t == 2) 
		{
			pair <long long,long long> res = segtree.query(x, y);
			printf("%d\n", int(res.first));
		}
	}	
}