#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

long long pw(long long a, long long b, long long mod) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

int inv(int a, int mod) {
	return pw(a, mod - 2, mod);
}

int main(){

	int m = nxt(), n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	if (n == m) {
		cout << "0 1\n";
		return 0;
	} else if (n == 1) {
		cout << a[0] << " 1\n";
		return 0;
	}

	bool rev = false;
	if (m < n + n) {
		sort(all(a));
		vector<int> b;
		int cur = 0;
		for (int i = 0; i < m; ++i) {
			if (cur < n && a[cur] == i) {
				++cur;
			} else {
				b.push_back(i);
			}
		}
		b.swap(a);
		n = a.size();
		rev = true;
	}

	set<int> S;
	for (int i = 0; i < n; ++i) {
		S.insert((a[i] - a[0] + m) % m);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (S.find((a[i] - a[1] + m) % m) != S.end()) {
			++cnt;
		}
	}

	int k = n - cnt;
	int d = 1ll * (a[1] - a[0] + m) * inv(k, m) % m;
	set<int> everything;
	for (int x : a) {
		everything.insert(x);
	}
	int x = a[0];
	cnt = 0;
	while (everything.find(x) != everything.end()) {
		++cnt;
		x = (x - d + m) % m;
	}
	int mn = (x + d) % m;
	x = (a[0] + d) % m;
	while (everything.find(x) != everything.end()) {
		++cnt;
		x = (x + d) % m;
	}
	if (cnt != n) {
		puts("-1");
	} else {
		cout << (rev ? x : mn) << " " << d << "\n";
	}

	return 0;
}