#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXAB 100
int N, A, B;
int ans[MAXAB][MAXAB];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> A >> B;
	if (N > A * B) {
		cout << -1 << endl;
		return 0;
	}

	int cnt = 0;
	int d = 1;
	int ci = 0, cj = 0;
	while (cnt < N) {
		ans[ci][cj] = (++cnt);
		if (cj + d >= 0 && cj + d < B) {
			cj = cj + d;
		}
		else {
			ci++;
			d = -d;
		}
	}

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B - 1; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << ans[i][B - 1] << '\n';
	}

	cout.flush();
	return 0;
}