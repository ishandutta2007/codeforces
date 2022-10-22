#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 2.1e5;
int lg[N];
template <typename T>
struct Q
{
	vector<T> a;
	vector<vector<T>> st;
	Q(const vector<T> &b) : a(all(b)), st(lg[b.size()] + 1, vector<T>(b.size()))
	{
		int n = a.size(), i, j;
		for (i = 0; i < n; i++)
			st[0][i] = i;
		for (j = 1; j <= lg[n]; j++)
			for (i = 0; i + (1 << j) <= n; i++)
				st[j][i] = a[st[j - 1][i]] > a[st[j - 1][i + (1 << j - 1)]] ? st[j - 1][i] : st[j - 1][i + (1 << j - 1)];
	}
	int rmq(int l, int r)
	{
		int z = lg[r - l + 1];
		return a[st[z][l]] > a[st[z][r - (1 << z) + 1]] ? st[z][l] : st[z][r - (1 << z) + 1];
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (int i = 2; i < N; i++)
		lg[i] = lg[i >> 1] + 1;
	for (cin >> testcase; testcase--;)
	{
		int n, m, i, j, flg = 1;
		cin >> n;
		vector<int> a(n);
		for (int &x : a)
			cin >> x;
		vector<ll> sum(n + 1), ns(n + 1);
		for (i = 0; i < n; i++)
			sum[i + 1] = sum[i] + a[i];
		for (i = 0; i <= n; i++)
			ns[i] = -sum[i];
		Q s(a);
		Q t(sum);
		Q tt(ns);
		//[l,r):sum[r]-sum[l]
		auto dfs = [&](auto dfs, int l, int r) -> void
		{
			if (l >= r || !flg)
				return;
			int x = s.rmq(l, r);
			int y = t.rmq(x + 1, r + 1);
			// cerr << l << ' ' << r << ' ' << x << ' ' << y << endl;
			flg &= sum[y] <= sum[x + 1];
			y = tt.rmq(l, x);
			// cerr << l << ' ' << r << ' ' << x << ' ' << y << endl;
			flg &= sum[x] <= sum[y];
			dfs(dfs, l, x - 1);
			dfs(dfs, x + 1, r);
		};
		dfs(dfs, 0, n - 1);
		if (flg)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}