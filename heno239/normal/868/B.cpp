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

void solve() {
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	if (h == 12)h = 0;
	vector<int> g;
	g.push_back(5 * h);
	g.push_back(m);
	g.push_back(s);
	sort(g.begin(), g.end());
	g.erase(unique(g.begin(), g.end()), g.end());
	if (g.size() == 1) {
		cout << "YES" << endl;
	}
	else {
		int id1=g.size(), id2=g.size();
		t1 *= 5, t2 *= 5;
		rep(i, g.size()-1) {
			if (g[i] < t1&&t1 <= g[i+1]) {
				id1 = i;
			}
			if (g[i] < t2&&t2 <= g[i + 1]) {
				id2 = i;
			}
		}
		if (id1 == id2) {
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
	//cout << fixed << setprecision(9);
	solve();
	//stop
	return 0;
}