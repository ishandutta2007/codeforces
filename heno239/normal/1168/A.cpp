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
typedef long long  ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int n,m;
vector<int> a;
bool can(int x) {
	int mi = 0;
	rep(i, n) {
		int r = a[i] + x;
		if (r < m) {
			if (mi > r) {
				return false;
			}
			mi = max(mi, a[i]);
		}
		else {
			r -= m;
			if (r >= mi) {
				//mi = max(mi, r);
				continue;
			}
			else {
				mi = max(mi, a[i]);
			}
		}
	}
	return true;
}
void solve() {
	cin >> n >> m;
	a.resize(n);
	rep(i, n) {
		cin >> a[i];
	}
	if (m == 1) {
		cout << 0 << endl; return;
	}
	int le = -1, ri = m;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		if (can(mid)) {
			ri = mid;
		}
		else {
			le = mid;
		}
	}
	cout << ri << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}