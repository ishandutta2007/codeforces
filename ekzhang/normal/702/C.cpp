#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
int N, M;
int A[MAXN];
set<int> towers;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		towers.insert(x);
	}

	for (int i = 0; i < N; i++) {
		auto it = towers.lower_bound(A[i]);
		if (it != towers.end() && *it == A[i]) continue;
		int dist = numeric_limits<int>::max();
		if (it != towers.end()) {
			dist = min(dist, *it - A[i]);
		}
		if (it != towers.begin()) {
			dist = min(dist, A[i] - *(--it));
		}
		ans = max(ans, dist);
	}

	cout << ans << endl;
	return 0;
}