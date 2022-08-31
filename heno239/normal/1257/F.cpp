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
#include<utility>
#include<set>

using namespace std;

//#define int long long

using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll INF = (1e+18) + 100;
const ll mod = 998244353;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

struct Node {
	Node *ch[61];
	int memo;
	Node() {
		rep(i, 61)ch[i] = NULL;
		memo = 0;
	}
};
void add(Node* nd, vector<int> d, int id) {
	rep(i, d.size()) {
		int nex = d[i] + 30;
		if (nd->ch[nex] == NULL) {
			nd->ch[nex] = new Node();
		}
		nd = nd->ch[nex];
	}
	nd->memo = id;
}

void solve() {
	int n; cin >> n;
	vector<int> x(n);
	rep(i, n) {
		cin >> x[i];
	}
	Node* root = new Node();
	int m = (1 << 15);
	rep(i, (1 << 15)) {
		int sta = (x[0] % m) ^ i;
		int cnt = 0;
		rep(j, 15) {
			if (sta&(1 << j))cnt++;
		}
		vector<int> ds;
		rep1(j, n - 1) {
			int g = (x[j] % m) ^ i;
			int tmp = 0;
			rep(k, 15) {
				if (g&(1 << k))tmp++;
			}
			ds.push_back(cnt - tmp);
		}
		add(root, ds, i);
	}
	rep(i, (1 << 15)) {
		int sta = (x[0] / m) ^ i;
		int cnt = 0;
		rep(j, 15)if (sta&(1 << j))cnt++;
		Node* cop = root;
		bool valid = true;
		rep1(j, n - 1) {
			int g = (x[j] / m) ^ i;
			int tmp = 0;
			rep(k, 15)if (g&(1 << k))tmp++;
			int nex = 30 + tmp - cnt;
			if (cop->ch[nex] == NULL) {
				valid = false; break;
			}
			cop = cop->ch[nex];
		}
		if (valid) {
			int ans = i * m + cop->memo;
			cout << ans << endl; return;
		}
	}
	cout << -1 << endl; return;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	solve();
	//stop
		return 0;
}