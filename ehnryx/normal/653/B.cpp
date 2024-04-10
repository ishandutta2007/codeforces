#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 7;
unordered_set<string> cnt[N];
map<char,vector<string>> adj;

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	string s, t;
	for (int i=0; i<k; i++) {
		cin >> s >> t;
		adj[t[0]].push_back(s);
	}

	cnt[1].insert("a");
	for (int i=2; i<=n; i++) {
		for (const auto& it : cnt[i-1]) {
			for (const auto& pre : adj[it[0]]) {
				cnt[i].insert(pre + it.substr(1,i-1));
			}
		}
	}

	cout << cnt[n].size() << nl;

	return 0;
}