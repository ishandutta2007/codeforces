#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll fact[200001], inv[200001];

ll modpow(ll b, ll p) {
	if (p == 0) return 1;
	ll t = modpow(b, p/2);
	ll t2 = (t*t)%MOD;
	if (p%2) return (t2*b)%MOD;
	else return t2;
}

ll modinv(ll x) {
	return modpow(x, MOD-2);
}

ll ncr(ll n, ll r) {
	return (((fact[n] * inv[r]) % MOD) * inv[n-r]) % MOD;
}

struct Point {
	ll value;
	int type;
};

bool cmp(const Point &a, const Point &b) {
	return a.value < b.value;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fact[i] = (i*fact[i-1])%MOD;
		inv[i] = modinv(fact[i]);
	}

	vector<Point> points;
	int n, k;
	cin >> n >> k;
	points.resize(2*n);
	for (int i = 0; i < n; i++) {
		cin >> points[2*i].value >> points[2*i+1].value;
		points[2*i].type = 1;
		points[2*i+1].type = -1;
	}
	sort(points.begin(), points.end(), cmp);
	int ans = 0;
	int prev, curr, temp;
	prev = curr = 0;
	for (int i = 0; i < 2*n; ) {
		int j;
		temp = 0;
		for (j = i; j < 2*n && points[j].value == points[i].value; j++) {
			if (points[j].type > 0)
				curr++;
			else
				temp++;
		}
		if (curr >= k) {
			if (prev >= k) {
				ans = (ans + ncr(prev, k)*(points[j-1].value - points[i-1].value - 1)%MOD) % MOD;
			}
			ans = (ans + ncr(curr,k)) % MOD;
		}
		curr -= temp;
		prev = curr;
		i = j;
	}
	cout << ans << endl;
	return 0;
}