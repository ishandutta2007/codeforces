#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXB = 12;
const int MAXL = 70;
ll dp[MAXB][MAXL][MAXB]; // b, l, d: base, len, digits: number of ways with d distinct digits
ll pref[MAXB][MAXL]; // b, l: number of things < b^l

void precomp() {
	for (int b = 2; b <= 10; b++) {
		dp[b][0][0] = 1;
		for (int l = 1; l < MAXL; l ++) {
			for (int d = 0; d <= b; d++) {
				dp[b][l][d] = d * dp[b][l-1][d-1] + (b-d) * dp[b][l-1][d+1];
				assert(l % 2 == d % 2 || dp[b][l][d] == 0);
			}
		}
		pref[b][0] = 0;
		pref[b][1] = 0;
		for (int l = 1; l+1 < MAXL; l++) {
			pref[b][l+1] = pref[b][l] + (b-1) * dp[b][l-1][1];
		}
		assert(pref[b][1] == 0);
	}
}

ll go(int b, ll a) {
	//cerr << "starting " << b << ' ' << a << '\n';
	ll res = 0;
	vector<int> d;
	for (;a; a /= b) {
		d.push_back(a % b);
	}
	reverse(d.begin(), d.end());
	int l = int(d.size());
	res += pref[b][l]; // all things smaller
	//cerr << "Pref res " << pref[b][l] << '\n';
	unsigned int mask = 0;
	for (int i = 0; i < l; i++) {
		//cerr << "digit " << d[i] << '\n';
		for (int v = 0; v < d[i]; v++) {
			if (i == 0 && v == 0) continue;
			res += dp[b][l-1-i][__builtin_popcount(mask ^ (1 << v))];
			//cerr << res << '\n';
		}
		mask ^= (1 << d[i]);
	}
	//cerr << res << '\n';
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);

	precomp();

	int Q; cin >> Q;
	for (int i = 0; i < Q; i++) {
		int b; ll l, r; cin >> b >> l >> r;
		cout << go(b, r+1) - go(b, l) << '\n';
	}

	return 0;
}