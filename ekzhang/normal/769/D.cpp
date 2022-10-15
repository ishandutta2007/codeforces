#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

const int M = 1<<14; // 16384
int N, K;
long long c[M];

void FWHT(long long* A, bool inv=false) {
	for (int len = 1; 2 * len <= M; len <<= 1) {
		for (int i = 0; i < M; i += 2 * len) {
			for (int j = i; j < i + len; j++) {
				long long u = A[j], v = A[j + len];
				A[j] = u + v;
				A[j + len] = u - v;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < M; i++) {
			A[i] /= M;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		++c[x];
	}

	if (K == 0) {
		long long ans = 0;
		for (int i = 0; i < M; i++) {
			ans += c[i] * (c[i] - 1) / 2;
		}
		cout << ans << '\n';
		return 0;
	}

	FWHT(c);

	for (int i = 0; i < M; i++) {
		c[i] = c[i] * c[i];
	}

	FWHT(c, true);

	long long ans = 0;
	for (int i = 0; i < M; i++) {
		if (__builtin_popcount(i) == K) {
			// if (c[i]) error(i, c[i]);
			ans += c[i];
		}
	}

	cout << ans / 2 << '\n';
	return 0;
}