#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

const int logn = 20;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<vector<int> > t(logn, vector<int>(n));
	for (int i = 0; i < n; i++) cin >> a[i];
	int r = min_element(a.begin(), a.end()) - a.begin();
	t[0][r] = r;
	for (int i = 0, u, v; i < n - 1; i++)
	{
		cin >> u >> v; u--; v--;
		if (a[u] < a[v]) swap(u, v);
		t[0][u] = v;
	}
	for (int j = 1; j < logn; j++) for (int i = 0; i < n; i++) t[j][i] = t[j - 1][t[j - 1][i]];
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == r) continue;
		ll w = 1e18;
		for (int dist = 0; dist < logn; dist++)
		{
			w = min(w, a[t[dist][i]] * 1ll * (dist + 1) + a[i]);
		}
		ans += w;
	}
	cout << ans << "\n";
	return 0;
}