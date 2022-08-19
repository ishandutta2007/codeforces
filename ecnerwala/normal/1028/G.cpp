#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll V = 10004205361450474LL;
const ll MAXK = 1e4;

using state = pair<ll, ll>;

map<ll, ll> mem[7];

ll solveBig(int m) {
	assert(m >= 0);
	if (m == 0) return 0;
	ll r = solveBig(m-1);
	if (V / (MAXK + 1) <= r) {
		return V;
	}
	return min(MAXK + r * (MAXK + 1), V);
}

// returns the max we can check in m steps
ll dp(int m, ll l) {
	assert(m >= 0 && m <= 5);
	if (m == 0) return l-1;

	if (l >= MAXK) {
		return l + solveBig(m) - 1;
	}

	ll k = min(l, MAXK);
	if (mem[m].count(l)) return mem[m][l];

	// let's find how much we can solve with each query
	//cerr << m << ' ' << l << '\n';
	ll cur = l;
	for (int a = 0; cur <= V && a < k; a++) {
		ll g = dp(m-1, cur) + 1;
		cur = g + 1;
	}
	ll res;
	if (cur > V) {
		res = V;
	} else {
		res = dp(m-1, cur);
	}
	cerr << m << ' ' << l << ' ' << res << '\n';
	return mem[m][l] = res;
}

vector<ll> getGuesses(int m, ll l) {
	assert(m >= 0 && m <= 5);
	assert(m > 0);

	ll k = min(l, MAXK);

	// let's find how much we can solve with each query
	//cerr << m << ' ' << l << '\n';
	ll cur = l;
	vector<ll> guesses;
	for (int a = 0; cur <= V && a < k; a++) {
		ll g = dp(m-1, cur) + 1;
		if (g <= V) guesses.push_back(g);
		cur = g + 1;
	}
	return guesses;
}

void run(int m, ll l) {
	vector<ll> guesses = getGuesses(m, l);
	int k = int(guesses.size());
	assert(k <= l);
	assert(k <= MAXK);
	if (k == 0) {
		run(m-1, l);
		return;
	}
	cout << k;
	for (ll g : guesses) {
		cout << ' ' << g;
	}
	cout << endl;
	int res; cin >> res;
	if (res == -2) {
		// wrong answer
		exit(0);
	} else if (res == -1) {
		exit(0);
	} else {
		if (res == 0) {
			run(m-1, l);
		} else {
			assert(1 <= res && res <= k);
			run(m-1, guesses[res-1] + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	ll R = dp(5, 1);
	assert(R == V);
	run(5, 1);

	return 0;
}