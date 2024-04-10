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
typedef pair<int, int>P;
typedef pair<int, bool> sP;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void trans(string &s, int l, int r) {
	int len = r - l + 1;
	rep(i, len / 2) {
		swap(s[l + i], s[r - i]);
	}
}
void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int d = n / 2;
	string ans;
	rep(i, k - 1) {
		ans += "()";
	}
	int rest = n - (2 * (k - 1));
	rep(i, rest / 2)ans.push_back('(');
	rep(i, rest / 2)ans.push_back(')');
	vector<P> v;
	rep(i, n) {
		if (s[i] != ans[i]) {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == ans[i]) {
					v.push_back({ i,j });
					trans(s, i, j);
					break;
				}
			}
		}
	}
	cout << v.size() << "\n";
	rep(i, v.size()) {
		cout << v[i].first + 1 << " " << v[i].second + 1 << "\n";
	}
	//cout << s << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//stop
	return 0;
}