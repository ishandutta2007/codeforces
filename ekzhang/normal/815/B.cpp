#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 200013
#define MOD 1000000007
LL N;
LL A[MAXN];
LL nck[MAXN];

LL modinv(LL x) {
	LL buf[31];
	buf[0] = x;
	for (int i = 0; i < 30; i++) {
		buf[i + 1] = (buf[i] * buf[i]) % MOD;
	}
	int p = MOD - 2;
	LL ret = 1;
	for (int i = 30; i >= 0; i--) {
		if ((1<<i) <= p) {
			p -= (1<<i);
			ret *= buf[i];
			ret %= MOD;
		}
	}
	return ret;
}

void calc_nck() {
	// calculate C(N-1, K) for all 0 <= k <= N - 1;
	nck[0] = 1;
	for (int i = 1; i <= N - 1; i++) {
		nck[i] = nck[i-1];
		nck[i] *= (N - i);
		nck[i] %= MOD;
		nck[i] *= modinv(i);
		nck[i] %= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	if (N == 1) {
		cout << A[0] << endl;
		return 0;
	}

	if (N % 2) {
		for (int i = 0; i < N - 1; i++) {
			if (i % 2 == 0) A[i] += A[i + 1];
			else A[i] += MOD - A[i + 1];
			A[i] %= MOD;
		}
		--N;
	}

	N /= 2;
	calc_nck();
	N *= 2;

	LL a = 0, b = 0;
	for (int i = 0; i < N; i += 2) {
		a += nck[i / 2] * A[i];
		a %= MOD;
	}
	for (int i = 1; i < N; i += 2) {
		b += nck[i / 2] * A[i];
		b %= MOD;
	}

	// error(a, b);

	LL ans = 0;
	if ((N / 2) % 2) {
		ans = a + b;
	}
	else {
		ans = a - b;
	}
	ans = (ans + MOD) % MOD;

	cout << ans << endl;
	return 0;
}