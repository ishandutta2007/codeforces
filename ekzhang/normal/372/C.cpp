#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define INF (1LL<<62)
#define MAXN 150013
#define MAXM 313
#define MAXLG 19
typedef long long LL;
int N, M, D;
LL A[MAXM], B[MAXM], T[MAXM];
LL ans = 0;
LL dp[MAXN];
LL rmq[MAXLG][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> D;
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i] >> T[i];
		ans += B[i];
		A[i]--;
	}

	LL ptime = -N;
	int ct = 0;
	for (int i = 0; i < M; i++) {
		ct ^= 1;
		LL dt = T[i] - ptime;
		ptime = T[i];
		LL mv = min((LL) N - 1, D * dt);
		for (int pos = 0; pos < N; pos++) {
			int s = max(0, pos - (int) mv);
			int e = min(N - 1, pos + (int) mv);

			int lg = 31 - __builtin_clz(e - s + 1);
			LL q = min(rmq[lg][s], rmq[lg][e - (1<<lg) + 1]);
			dp[pos] = q + abs(pos - A[i]);
		}
		for (int pos = 0; pos < N; pos++) {
			rmq[0][pos] = dp[pos];
		}
		for (int lg = 0; lg < MAXLG - 1; lg++) {
			for (int pos = 0; pos < N; pos++) {
				rmq[lg+1][pos] = rmq[lg][pos];
				if (pos + (1<<lg) < N) {
					rmq[lg+1][pos] = min(rmq[lg+1][pos], rmq[lg][pos + (1<<lg)]);
				}
			}
		}
	}

	ans -= rmq[MAXLG - 1][0];
	cout << ans << endl;
	return 0;
}