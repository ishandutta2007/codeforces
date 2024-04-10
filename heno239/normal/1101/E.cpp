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
typedef long long ll;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int ans[1 << 18];
typedef pair<P, int> speP;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int q; cin >> q;
	int lema = 0, rima = 0;
	rep(i, q) {
		char t; int x, y; cin >> t >> x >> y; if (x > y)swap(x, y);
		if (t == '+') {
			lema = max(lema, x);
			rima = max(rima, y);
		}
		else {
			if (x >= lema && y >= rima)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	//stop
	return 0;
}