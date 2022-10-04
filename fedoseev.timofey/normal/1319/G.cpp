#include  <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(time(0));

const int P = rnd() % (int)1e9 + 10;
const int MA = 1e9 + 7, MB = 1e9 + 9;

int mul(int a, int b, int md) {
	return ((ll)a * b) % md;
}

void add(int &a, int b, int md) {
 	a += b;
 	if (a >= md) a -= md;
}

void sub(int &a, int b, int md) {
	a -= b;
	if (a < 0) a += md;
}

int power(int a, ll b, int md) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = mul(res, a, md);
		}
		b >>= 1;
		a = mul(a, a, md);
	}
	return res;
}

int inv(int a, int md) {
	return power(a, md - 2, md);
}

struct Hash {
	int a, b;
	Hash(int _a, int _b) {
		a = _a;
		b = _b;
	}
	Hash() {
		a = 0;
		b = 0;
	}
	Hash operator +(const Hash &other) const {
		int ra = a, rb = b;
		add(ra, other.a, MA);
		add(rb, other.b, MB);
		return Hash(ra, rb);
	}
	Hash operator -(const Hash &other) const {
		int ra = a, rb = b;
		sub(ra, other.a, MA);
		sub(rb, other.b, MB);
		return Hash(ra, rb);
	}

	bool operator ==(const Hash &other) const {
		return a == other.a && b == other.b;
	}	
}; 

void solve() {
	int n;
	cin >> n;
	string t;
	cin >> t;
	vector <int> pref(n + 1);
	for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + (t[i] == '0');
	vector <int> nz(n, n), pz(n, -1);
	for (int i = 0; i < n; ++i) {
		if (i > 0) pz[i] = pz[i - 1];
		if (t[i] == '0') pz[i] = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (i + 1 < n) nz[i] = nz[i + 1];
		if (t[i] == '0') nz[i] = i;
	}
	auto get = [&] (int l, int r) {
		assert(pref[r + 1] - pref[l] == 0);
		assert((r - l + 1) % 2 == 1);
		return Hash(power(P, pref[r + 1], MA), power(P, pref[r + 1], MB));
	};
	auto full_one = [&] (int l, int r) {
		return pref[r + 1] - pref[l] == 0;
	};

	vector <Hash> H(n + 1);
	int lst = -1;
	for (int i = 0; i < n; ++i) {
	 	if (t[i] == '1') {
	 		if (lst == -1) lst = i;
	 	}
	 	else {
	 		if (lst != -1) {
	 			int len = i - lst;
	 			if (len % 2 == 1) {
	 				auto p = get(lst, i - 1);
	 				H[i] = p;
	 			}
	 	 	}
	 	 	lst = -1;
	 	}
	}
	//cout << lst << endl;
	if (lst != -1 && (n - lst) % 2 == 1) {
		H[n] = get(lst, n - 1);
	}
	for (int i = 0; i < n; ++i) {
		H[i + 1] = H[i + 1] + H[i];
	}
	auto get_zero = [&] (int l, int r) {
		return pref[r + 1] - pref[l];  	
	};
	auto get_Hash = [&] (int l, int r) {
		if (full_one(l, r)) {
		 	if ((r - l + 1) % 2 == 1) return Hash(1, 1);
		 	else return Hash(0, 0);
		}
		Hash res = H[r + 1] - H[l];
		if (t[r] == '1') {
		 	int pl = pz[r] + 1;
		 	int pr = nz[r] - 1;
		 	if (pr == r && (pr - pl + 1) % 2 == 1) res = res - get(pl, pr);
		 	if ((r - pl + 1) % 2 == 1) res = res + get(pl, r);
		}
		if (t[l] == '1') {
			int pl = pz[l] + 1;
			int pr = nz[l] - 1;
			if ((pr - pl + 1) % 2 == 1) res = res - get(pl, pr);
			if ((pr - l + 1) % 2 == 1) res = res + get(l, pr);
		} 
		int cnt = pref[l];
		res.a = mul(res.a, inv(power(P, cnt, MA), MA), MA);
		res.b = mul(res.b, inv(power(P, cnt, MB), MB), MB);
		return res;
 	};
 	int q;
 	cin >> q;
 	while (q--) {
 	 	int a, b, len;
 	 	cin >> a >> b >> len;
 	 	--a, --b;
 	 	//cout << get_Hash(a, a + len - 1).b << ' ' << get_Hash(b, b + len - 1).b << endl;
 	 	if (get_zero(a, a + len - 1) == get_zero(b, b + len - 1) && get_Hash(a, a + len - 1) == get_Hash(b, b + len - 1)) {
 	 		cout << "Yes\n";
 	 	} else {
 	 	 	cout << "No\n";
 	 	}
 	}
}
                  
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}	
}