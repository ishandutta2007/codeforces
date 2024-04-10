#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013

int N, M;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	int ans = N;
	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		ans = min(ans, r - l + 1);
	}

	cout << ans << '\n';
	for (int i = 0; i < N; i++) {
		cout << (i % ans) << ' ';
	}
	cout << endl;
	return 0;
}