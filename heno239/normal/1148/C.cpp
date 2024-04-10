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
#include<cassert>
using namespace std;

typedef long long  ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000003;
typedef double ld;
typedef complex<ld> Point;
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
typedef vector<int> vec;


vector<int> p, inv;
vector<P> ans;
void swp(int i, int j) {
	ans.push_back({ i + 1,j + 1 });
	swap(p[i], p[j]);
	inv[p[i]] = i, inv[p[j]] = j;
}
void solve() {
	int n; cin >> n;
	p.resize(n), inv.resize(n);
	rep(i, n) {
		cin >> p[i]; p[i]--;
		inv[p[i]] = i;
	}
	int d = n / 2;
	rep(i, d - 1) {
		int l = d - 1 - i, r = d + i;
		if (inv[r]>=d) {
			swp(0, inv[r]); swp(0, r);
		}
		else {
			swp(inv[r], n - 1); swp(0, n - 1); swp(0, r);
		}
		if (inv[l] <= d - 1) {
			swp(inv[l], n - 1); swp(l, n - 1);
		}
		else {
			swp(0, inv[l]); swp(0, n - 1); swp(l, n - 1);
		}
	}
	if (p[0] != 0)swp(0, n - 1);
	//rep(i, n)cout << p[i] << endl;
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n)solve();
	solve();
	//stop
	return 0;
}