#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;

const int MAXN = 2e5;
int N;
int S[MAXN];
int T;
pii tickets[MAXN]; // person, location

ll fact(ll n) {
	ll res = 1;
	for(ll i = 1; i <= n; i++) {
		res *= i;
		res %= MOD;
	}
	return res;
}

ll exp(ll a, ll e) {
	ll res = 1;
	while(e) {
		if(e % 2) {
			res *= a;
			res %= MOD;
		}

		a *= a;
		a %= MOD;
		e /= 2;
	}
	return res;
}

ll inv(ll a) {
	return exp(a, MOD-2);
}

ll choose(ll n, ll r) {
	if(r < 0 || r > n) return 0;
	ll res = fact(n);
	res *= inv(fact(r));
	res %= MOD;
	res *= inv(fact(n - r));
	res %= MOD;
	return res;
}


ll go() {
	T = 0;
	for(int i = 0; i < N; i++) {
		if(S[i]) {
			tickets[T++] = pii(S[i], i);
		}
	}

	if(T == 0) {
		ll res = 1;
		for(int i = 0; i < (N - 1); i++) {
			res *= 2;
			res %= MOD;
		}
		return res;
	} else if (T == 1) {
		int loc = tickets[0].second;
		int num = tickets[0].first;
		if(num == 1) return choose(N - 1, loc);
		ll res = 0;
		if(loc >= num - 1) {
			res += choose(N - num, N - loc - 1);
		}
		if(N - loc - 1 >= num - 1) {
			res += choose(N - num, loc);
		}
		return res * exp(2, num - 2) % MOD;
	} else {
		sort(tickets, tickets + T);
		int loc1 = tickets[0].second;
		int num1 = tickets[0].first;
		int loc2 = tickets[1].second;
		int num2 = tickets[1].first;
		if(loc2 < loc1) {
			for(int i = 0; i < T; i++) {
				tickets[i].second = N - 1 - tickets[i].second;
			}
			loc1 = N - 1 - loc1;
			loc2 = N - 1 - loc2;
		}
		
		int left = loc2 - num2 + 1, right = loc2;

		if(left < 0) return 0;

		cerr << loc1 << ' '<< num1 << ' ' << loc2 << ' ' << num2 << '\n';

		ll res = 0;
		if(num1 - 1 <= right - loc1 - 1) {
			res += choose(num2 - num1 - 1, loc1 - left);
			cerr << "hello\n";
		} 
		if(num1 - 1 <= loc1 - left) {
			res += choose(num2 - num1 - 1, right - loc1 - 1);
			cerr << "hello2\n";
		}
		if(num1 == 1) {
			res *= inv(2), res %= MOD;
		} else {
			res *= exp(2, num1 - 2);
			res %= MOD;
		}

		cerr << res << '\n';


		int prv = num2;

		for(int i = 2; i < T; i++) {
			int loc = tickets[i].second;
			int num = tickets[i].first;

			if(loc < left) {
				res *= choose(num - prv - 1, left - loc - 1);
				res %= MOD;
				left = loc;
				right = loc + num - 1;
				if(right >= N) return 0;
			} else if(loc > right) {
				res *= choose(num - prv - 1, loc - right - 1);
				res %= MOD;
				right = loc;
				left = loc - num + 1;
				if(left < 0) return 0;
			} else {
				return 0;
			}
			prv = num;
			if(res == 0) return 0;
		}

		res *= choose(N - (right - left + 1), left);
		res %= MOD;

		return res;

	}

}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> S[i];

	cout << go() << '\n';
}