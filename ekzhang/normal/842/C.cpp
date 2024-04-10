#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 200013
#define MAXF 240
int N, M;
int A[MAXN];
vector<int> adj[MAXN];
int ans[MAXN];
int ct[MAXF];
vector<int> factors;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void dfs(int n, int p) {
	if (n) ans[n] = gcd(A[n], ans[p]);
	else ans[n] = 0;
	for (int v : adj[n]) if (v != p) {
		dfs(v, n);
	}
}

vector<int> factor(int n) {
	vector<int> ans;
	for (int d = 1; d <= n; d++) {
		if (n % d == 0) {
			ans.push_back(d);
		}
	}
	return ans;
}

void go(int n, int p) {
	for (int i = 0; i < M; i++) {
		if (A[n] % factors[i] != 0) {
			ct[i]--;
		}
	}

	int x = 0;
	for (int i = 0; i < M; i++) {
		if (ct[i] >= -1) {
			x = factors[i];
		}
	}

	ans[n] = max(ans[n], x);

	for (int v : adj[n]) if (v != p) {
		go(v, n);
	}

	
	for (int i = 0; i < M; i++) {
		if (A[n] % factors[i] != 0) {
			ct[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(0, -1);
	factors = factor(A[0]);
	M = factors.size();

	go(0, -1);

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}