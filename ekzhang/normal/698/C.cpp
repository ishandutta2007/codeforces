#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define double long double
#define MAXMASK 1050013
#define MAXN 20
int K, N;
double A[MAXN];
double dp[MAXMASK];
double ans[MAXN];
int nonzero = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		nonzero += (A[i] != 0);
	}

	if (nonzero <= K) {
		for (int i = 0; i < N; i++) {
			cout << (A[i] ? 1 : 0) << ' ';
		}
		cout << endl;
		return 0;
	}

	dp[0] = 1;
	for (int mask = 1; mask < (1<<N); mask++) {
		double denom = 0;
		for (int j = 0; j < N; j++) {
			if (!(mask & (1<<j))) {
				denom += A[j];
			}
		}
		for (int j = 0; j < N; j++) {
			if (mask & (1<<j)) {
				dp[mask] += dp[mask ^ (1<<j)] * (A[j] / (A[j] + denom));
			}
		}
		if (__builtin_popcount(mask) == K) {
			for (int j = 0; j < N; j++) {
				if (mask & (1<<j)) {
					ans[j] += dp[mask];
				}
			}
		}
	}

	cout << setprecision(16);
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	cout << endl;
	return 0;
}