#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second


vector<int> G[1 << 18];
bool used[1 << 18];

vector<int> T[1 << 18];
void maketree(int v) {
	used[v] = true;
	rep(j, G[v].size()) {
		int to = G[v][j];
		if (used[to])continue;
		T[v].push_back(to);
		maketree(to);
	}
}
int b;

vector<int> ans;
void dfs(int v) {
	ans.push_back(v);
	rep(j, T[v].size()) {
		int to = T[v][j];
		dfs(to);
		ans.push_back(v);
	}
}

void solve() {
	int n, m; cin >> n >> m; int k; cin >> k;
	b = (2*n + k - 1) / k;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}
	maketree(0);
	dfs(0);

	rep(i, ans.size()) {
		if (T[ans[i]].size() == 0) {
			ans.erase(ans.begin(), ans.begin() + i);
			break;
		}
	}
	fill(used, used + n, false);
	int le = 0;
	rep(i, k) {
		while (le < ans.size()&&used[ans[le]])le++;
		vector<int> z;
		rep(j, b) {
			if (le == ans.size())break;
			used[ans[le]] = true;
			z.push_back(ans[le]); le++;

		}
		if (z.size()) {
			cout << z.size();
			rep(j, z.size()) {
				cout << " " << z[j] + 1;
			}
			cout << endl;
		}
		else {
			cout << "1 1" << endl;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}