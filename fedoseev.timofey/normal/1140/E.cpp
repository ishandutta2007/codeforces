#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += md;
	return a;
}

int power(int a, ll b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) res = mul(a, res);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int k;

int get(vector <int> a) {
	int n = a.size();
	for (int i = 0; i + 1 < n; ++i) {
		if (a[i] != -1 && a[i] == a[i + 1]) return 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) cnt += (a[i] != -1);
	if (cnt == 0) {
		return mul(k, power(k - 1, n - 1));
	}
	int cur = 1;
	int l = 0;
	while (a[l] == -1) ++l;
	cur = mul(cur, power(k - 1, l));
	int r = n - 1;
	while (a[r] == -1) --r;
	cur = mul(cur, power(k - 1, n - r - 1));
	int last = l;
	for (int i = l + 1; i <= r; ++i) {
		if (a[i] != -1) {
			if (i != last + 1) {
				int fir = k - 1;
				int sec = (a[i] == a[last] ? 0 : 1);
				for (int j = last + 2; j < i; ++j) {
					int nfir = mul(fir, k - 1);
					int nsec = sub(fir, sec);
					fir = nfir;
					sec = nsec;
				}
				cur = mul(cur, sub(fir, sec));
			}
			last = i;
		}
	}
	return cur;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> fir, sec;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			fir.push_back(a[i]);
		}
		else {
			sec.push_back(a[i]);
		}
	}
	cout << mul(get(fir), get(sec)) << '\n';
}