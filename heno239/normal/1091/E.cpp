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
typedef pair<ld, ld> LDP;
int a[1 << 19]; int n;
ll s[1 << 19];

int z;
ll cop[1 << 19];
ll cc[1 <<19];
//ax
int loc(ll x) {
	int id = upper_bound(cop, cop + z, x) - cop;
	return z - id;
}
bool valid = true;
int calcle() {
	int res = 0;
	rep1(i, z) {
		cc[i] += (ll)i*(i-1)-s[i];
		int id = loc(i);
		id = max(id, i);
		cc[i] += (ll)(id-i)*i; cc[i] += s[z] - s[id];
		if (cc[i] < 0) {
			ll dif = -cc[i];
			if (dif > i) {
				valid = false; return 0;
			}
			else {
				res = max(res, (int)dif);
			}
		}
		//cout << cc[i] << endl;
	}
	return res;
}
int b[1 << 19];ll cb[1 << 19]; ll sb[1 << 19];
//x-1
bool ok(int x) {
	rep(i, z) {
		b[i] = a[i];
		if (i < x)b[i]--;
	}
	sort(b, b + z,greater<int>());
	rep(i, z) {
		sb[i + 1] = sb[i] + b[i];
		cb[i] = b[z - 1 - i];
	}
	rep1(i, z) {
		ll cnt = 0;
		cnt -= sb[i];
		cnt += (ll)i * (i - 1);
		int id = lower_bound(cb, cb + z, i) - cb;
		id = z - id;
		id = max(id, i);
		cnt += (ll)(id - i)*i + sb[z] - sb[id];
		//cout << i << " " << cnt << endl;
		if (cnt < 0)return false;
	}
	return true;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll zz = 0;
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		zz += a[i]; zz %= 2;
	}
	sort(a, a + n,greater<int>());
	rep(i, n) {
		if (a[i])z = i + 1;
	}
	rep(i, z) {
		cop[i] = a[z - 1 - i];
		s[i + 1] = s[i] + a[i];
	}
	int le = calcle(); 
	if (le % 2 != zz)le++;
	//cout << le << endl;
	if (!valid) {
		cout << -1 << endl; return 0;
	}
	else {
		int ri = z;
		if (ri % 2 != zz)ri++;
		int lee = 0; int rii = (ri - le) / 2;
		while (rii - lee > 1) {
			int mid = (rii + lee) / 2; mid = mid * 2 + le;
			if (ok(mid))lee = (mid-le)/2;
			else rii = (mid-le)/2;
		}
		ri = 2 * rii + le;
		if (ri > z)ri -= 2;
		if (!ok(le)) {
			cout << -1 << endl;
			//cout << le << endl;
			//stop
			return 0;
		}
		if (!ok(ri))ri-=2;
		//cout << ri << endl;
		Rep1(i, le, ri) {
			if (i % 2 == zz) {
				if (i - le > 1)cout << " ";
				cout << i;
			}
		}
	}

	return 0;
}