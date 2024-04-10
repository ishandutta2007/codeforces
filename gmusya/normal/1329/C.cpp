#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll n, g;
ll oldsz, newsz;
vector <ll> pd, newpd, can, a, ans;

void dfs1(ll v) {
	if (v > oldsz) return;
	if (2 * v <= oldsz) pd[2 * v] = pd[v] / 2;
	if (2 * v + 1 <= oldsz) pd[2 * v + 1] = pd[v] / 2;
	dfs1(v * 2);
	dfs1(v * 2 + 1);
}

void dfs2(ll v) {
	if (v > newsz) return;
	if (2 * v <= newsz) newpd[2 * v] = newpd[v] / 2;
	if (2 * v + 1 <= newsz) newpd[2 * v + 1] = newpd[v] / 2;
	dfs2(v * 2);
	dfs2(v * 2 + 1);
}

bool dfstry(ll v) {
	if (v > newsz) return true;
	if (!can[v]) return false;
	if (a[v * 2] > a[v * 2 + 1]) return dfstry(v * 2);
	else return dfstry(v * 2 + 1);
}

void dov(ll v) {
	if (a[v] == 0) return;
	can[v]--;
	if (a[v * 2] > a[v * 2 + 1]) {
		a[v] = a[v * 2];
		dov(v * 2);
		return;
	}
	a[v] = a[v * 2 + 1];
	dov(v * 2 + 1);
}

void solve(ll v) {
	if (v > oldsz) return;
	while (dfstry(v) && can[v]) {
		ans.push_back(v);
		dov(v);
	}
	solve(v * 2);
	solve(v * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		cin >> n >> g;
		oldsz = (1 << n) - 1, newsz = (1 << g) - 1;
		pd.assign(oldsz + 1, 0), newpd.assign(oldsz + 1, 0), can.assign(2 * oldsz + 3, 0), a.assign(2 * oldsz + 3, 0), ans.assign(0, 0);
		for (ll i = 1; i <= oldsz; i++) cin >> a[i];
		pd[1] = oldsz;
		dfs1(1);
		newpd[1] = newsz;
		dfs2(1);
		for (ll i = 1; i <= oldsz; i++) can[i] = pd[i] - newpd[i];
		solve(1);
		ll sum = 0;
		for (ll i = 1; i <= oldsz; i++) sum += a[i];
		cout << sum << endl;
		for (ll i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	}
	return 0;
}