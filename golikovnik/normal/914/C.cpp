#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define endl '\n'
#define make_unique(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

const int N = 1111;
int zeros[N];
int counter[N];
const ll MOD = 1e9 + 7;
ll cnk[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	string n = read<string>();
	int k = read();
	for (int i = 0; i < N; ++i) {
		cnk[i][0] = cnk[i][i] = 1;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			cnk[j][i] = cnk[j - 1][i - 1] + cnk[j - 1][i] % MOD;
		}
	}
	counter[0] = counter[1] = 1;
	for (int i = 2; i < N; ++i) {
		int num = i;
		int cnt = 0;
		while (num) {
			cnt += num & 1;
			num /= 2;
		}
		counter[i] = counter[cnt] + 1;
	}
	if (!k) {
		cout << 1 << endl;
		return 0;
	}
	ll ans = counter[count(all(n), '1')] == k && n != "1";
	for (int i = 0; i < sz(n); ++i) {
		if (!i) {
			zeros[i] = n[i] == '1';
		} else {
			zeros[i] = zeros[i - 1] + (n[i] == '1');
		}	
	}
	for (int i = 0; i < sz(n); ++i) {
		if (n[i] == '1') {
			int positions = max(0, sz(n) - i - 1);
			for (int numberofzeros = 0; numberofzeros < positions + 1; ++numberofzeros) {
				if (!i && !numberofzeros) continue;
				int totalzeros = zeros[i] - 1 + numberofzeros;
				if (counter[totalzeros] == k) {
					ll res = cnk[positions][numberofzeros];
					ans += res;
					if (!i && totalzeros == 1) {
						--ans;
					}
					ans %= MOD;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}