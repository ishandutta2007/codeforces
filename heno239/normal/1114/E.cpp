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
random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<> rd3(0, 65535);
bool used[1 << 20];
int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int le = 0, ri = 1000000000;
	rep(i, 30) {
		int mid = (le + ri) / 2;
		cout << "> " << mid << endl;
		int z; cin >> z;
		if (z)le = mid;
		else ri = mid;
	}
	int ma = ri;
	int d = 0;
	rep(i, min(30,n)) {
		int r = (ll)rd3(mt)*mod%n;
		while (used[r]) {
			r = rd3(mt)*mod%n;
		}
		used[r] = true;
		cout << "? " << r + 1 << endl;
		int t; cin >> t;
		d = gcd(d, abs(t - ma));
	}
	cout << "! "<<ma - (n - 1)*d << " " << d << endl;
	//stop
	return 0;
}