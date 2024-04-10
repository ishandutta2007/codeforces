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
const ld eps = 1e-3;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n; ll T;
ll a[1 << 18], t[1 << 18];
//xxT
bool can(int x) {
	vector<ll> v;
	rep(i, n) {
		if (x <= a[i])v.push_back(t[i]);
	}
	sort(v.begin(), v.end());
	if (v.size() < x)return false;
	ll sum = 0;
	rep(i, x) {
		sum += v[i];
	}
	return sum <= T;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> T;
	rep(i, n) {
		cin >> a[i] >> t[i];
	}
	int le = 1, ri = n;
	while (ri - le > 1) {
		int mid = (ri + le) / 2;
		if (can(mid))le = mid;
		else ri = mid;
	}
	while (ri > 0 && !can(ri)) {
		ri--;
	}
	vector<LP> v;
	rep(i, n) {
		if (ri <= a[i])v.push_back({ t[i],i });
	}
	sort(v.begin(), v.end());;
	cout << ri << endl;
	cout << ri << endl;
	rep(i, ri) {
		if (i > 0)cout << " ";
		cout << v[i].second + 1;
	}
	cout << endl;
	//stop
	return 0;
}