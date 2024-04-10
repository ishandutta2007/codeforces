#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
int N, Q;
int A[MAXN];
int ans[MAXN][300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int k = 1; k < 300; k++) {
		for (int i = N - 1; i >= 0; i--) {
			if (i + A[i] + k >= N) {
				ans[i][k] = 1;
			}
			else {
				ans[i][k] = 1 + ans[i + A[i] + k][k];
			}
		}
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int P, K;
		cin >> P >> K;
		P--;
		if (K < 300) {
			cout << ans[P][K] << '\n';
		}
		else {
			int ans = 0;
			while (P < N) {
				P += A[P] + K;
				ans++;
			}
			cout << ans << '\n';
		}
	}

	cout.flush();
	return 0;
}