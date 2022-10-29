#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a[100000];

struct IT
{
	int N, X;
	struct TNode
	{
		int size;
		long long ans;
		vector<pair<int,int>> l, r;
		TNode() {}
		TNode(int n, int x)
		{
			size = 1;
			ans = n >= x;
			pair<int,int> tmp = make_pair(1, n); 
			l.push_back(tmp);
			r.push_back(tmp);
		}
		void print()
		{
			cout << "size: " << size << ", ans: " << ans << endl;
			cout << "left side:";
			for (pair<int,int> p : l)
				cout << " {" << p.first << ", " << p.second << "}";
			cout << endl;
			cout << "right side:";
			for (pair<int,int> p : r)
				cout << " {" << p.first << ", " << p.second << "}";
			cout << endl;
		}
	};
	vector<TNode> node;
	TNode merge(TNode l, TNode r)
	{
		if (l.l.empty())
			return r;
		if (r.r.empty())
			return l;
		TNode tmp;
		tmp.size = l.size + r.size;
		tmp.l = l.l;
		for (pair<int, int> p : r.l)
		{
			int last = tmp.l.back().second;
			if ((last | p.second) > last)
				tmp.l.push_back(make_pair(p.first + l.size, last | p.second));
		}
		tmp.r = r.r;
		for (pair<int, int> p : l.r)
		{
			int last = tmp.r.back().second;
			if ((last | p.second) > last)
				tmp.r.push_back(make_pair(p.first + r.size, last | p.second));
		}
		tmp.ans = l.ans + r.ans;
		for (int il = l.r.size() - 1, ir = 0; il >= 0; l.size = --l.r[il--].first)
		{
			while (ir < r.l.size() && (l.r[il].second | r.l[ir].second) < X)
				++ir;
			if (ir == r.l.size())
				break;
			tmp.ans += 1LL * (l.size - l.r[il].first + 1) * (r.size - r.l[ir].first + 1);
		}
		return tmp;
	}
	IT(int n, int x) : N(n), X(x)
	{
		node.resize(2 * N);
		for (int i = 2 * N; --i;)
			node[i] = i < N ? merge(node[2 * i], node[2 * i + 1]) : TNode(a[i - N], X);
	}
	void update(int x, int y)
	{
		node[x + N] = TNode(a[x] = y, X);
		for (x += N; x /= 2;)
			node[x] = merge(node[2 * x], node[2 * x + 1]);
	}
	long long query(int x, int y)
	{
		TNode l, r;
		for (x += N, y += N; x < y; x /= 2, y /= 2)
		{
			if (x & 1)
				l = merge(l, node[x++]);
			if (y & 1)
				r = merge(node[--y], r);
		}
		return merge(l, r).ans;
	}
};

int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	IT data(n, x);
	for (int i = 0; i < m; ++i)
	{
		int t, x, y;
		cin >> t >> x >> y;
		switch (t)
		{
		case 1:
			data.update(x - 1, y);
		break;
		case 2:
			cout << data.query(x - 1, y) << endl;
		break;
		}
	}
	return 0;
}