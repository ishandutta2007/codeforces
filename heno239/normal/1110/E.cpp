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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n;
ll c[1 << 18], t[1 << 18];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> c[i];
	}
	rep(i, n) {
		cin >> t[i];
	}
	if (c[0] != t[0] || c[n - 1] != t[n - 1]) {
		cout << "No" << endl;
	}
	else {
		vector<ll> v, u;
		rep(i, n - 1) {
			v.push_back(c[i + 1] - c[i]);
			u.push_back(t[i + 1] - t[i]);
		}
		sort(v.begin(), v.end());
		sort(u.begin(), u.end());
		if (u == v)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	//stop
	return 0;
}