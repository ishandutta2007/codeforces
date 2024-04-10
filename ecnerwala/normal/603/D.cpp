#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int MAXN = 3e3;

int N;
ll A[MAXN], B[MAXN], C[MAXN];

ll gcd(ll a, ll b) {
	while(a) {
		ll tmp = b % a;
		b = a;
		a = tmp;
	}
	return b;
}

pii simp(pii a) {
	ll g = gcd(abs(a.first), abs(a.second));
	a.first /= g, a.second /= g;
	return max(a, pii(-a.first, -a.second));
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N;
	int cnt0 = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i];
		if(C[i] == 0) {
			cnt0++;
			N --;
			i --;
		}
	}

	assert(cnt0 <= 2);

	ll res = 0;

	for(int i = 0; i < N; i++) {
		vector<pii> vals;
		ll d = A[i], e = B[i], f = C[i];
		for(int j = 0; j < N; j++) {
			if(i == j) continue;

			ll a = A[j], b = B[j], c = C[j];
			pii v(
					f * (a * a + b * b) - (d * a + e * b) * c,
					(e * a - d * b) * c
					);
			vals.push_back(v);
		}


		assert(int(vals.size()) == N - 1);
		for(int j = 0; j < N - 1; j++) {
			vals[j] = simp(vals[j]);
		}

		sort(vals.begin(), vals.end());

		ll cnt = 1;
		for(int j = 1; j < N - 1; j++) {
			if(vals[j] == vals[j - 1]) {
				res += cnt;
				cnt ++;
			} else {
				cnt = 1;
			}
		}
	}

	res /= 3;

	if(cnt0 == 2) res += N;

	cout << res << '\n';

	return 0;
}