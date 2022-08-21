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

//#define int long long
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
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct Node {
	Node *ch[26];
	int num;
	//

	Node() {
		rep(i, 26) {
			ch[i] = NULL;
		}
		num = 0;
	};
};
void add(Node* node, const string &s) {
	for (auto&& c : s) {
		int z = c - 'a';
		if (node->ch[z] == NULL)node->ch[z] = new Node();
		node = node->ch[z];
	}
	node->num++;
}
bool process(Node* &node,char t) {
	if (node->ch[t-'a'] == NULL) {
		return false;
	}
	node = node->ch[t-'a'];
	return true;
}

void Z_algorithm(const string &s, vector<int> &a) {
	int sz = s.size();
	a.resize(sz);
	a[0] = sz;
	int i = 1, j = 0;
	while (i < sz) {
		while (i + j < sz&&s[j] == s[i + j])++j;
		a[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < sz&&k + a[k] < j)a[i + k] = a[k], ++k;
		i += k; j -= k;
	}
}

const int sz = 400;

vector<int> loc[1 << 18];
ll dp[1 << 18][2];
void solve() {
	string t; cin >> t;
	int n; cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	int m = t.size();
	Node* nd = new Node();
	rep(i, n) {
		if (s[i].length() > sz) {
			string u = s[i] + t;
			vector<int> a;
			Z_algorithm(u, a);
			int len = s[i].size();
			Rep(j, len, u.size()) {
				if (a[j] >= len) {
					loc[j - len].push_back(len);
				}
			}
		}
		else {
			add(nd, s[i]);
		}
	}
	ll ans = 0;
	dp[0][0] = 1;
	rep(i, m) {
		rep(j, loc[i].size()) {
			//dp[i + loc[i][j]][0] += dp[i][1];
			dp[i + loc[i][j]][1] += dp[i][0];
			ans += dp[i][1];
		}
		Node* nnd = nd;
		rep1(j, sz) {
			if (i + j - 1 >= m)break;
			if (process(nnd, t[i + j - 1])) {
				int num = nnd->num;
				//dp[i + j][0] += dp[i][1] * num;
				dp[i + j][1] += dp[i][0] * num;
				ans += dp[i][1] * num;
			}
			else break;
		}
		dp[i + 1][0] += dp[i][0];
	}
	/*rep(i, m + 1) {
		cout << dp[i][0] << " " << dp[i][1] << endl;
	}*/
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}