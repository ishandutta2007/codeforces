#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;

ll T;
const int MAXN = 4e5;
int N;
ll A[MAXN];
ll S;
ll G;
ll R[MAXN];

ll inv(ll a, ll m) {
	return (a == 1) ? 1 : m - inv(m % a, a) * m / a;
}

ll gcd(ll a, ll b) {
	return __gcd(a, b);
}

unordered_map<ll, vector<pll>> mps;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	S = 0;
	for (int i = 0; i < N; i++) {
		S += A[i];
		S %= T;
	}

	A[0] = 0;
	for (int i = 1; i < N; i++) {
		A[i] = (A[i-1] + A[i]) % T;
	}
	A[N] = S;

	G = gcd(S, T);
	S /= G, T /= G;
	assert(S < T);
	if (S == 0) {
		unordered_set<ll> seen;
		for (int i = 0; i < N; i++) {
			if (!seen.count(A[i])) R[i] = 1;
			seen.insert(A[i]);
		}
	} else {
		S = (T - inv(S, T)) % T;

		for (int i = 0; i < N; i++) {
			ll bucket = A[i] % G;
			ll val = (A[i] / G) * S % T;
			mps[bucket].emplace_back(val, i);
		}
		for (auto &it : mps) {
			vector<pll> &v = it.second;
			sort(v.begin(), v.end());
			assert(!v.empty());
			ll last = 0;
			for (pll &a : v) {
				//cerr << a.first << ' ' << a.second << '\n';
				R[a.second] = a.first - last;
				last = a.first;
			}
			R[v[0].second] += T - last;
		}
	}
	for (int i = 0; i < N; i++){
		if (i) cout << ' ';
		cout << R[i];
	}
	cout << '\n';

	return 0;
}