#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, v) for (auto &a : v)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

void solve() {
	string S; cin >> S;
	string T; cin >> T;
	reverse(all(S)); reverse(all(T));
	int p = 0;
	bool skip[26]; F0R(i, 26) skip[i] = false;
	trav(a, T) {
		if (skip[a-'A']) {
			cout << "NO" << nl; return;
		}
		while (p < sz(S)) {
			if (S[p] != a) {
				skip[S[p] - 'A'] = true;
			} else goto done;
			p++;
		}
		cout << "NO" << nl; return;
		done:
		;
		p++;
	}
	cout << "YES" << nl;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		solve();
	}
}