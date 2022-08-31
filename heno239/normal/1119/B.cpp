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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod*mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

void solve() {
	int n; ll h; cin >> n >> h;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	int le = 0; int ri = n + 1;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		vector<ll> v;
		rep(i, mid)v.push_back(a[i]);
		sort(v.begin(), v.end());
		ll sum = 0;
		for (int j = mid - 1; j >= 0; j-=2) {
			sum += v[j];
		}
		//cout << mid << " " << sum << endl;
		if (sum <= h) {
			le = mid;
		}
		else ri = mid;
	}
	cout << le << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}