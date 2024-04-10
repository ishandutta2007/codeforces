#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 3e5 + 79, logn = 20, max2 = 1 << 19;
vector<vector<int> > l(logn, vector<int>(maxn, -1)), maxi(logn, vector<int>(maxn, -1)), g(maxn), g2(maxn);
vector<int> p(maxn), s(maxn, 1), d(maxn, 0);
int highest(int vr)
{
	while (vr != p[vr]) vr = p[vr];
	return vr;
}
bool merge(int a, int b)
{
	a = highest(a); b = highest(b);
	if (a == b) return false;
	if (s[a] < s[b]) swap(a, b);
	s[a] += s[b];
	p[b] = a;
	return true;
}
void dfs(int v)
{
	for (int i = 1; i < logn; i++) if (l[i - 1][v] != -1) l[i][v] = l[i - 1][l[i - 1][v]];
	for (int i = 1; i < logn; i++) if (l[i - 1][v] != -1) maxi[i][v] = max(maxi[i - 1][v], maxi[i - 1][l[i - 1][v]]);
	for (int i : g2[v])
	{
		if (l[0][v] == i) continue;
		maxi[0][i] = l[0][i] = v;
		d[i] = d[v] + 1;
		dfs(i);
	}
}
int maxlca(int u, int v)
{
	int ans = max(u, v);
	if (d[u] < d[v]) swap(u, v);
	for (int i = logn - 1; i >= 0; i--)
	{
		if (l[i][u] != -1 && d[l[i][u]] >= d[v])
		{
			ans = max(ans, maxi[i][u]);
			u = l[i][u];
		}
	}
	if (u == v) return ans;
	for (int i = logn - 1; i >= 0; i--)
	{
		if (l[i][u] != l[i][v])
		{
			ans = max({ ans, maxi[i][u], maxi[i][v] });
			u = l[i][u]; v = l[i][v];
		}
	}
	return max(ans, l[0][v]);
}
vector<ll> lazy(max2 * 2, 0), sum(max2 * 2, 0), ans(maxn, 0);
void unlazy(int vr, int len1, int len2)
{
	lazy[vr * 2 + 1] += lazy[vr]; lazy[vr * 2 + 2] += lazy[vr];
	sum[vr * 2 + 1] += lazy[vr] * 1ll * len1;
	sum[vr * 2 + 2] += lazy[vr] * 1ll * len2;
	lazy[vr] = 0;
}
void add(int l, int r, int myl = 0, int myr = max2 - 1, int vr = 0)
{
	if (r < myl || l > myr) return;
	if (l <= myl && myr <= r)
	{
		lazy[vr] ++; sum[vr] += myr - myl + 1;
		return;
	}
	int mid = (myl + myr) / 2;
	unlazy(vr, (mid - myl + 1), (myr - mid));
	add(l, r, myl, mid, vr * 2 + 1);
	add(l, r, mid + 1, myr, vr * 2 + 2);
	sum[vr] = sum[vr * 2 + 1] + sum[vr * 2 + 2];
}
ll suma(int l, int r, int myl = 0, int myr = max2 - 1, int vr = 0)
{
	if (r < myl || l > myr) return 0;
	if (l <= myl && myr <= r) return sum[vr];
	int mid = (myl + myr) / 2;
	unlazy(vr, (mid - myl + 1), (myr - mid));
	return suma(l, r, myl, mid, vr * 2 + 1) + suma(l, r, mid + 1, myr, vr * 2 + 2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b; a--; b--;
		g[min(a, b)].push_back(max(a, b));
	}
	for (int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());
	for (int i = n - 1; i >= 0; i--) for (int& j : g[i])
		if (merge(i, j)) { g2[i].push_back(j); g2[j].push_back(i); j = -1; }
	for (int i = 0; i < n; i++) if (l[0][i] == -1) dfs(i);
	int mini = n;
	vector < vector<pair<int, int> > > qu(n);
	cin >> q;
	for (int i = 0, l, r; i < q; i++)
	{
		cin >> l >> r; l--; r--;
		qu[l].push_back({ r, i });
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j : g[i])
			if (j != -1) mini = min(mini, maxlca(i, j));
		add(i, mini - 1);
		//cout << i << " " << mini << "\n";
		for (pair<int, int> qq : qu[i])
			ans[qq.second] = suma(i, qq.first);
	}
	for (int i = 0; i < q; i++) cout << ans[i] << "\n";
	return 0;
}