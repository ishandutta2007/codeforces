#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int K = 30;
const int MOD = 1e9 + 7;
const int N = 3e5 + 100;

int mul(int a, int b) {
	return int((a * 1ll * b) % MOD);
}

int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}

int sub(int a, int b) {
	a -= b;
	return a < MOD ? a + MOD : a;
}

int p2[N + 1];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	p2[0] = 1;
	forn(i, N) {
		p2[i + 1] = mul(p2[i], 2);
	}
	
	int n;
	cin >> n;
	vi a(n);
	forn(i, n) {
		cin >> a[i];
	}
	
	vi b(K, 0);
	forn(i, n) {
		int t = 0;
		while(a[i] % 2 == 0) {
			t++;
			a[i] /= 2;
		}
		b[t]++;
	}
	vi pref(K + 1, 0);
	fornr(i, K) {
		pref[i] = pref[i + 1] + b[i];
	}
	int ans = 0;
	forn(i, K) {
//		cerr << i << " " << b[i] << " " << pref[i] << '\n';
		if (!i) {
			ans = add(ans, mul(p2[pref[i + 1]], sub(p2[b[i]], 1)));
		} else if (b[i]) {
			ans = add(ans, mul(p2[pref[i + 1]], sub(p2[b[i] - 1], 1)));
		}
	}
	cout << ans << '\n';
}