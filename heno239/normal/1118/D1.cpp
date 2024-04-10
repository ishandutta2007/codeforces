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
const ll mod = 1000000007;
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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n;ll m;
ll a[1 << 18];
bool can(int x) {
	ll sum = 0;
	rep(i, n) {
		int d = i / x;
		sum += max((ll)0, a[i] - d);
	}
	return sum >= m;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	ll sum = 0;
	rep(i, n) {
		cin >> a[i]; sum += a[i];
	}
	sort(a, a + n,greater<ll>());
	if (sum < m) {
		cout << -1 << endl; return 0;
	}
	int le = 0, ri = n;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		if (can(mid))ri = mid;
		else le = mid;
	}
	cout << ri << endl;
	//stop
	return 0;
}