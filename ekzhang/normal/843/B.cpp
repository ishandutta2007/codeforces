#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

int N, m, X;

pair<int, int> q(int idx) {
	cout << "? " << idx << endl;
	int a, b;
	cin >> a >> b;
	return {a, b};
}

void done(int ans) {
	cout << "! " << ans << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	srand(42);
	cin >> N >> m >> X;
	int mval = -1;

	for (int i = 0; i < 1000; i++) {
		int idx = ((rand() ^ (rand() << 16)) % N) + 1;
		int v = q(idx).first;
		if (v < X && v > mval) {
			m = idx, mval = v;
		}
	}

	for (int i = 0; i < 999; i++) {
		auto p = q(m);
		if (p.first >= X) done(p.first);
		m = p.second;
		if (m == -1) done(-1);
	}

	cout.flush();
	return 0;
}