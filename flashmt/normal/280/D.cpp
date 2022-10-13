#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;

struct node
{
	int low, high, mid;
	int sum, maxAll, maxLeft, maxRight, minAll, minLeft, minRight;
	pair <int,int> idMaxAll, idMinAll;
	int reserved, idMaxLeft, idMaxRight, idMinLeft, idMinRight;
	node *L, *R;
	
	node() {}
	node(int _low, int _high)
	{
		low = _low; high = _high; mid = (low + high) / 2;
		sum = maxAll = maxLeft = maxRight = minAll = minLeft = minRight = 0;
		reserved = 0;
		if (low < high)
		{
			L = new node(low, mid);
			R = new node(mid + 1, high);
		}
	}
	
	void updateFromChildren(node L, node R)
	{
		int val;

		sum = L.sum + R.sum;
		
		val = L.sum + R.maxLeft;
		if (val > L.maxLeft)	maxLeft = val, idMaxLeft = R.idMaxLeft;
		else maxLeft = L.maxLeft, idMaxLeft = L.idMaxLeft;
		
		val = L.sum + R.minLeft;
		if (val < L.minLeft) minLeft = val, idMinLeft = R.idMinLeft;
		else minLeft = L.minLeft, idMinLeft = L.idMinLeft;
		
		val = R.sum + L.maxRight;
		if (val > R.maxRight) maxRight = val, idMaxRight = L.idMaxRight;
		else maxRight = R.maxRight, idMaxRight = R.idMaxRight;
		
		val = R.sum + L.minRight;
		if (val < R.minRight) minRight = val, idMinRight = L.idMinRight;
		else minRight = R.minRight, idMinRight = R.idMinRight;
		
		maxAll = max(max(L.maxAll, R.maxAll), L.maxRight + R.maxLeft);
		if (maxAll == L.maxAll) idMaxAll = L.idMaxAll;
		else if (maxAll == R.maxAll) idMaxAll = R.idMaxAll;
		else idMaxAll = make_pair(L.idMaxRight, R.idMaxLeft);
		
		minAll = min(min(L.minAll, R.minAll), L.minRight + R.minLeft);
		if (minAll == L.minAll) idMinAll = L.idMinAll;
		else if (minAll == R.minAll) idMinAll = R.idMinAll;
		else idMinAll = make_pair(L.idMinRight, R.idMinLeft);
	}
	
	void update(int x, int val)
	{
		if (low == high)
		{
			sum = val;
			idMaxAll = idMinAll = make_pair(x, x);
			maxAll = maxLeft = maxRight = max(0, val);
			minAll = minLeft = minRight = min(0, val);
			idMaxLeft = idMaxRight = idMinLeft = idMinRight = x;
			return;
		}
		if (x <= mid) L -> update(x, val);
		else R -> update(x, val);
		updateFromChildren(*L, *R);
	}
	
	void doNegate()
	{
		sum = -sum;
		swap(maxAll, minAll); swap(idMaxAll, idMinAll);
		swap(maxLeft, minLeft); swap(idMaxLeft, idMinLeft);
		swap(maxRight, minRight); swap(idMaxRight, idMinRight);
		maxAll = -maxAll; maxLeft = -maxLeft; maxRight = -maxRight;
		minAll = -minAll; minLeft = -minLeft; minRight = -minRight;
		reserved ^= 1; 
	}
	
	void negate(int x, int y)
	{
		if (low == x && high == y) doNegate();
		else
		{
			
			if (reserved)
			{
				L -> doNegate();
				R -> doNegate();
				reserved = 0;
			}
			
			if (x <= mid) L -> negate(x, min(y, mid));
			if (mid < y) R -> negate(max(x, mid + 1), y);
			updateFromChildren(*L, *R);
		}
	}
	
	node query(int x, int y)
	{
		if (low == x && high == y) return *this;
		
		if (reserved)
		{
			L -> doNegate();
			R -> doNegate();
			reserved = 0;
		}
		
		node u, v, res;
		if (x <= mid) u = L -> query(x, min(y, mid));
		if (mid < y) v = R -> query(max(x, mid + 1), y);
		if (x > mid) return v;
		if (y <= mid) return u;
		res.low = x; res.high = y;
		res.updateFromChildren(u, v);
		return res;
	}
};

int main()
{
	int n, x, Q, type, y, k;
	pair <int,int> endpoints[22];
	
	cin >> n;
	node root(1, n);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &x);
		root.update(i, x);
	}
	
	cin >> Q;
	while (Q--)
	{
		scanf("%d%d%d", &type, &x, &y);
		if (!type) root.update(x, y);
		else
		{
			int ans = 0;
			scanf("%d", &k);
			
			for (int i = 0; i < k; i++)
			{
				node u = root.query(x, y);
				if (u.maxAll <= 0) endpoints[i] = make_pair(0, 0), k = i + 1;
				else 
				{
					ans += u.maxAll;
					endpoints[i] = u.idMaxAll;
					root.negate(endpoints[i].first, endpoints[i].second);
				}
			}
			
			printf("%d\n", ans);
			
			for (int i = 0; i < k; i++)
				if (endpoints[i].first)
					root.negate(endpoints[i].first, endpoints[i].second);
		}
	}
	
}