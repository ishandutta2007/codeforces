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
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

struct Node {
	Node *ch[2];
	Node() {
		ch[0] = ch[1] = NULL;
	}
};


int nex[81][2];

vector<int> valids;
bool valid[81];

bool canseni[81];
void init() {
	rep(i, 81) {
		rep(j, 2) {
			int to = i * 3 + j;
			to %= 81;
			nex[i][j] = to;
		}
	}
	rep(i, 81) {
		vector<int> b;
		int cop = i;
		rep(j, 4) {
			b.push_back(cop % 3); cop /= 3;
		}
		valid[i] = true;
		rep(j, 3) {
			if (b[j] == 2 && b[j + 1] != 2) {
				valid[i] = false;
			}
		}
		if (b == vector<int>{1, 1, 0, 0})valid[i] = false;
		if (b == vector<int>{1, 0, 1, 0})valid[i] = false;
		if (b == vector<int>{0, 1, 1, 1})valid[i] = false;
		if (b == vector<int>{1, 1, 1, 1})valid[i] = false;
		if (valid[i])valids.push_back(i);
		canseni[i] = (valid[i] && (b[3] == 2));
	}
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<ll> dp(81), cop(81);
	Node* root = new Node();
	vector<ll> ans(n);
	rep(i, n) {
		fill(dp.begin(), dp.end(), 0); dp[80] = 1;

		Node* nd = root;
		Rep(j, i, n) {
			int z = a[j];
			fill(cop.begin(), cop.end(), 0);
			rep(k, valids.size()) {
				int id = valids[k];
				if (canseni[id]) {
					//cout << i << " " << j << " " << id << endl;
					int to = nex[id][z];
					cop[to] += dp[id];
					if (valid[to]) {
						cop[80] += dp[id];
					}
				}
			}
			rep(k, valids.size()) {
				int id = valids[k];
				dp[id] = cop[id] % mod;
			}
			if (nd->ch[z] == NULL) {
				//cout << i << " " << j << " hello "<<dp[80] << endl;
				ans[j] += dp[80]; nd->ch[z] = new Node();
			}
			nd = nd->ch[z];
		}
	}
	rep(i, n - 1) {
		ans[i + 1] += ans[i];
		ans[i + 1] %= mod;
	}
	rep(i, n) {
		cout << ans[i] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	init();
	solve();

	//cout << "finish" << endl;
	//stop
		return 0;
}