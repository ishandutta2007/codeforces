#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MOD 1000000007
#define MAXN 1000013
int N, K;
LL f[MAXN];
LL finv[MAXN];
LL A[MAXN];
LL B[MAXN];

LL modinv(LL x) {
	LL A[31];
	A[0] = x;
	for (int i = 0; i < 30; i++) {
		A[i + 1] = (A[i] * A[i]) % MOD;
	}

	LL ret = 1;
	for (int i = 0; i <= 30; i++) {
		if ((1<<i) & (MOD - 2)) {
			ret = (ret * A[i]) % MOD;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	finv[0] = 1; // 0!^-1 = 1^-1 = 1
	f[0] = 1;
	for (int i = 1; i <= N; i++) {
		finv[i] = (finv[i - 1] * modinv(i)) % MOD;
		f[i] = (f[i - 1] * i) % MOD;
	}

	A[0] = B[0] = 1;
	LL cur = 1;
	LL fact = 1;
	for (int n = 1; n <= N - 1; n++) {
		A[n] = (cur * fact) % MOD;
		fact = (fact * n) % MOD;
		if (n - K >= 0) {
			cur = (cur + MOD - B[n - K]) % MOD;
		}
		B[n] = (A[n] * finv[n]) % MOD;
		cur = (cur + B[n]) % MOD;
		// error(A[n]);
	}

	LL ans = 0;
	for (int k = 0; k < N; k++) {
		LL cur = B[k];
		cur *= f[N - 1];
		cur %= MOD;
		ans = (ans + cur) % MOD;
	}

	ans = (f[N] - ans + MOD) % MOD;

	cout << ans << endl;
	return 0;
}