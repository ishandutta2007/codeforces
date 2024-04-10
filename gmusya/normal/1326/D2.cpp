#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define ll long long

using namespace std;

const ll MAXN = 1e6 + 1;
const ll MOD1 = 1e9 + 123;
const ll MOD2 = 1e9 + 321;
const ll P = 31;

bool check(string &s, int l, int r, vector <ll> &hs, vector <ll> &hr, vector <ll> &p, ll MOD) {
	int n = s.size();;
	int sl = l, sr = r;
	int rl = n - 1 - r, rr = n - 1 - l;
	ll Hs = hs[r];
	if (sl > 0) Hs -= hs[sl - 1];
	Hs = (Hs % MOD + MOD) % MOD;
	Hs = (Hs * p[n - r]) % MOD;
	ll Hr = hr[rr];
	if (rl > 0) Hr -= hr[rl - 1];
	Hr = (Hr % MOD + MOD) % MOD;
	Hr = (Hr * p[n - rr]) % MOD;
	return (Hr == Hs);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <ll> p1(MAXN), p2(MAXN);
	p1[0] = p2[0] = 1;
	for (ll i = 1; i < MAXN; i++) {
		p1[i] = p1[i - 1] * P % MOD1;
		p2[i] = p2[i - 1] * P % MOD2;
	}
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		string t;
		int uk = 0;
		while (uk < n && s[uk] == s[n - uk - 1]) uk++;
		if (uk == n) {
			cout << s << endl;
			continue;
		}
		for (int i = uk; i < n - uk; i++)
			t += s[i];
		int m = t.size();
		vector <ll> h1_s(m), h2_s(m), h1_r(m), h2_r(m);
		h1_s[0] = h2_s[0] = p1[0] * (t[0] - 'a' + 1);
		for (ll i = 1; i < m; i++) {
			h1_s[i] = (h1_s[i - 1] + p1[i] * (t[i] - 'a' + 1)) % MOD1;
			h2_s[i] = (h2_s[i - 1] + p2[i] * (t[i] - 'a' + 1)) % MOD2;
		}
		reverse(t.begin(), t.end());
		h1_r[0] = h2_r[0] = p1[0] * (t[0] - 'a' + 1);
		for (ll i = 1; i < m; i++) {
			h1_r[i] = (h1_r[i - 1] + p1[i] * (t[i] - 'a' + 1)) % MOD1;
			h2_r[i] = (h2_r[i - 1] + p2[i] * (t[i] - 'a' + 1)) % MOD2;
		}
		reverse(t.begin(), t.end());
		pair <int, int> ans;
		for (int i = 0; i < m; i++) if (check(t, 0, i, h1_s, h1_r, p1, MOD1) && check(t, 0, i, h2_s, h2_r, p2, MOD2)) ans = max(ans, { i + 1, 0 });
		for (int i = m - 1; i >= 0; i--) if (check(t, i, m - 1, h1_s, h1_r, p1, MOD1) && check(t, i, m - 1, h1_s, h1_r, p1, MOD1)) ans = max(ans, { m - i, 1 });
		for (int i = 0; i < uk; i++)
			cout << s[i];
		if (ans.second == 0) for (int i = uk; i < uk + ans.first; i++) cout << s[i];
		else for (int i = m - ans.first; i < m; i++) cout << t[i];
		for (int i = n - uk; i < n; i++) cout << s[i];
		cout << endl;
	}
	return 0;
}