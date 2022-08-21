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

vector<string> query(vector<int> a) {
	cout << "next";
	rep(i, a.size()) {
		cout << " " << a[i];
	}
	cout << endl;
	int m; cin >> m;
	vector<string> ret(m);
	rep(i, m) {
		cin >> ret[i];
	}
	return ret;
}

bool same(vector<string> &s, int a, int b) {
	int len = s.size();
	int c1, c2;
	rep(i, len) {
		rep(j, s[i].size()) {
			int t = s[i][j] - '0';
			if (t == a)c1 = i;
			if (t == b)c2 = i;
		}
	}
	return c1 == c2;
}
vector<string> in;
void solve() {
	while (true) {
		query({ 0 });
		in=query({ 0,1 });
		if (same(in,0, 1))break;
	}
	vector<int> al(10);
	rep(i, 10)al[i] = i;
	while (true) {
		in = query(al);
		if (same(in, 0, 2))break;
	}
	cout << "done" << endl;
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