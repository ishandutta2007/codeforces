#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXPOW 520 // 512

int K;
bool ans[MAXPOW][MAXPOW];

void expand(int p) {
	int x = (1 << p);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			ans[i + x][j] = ans[i][j + x] = ans[i][j];
			ans[i + x][j + x] = !ans[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> K;
	ans[0][0] = true;
	for (int i = 0; i < K; i++) {
		expand(i);
	}

	for (int i = 0; i < (1 << K); i++) {
		for (int j = 0; j < (1 << K); j++) {
			cout << (ans[i][j] ? '+' : '*');
		}
		cout << '\n';
	}

	cout.flush();
	return 0;
}