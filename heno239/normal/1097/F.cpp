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
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

typedef bitset<7001> bt;

bt memo[100000];

bt for_query[7001];
bt for_set[7001];

void init() {
	vector<int> v;
	Rep1(i,2, 90) {
		v.push_back(i*i);
	}
	bool divsqr[7001] = {};
	rep1(i, 7000) {
		rep(j, v.size()) {
			if (i%v[j] == 0) {
				divsqr[i] = true; break;
			}
		}
	}
	rep1(i, 7000) {
		for (int j = i; j <= 7000; j += i) {
			if (!divsqr[j/i]) {
				for_query[i][j] = 1;
			}
			for_set[j][i] = 1;
		}
	}
}

void solve() {
	int n, q; cin >> n >> q;
	rep(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int x, v; cin >> x >> v; x--;
			memo[x] = for_set[v];
		}
		else if (t == 2) {
			int x, y, z; cin >> x >> y >> z; x--; y--; z--;
			memo[x] = memo[y] ^ memo[z];
		}
		else if (t == 3) {
			int x, y, z; cin >> x >> y >> z; x--; y--; z--;
			memo[x] = memo[y] & memo[z];
		}
		else {
			int x, v; cin >> x >> v; x--;
			int num = (memo[x] & for_query[v]).count();
			cout << num % 2;
			//cout << " is ans" << endl;
		}
	}
	cout << endl;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}