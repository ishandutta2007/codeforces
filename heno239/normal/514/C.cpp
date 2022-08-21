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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct Node {
	Node *ch[3];
	//

	Node() { rep(i, 3)ch[i] = NULL; };
};
void add(Node* node, const string &s) {
	for (auto&& c : s) {
		int t = c - 'a';
		if (node->ch[t] == NULL)node->ch[t] = new Node();
		node = node->ch[t];
	}
}
bool dfs(Node* node, string &s, int i,int j) {
	if (i == s.size())return j == 1;
	int t = s[i] - 'a';
	bool ret = false;
	rep(k, 3) {
		if (node->ch[k] == NULL)continue;
		if (k != t) {
			if (j == 1)continue;
			bool b = dfs(node->ch[k], s, i + 1, j + 1);
			if (b)ret = b;
		}
		else {
			bool b = dfs(node->ch[k], s, i+1, j);
			if (b)ret = b;
		}
	}
	return ret;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<string> s(n), t(m);
	Node* nd = new Node();
	rep(i, n) {
		cin >> s[i];
		add(nd, s[i]);
	}
	rep(i, m) {
		cin >> t[i];
		if (dfs(nd, t[i], 0, 0)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}