#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define int long long
#define MAX 200013
typedef pair<int, char> pic;
int N, M;
vector<pic> s, p;
int f[MAX];

void kmp() {
	f[0] = -1;
	int c = 0;
	for (int i = 1; i < M - 2; i++) {
		while (c && p[1+i] != p[1+c]) {
			c = f[c];
		}
		if (p[1+i] == p[1+c]) {
			c++;
		}
		f[i + 1] = c;
	}
}

 main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		int a = stoi(t.substr(0, t.size() - 2));
		char c = t[t.size() - 1];
		if (!s.empty() && s.back().second == c) {
			s.back().first += a;
		}
		else {
			s.emplace_back(a, c);
		}
	}
	for (int i = 0; i < M; i++) {
		string t;
		cin >> t;
		int a = stoi(t.substr(0, t.size() - 2));
		char c = t[t.size() - 1];
		if (!p.empty() && p.back().second == c) {
			p.back().first += a;
		}
		else {
			p.emplace_back(a, c);
		}
	}

	N = s.size();
	M = p.size();

	if (M == 1) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (s[i].second == p[0].second) {
				ans += max(0LL, s[i].first - p[0].first + 1);
			}
		}
		cout << ans << endl;
		return 0;
	}

	int st = 1;
	if (M == 2) {
		st = 0;
	}

	kmp();

	int ans = 0;
	int c = 0;
	for (int i = st; i < N - 1; i++) {
		while (c && s[i] != p[1+c]) {
			c = f[c];
		}
		if (s[i] == p[1+c]) {
			c++;
		}
		if (c == M - 2) {
			auto t1 = s[i - M + 2];
			auto t2 = s[i + 1];
			if (t1.second == p[0].second && t1.first >= p[0].first &&
				t2.second == p[M-1].second && t2.first >= p[M-1].first) {

				ans++;
			}
			c = f[c];
		}
	}

	cout << ans << endl;
	return 0;
}