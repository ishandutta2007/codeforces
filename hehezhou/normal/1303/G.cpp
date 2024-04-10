#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[150010];
vector < int > son1[150010], son[300010];
int rt, wsze[300010], sze[300010];
void get_rt(int cur, int fa, int sum) {
	sze[cur] = 1, wsze[cur] = 0;
	for (auto i : son[cur]) {
		if (i == fa) continue;
		get_rt(i, cur, sum);
		sze[cur] += sze[i];
		wsze[cur] = max(wsze[cur], sze[i]);
	}
	wsze[cur] = max(wsze[cur], sum - sze[cur]);
	if (rt == -1 || wsze[cur] < wsze[rt]) rt = cur;
}
typedef pair < ll, ll > PLL;
vector < PLL > a1, a2;
void dfs(int cur, int fa, ll sum1, ll sum2, int dep, int type) {
	if (cur <= n) {
		if (type == 1) {
			dep++;
			sum1 += a[cur];
			sum2 += sum1;
			a1.push_back(make_pair(dep, sum2));
		}
		else {
			dep++;
			sum1 += a[cur];
			sum2 += 1ll * dep * a[cur];
			a2.push_back(make_pair(sum1, sum2));
		}
	}
	for (auto i : son[cur]) {
		if (i == fa) continue;
		dfs(i, cur, sum1, sum2, dep, type);
	}
}
inline int chk(PLL a, PLL b, PLL c) {
	a.first -= b.first, a.second -= b.second, b.first -= c.first, b.second -= c.second;
	return a.first * b.second - a.second * b.first >= 0;
}
long long ans = 0;
void calc() {
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	int top = 0;
	for (int i = 0; i < a1.size(); i++) {
		while (top >= 2 && chk(a1[top - 2], a1[top - 1], a1[i])) top--;
		a1[top++] = a1[i];
	}
	a1.resize(top);
	for (int i = 0, j = 0; i < a2.size(); i++) {
		while (j < top - 1 && a2[i].first * a1[j].first + a1[j].second <= a2[i].first * a1[j + 1].first + a1[j + 1].second) j++;
		ans = max(ans, a2[i].first * a1[j].first + a1[j].second + a2[i].second);
	}
}
void solve(int cur, int sum) {
	fprintf(stderr, "%d\n", sum);
	if (sum == 1) {
		ans = max(ans, (ll)a[cur]);
		return;
	}
	rt = -1;
	get_rt(cur, 0, sum);
	cur = rt;
	get_rt(cur, 0, sum);
	vector < int > sons = son[cur];
	if (sum == 2) {
		assert(sons.size());
		ans = max(ans, (ll)a[cur] + a[sons[0]] + max(a[cur], a[sons[0]]));
		return;
	}
	sort(sons.begin(), sons.end(), [](int a, int b) {
		return sze[a] > sze[b];
	});
	int mid = 0, csum = 0;
	while (mid < sons.size() && csum + sze[sons[mid]] <= sum / 2) csum += sze[sons[mid]], mid++;
	a1.clear(), a2.clear();
	a1.push_back({1, a[cur]});
	for (int i = 0; i < mid; i++) dfs(sons[i], cur, a[cur], a[cur], 1, 1);
	for (int i = mid; i < sons.size(); i++) dfs(sons[i], cur, 0, 0, 0, 2);
	calc();
	a1.clear(), a2.clear();
	a2.push_back({a[cur], a[cur]});
	for (int i = 0; i < mid; i++) dfs(sons[i], cur, a[cur], a[cur], 1, 2);
	for (int i = mid; i < sons.size(); i++) dfs(sons[i], cur, 0, 0, 0, 1);
	calc();
	son[cur] = vector < int > {sons.begin() + mid, sons.end()};
	solve(cur, sum - csum);
	son[cur] = vector < int > {sons.begin(), sons.begin() + mid};
	solve(cur, csum + 1);
	son[cur] = sons;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		son[u].push_back(v);
		son[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	solve(1, n);
	cout << ans << endl;
}