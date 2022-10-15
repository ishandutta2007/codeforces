#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200005
int N, A, B, C;
int T[MAXN];
bool K[MAXN]; // killed

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	cin >> A >> B >> C;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}
	sort(T, T + N);
	// A <= B <= C
	if (B > C) {
		swap(B, C);
	}
	if (A > B) {
		swap(A, B);
	}
	if (B > C) {
		swap(B, C);
	}

	if (T[N - 1] > A + B + C) {
		cout << -1 << endl;
		return 0;
	}

	// phase 1
	int ans = 0;
	int b = upper_bound(T, T + N, B + C) - T;
	for (int i = b; i < N; i++) {
		K[i] = true;
		ans++;
	}

	// phase 2
	int b1;
	int t = 0;
	for (b1 = b - 1; T[b1] > A + C; b1--) {
		K[b1] = true;
		ans++;
		if (A >= T[t]) {
			K[t] = true;
			t++;
		}
	}

	// phase 3
	int ef = upper_bound(T, T + N, B) - T - 1;
	int le = ef + 1;
	for (; T[b1] > C && T[b1] > A + B; b1--) {
		K[b1] = true;
		ans++;
		if (!K[ef]) {
			K[ef] = true;
			ef--;
		}
	}

	// final phase
	// not killed: [t, ef] and [le, b1]
	if (A + B > C) {
		for (; T[b1] > C && b1 >= le; b1--) {
			K[b1] = true;
			ans++;
			if (!K[le] && C >= T[le]) {
				K[le] = true;
				le++;
			}
			else {
				if (!K[ef]) {
					K[ef] = true;
					ef--;
				}
			}
		}
	}
	while (b1 >= le) {
		K[b1] = true;
		ans++;
		b1--;
		if (t > ef) {
			if (!K[le] && A + B >= T[le]) {
				K[le] = true;
				le++;
			}
		}
		else {
			if (!K[t] && A >= T[t]) {
				K[t] = true;
				t++;
			}
			if (!K[ef]) {
				K[ef] = true;
				ef--;
			}
		}
	}
	while (ef >= t) {
		ans++;
		K[ef] = true;
		ef--;
		if (ef < t) {
			break;
		}
		K[ef] = true;
		ef--;
		if (!K[t] && A >= T[t]) {
			K[t] = true;
			t++;
		}
	}

	cout << ans << endl;
	return 0;
}