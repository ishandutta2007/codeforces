#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;


#define int long long

typedef long long ll;
typedef long double ld;

const int N = 5e4;

int p[N];

const int md = 998244353;


int sq2(ll x) {
	int l = 0, r = 2e9;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if ((ll)m * m <= x) l = m;
		else r = m;
	}
	return l;
}

int sq3(ll x) {
	int l = 0, r = 2e6;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if ((ll)m * m * m <= x) l = m;
		else r = m;
	}
	return l;
}

int sq4(ll x) {
	int l = 0, r = 40000;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if ((ll)m * m * m * m <= x) l = m;
		else r = m;
	}
	return l;
}

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    map <int, int> cnt;
    int n;
    cin >> n;
    vector <ll> bad;
    for (int i = 0; i < n; ++i) {
    	ll d;
    	cin >> d;
    	int a = sq2(d);
    	int b = sq3(d);
    	int c = sq4(d);
    	if ((ll)c * c * c * c == d) {
    		for (int i = 0; i < 4; ++i) ++cnt[c];
    	}
    	else if ((ll)b * b * b == d) {
    		for (int i = 0; i < 3; ++i) ++cnt[b];
    	}
    	else if ((ll)a * a == d) {
    		for (int i = 0; i < 2; ++i) ++cnt[a];
    	}
    	else {
    		bad.push_back(d);
    	}
    }
    vector <ll> ps;

    for (int i = 0; i < bad.size(); ++i) {
    	for (auto &p : cnt) {
    		if ((bad[i] % p.first) == 0) {
    			ps.push_back(p.first);
    			ps.push_back(bad[i] / p.first);
    		}
    	}
    }
	
	for (int i = 0; i < bad.size(); ++i) {
		for (int j = i + 1; j < bad.size(); ++j) {
			if (bad[i] != bad[j]) {
				ll c = gcd(bad[i], bad[j]);
				if (c != 1) ps.push_back(c);
			}
		}
	}
	vector <ll> js;
	for (auto p : ps) {
		for (int i = 0; i < bad.size(); ++i) {
			if ((bad[i] % p) == 0) {
				js.push_back(bad[i] / p);
			}
		}
	}
	for (auto x : js) ps.push_back(x);
	for (auto p : ps) {
		for (int i = 0; i < bad.size(); ++i) {
			if ((bad[i] % p) == 0) {
				bad[i] /= p;
				++cnt[p];
			}
		}
	}
	map <ll, int> kek;
	for (int i = 0; i < bad.size(); ++i) {
		if (bad[i] != 1) ++kek[bad[i]];
	}
	int ans = 1;
	for (auto p : cnt) {
		ans = mul(ans, p.second + 1);
	}
	for (auto p : kek) {
		ans = mul(ans, p.second + 1);
		ans = mul(ans, p.second + 1);
	}
	cout << ans << '\n';
}