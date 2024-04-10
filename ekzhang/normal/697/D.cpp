#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013

int N;
int P[MAXN];
double dp[MAXN];
int sz[MAXN];
vector<int> ch[MAXN];

int dfs1(int n) {
	sz[n] = 1;
	for (int x : ch[n]) {
		sz[n] += dfs1(x);
	}
	return sz[n];
}

void dfs(int n) {
	// ok do the actual computation here :D
	for (int x : ch[n]) {
		dp[x] = dp[n] + (sz[n] - sz[x] + 1) / 2.0;
		dfs(x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	P[0] = -1;
	for (int i = 1; i < N; i++) {
		cin >> P[i];
		P[i]--;
		ch[P[i]].push_back(i);
	}

	dp[0] = 1.0;

	dfs1(0);
	// for (int i = 0; i < N; i++) {
	// 	error(P[i]);	
	// }
	dfs(0);

	for (int i = 0; i < N; i++) {
		cout << dp[i] << ' ';
	}

	cout << endl;
	return 0;
}