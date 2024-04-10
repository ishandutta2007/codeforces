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

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

int n, m,q;


int num[2000][2000];

int ispl(int x, int y) {
	int cur = 1;
	while (x | y) {
		int chk = 0;
		rep(i, 30) {
			int k = 1 << i;
			if ((x&k) || (y&k))chk = k;
			else if (k > max(x, y))break;
		}
		if (x >= chk && y >= chk) {
			x -= chk; y -= chk;
		}
		else if (x >= chk) {
			x -= chk; cur ^= 1;
		}
		else if (y >= chk) {
			y -= chk; cur ^= 1;
		}
	}
	return cur;
}

//0-indexed
ll calc(int x, int y) {
	if (x < 0 || y < 0)return 0;
	ll ret = 0;
	ll d = x / (2 * n); ll rx = x % (2 * n);
	ret += d * n*(y+1);
	d = y / (2 * m); ll ry = y % (2 * m);
	//cout << "???" << endl;
	//cout << rx << " " << ry <<" "<<num[rx][ry]<< endl;
	ret += d * m*(rx+1);
	ll ad = 0;
	ll dx = x /  n; if (rx >= n)dx--;
	ll dy = y / m; if (ry >= m)dy--;
	int id = ispl(dx, dy);
	if (id) {
		ad = num[rx][ry];
	}
	else {
		ad = (rx + 1)*(ry + 1) - num[rx][ry];
	}
	//cout << "aaa " << id << " "<<ad << endl;
	ret += ad;
	return ret;
}

int mp[2000][2000];

void solve() {
	cin >> n >> m >> q;
	rep(i, n) {
		rep(j, m) {
			char t; cin >> t;
			int z = (t == '1');
			mp[i][j] = z;
			mp[i + n][j] = z ^ 1;
			mp[i][j + m] = z ^ 1;
			mp[i + n][j + m] = z;
		}
	}
	
	rep(i, 2*n) {
		rep(j, 2*m) {
			if (mp[i][j])num[i][j] = 1;
			if (i - 1 >= 0)num[i][j] += num[i - 1][j];
			if (j - 1 >= 0)num[i][j] += num[i][j - 1];
			if (i - 1 >= 0 && j - 1 >= 0)num[i][j] -= num[i - 1][j - 1];
		}
	}
	rep(i, q) {
		ll lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		lx--; ly--; rx--; ry--;
		//cout << calc(rx, ry) << endl;
		ll ans = calc(rx, ry) - calc(lx - 1, ry) - calc(rx, ly - 1) + calc(lx - 1, ly - 1);
		cout << ans << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
		return 0;
}