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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

ll sum;
vector<ll> c;
void calc(int x) {
	c.clear();
	int k = sqrt(x);
	rep1(i, k) {
		if (x%i == 0) {
			if ((x / i - i) % 2)continue;
			ll t = (x / i - i) / 2;
			c.push_back(t*t);
		}
	}
	reverse(c.begin(), c.end());
}
vector<ll> ans;
ll a[1 << 17];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, n/2)cin >> a[i];
	rep(i, n / 2) {
		calc(a[i]);
		int id = upper_bound(c.begin(), c.end(), sum) - c.begin();
		if (id == c.size()) {
			cout << "No" << endl; return 0;
		}
		ans.push_back(c[id] - sum);
		ans.push_back(a[i]);
		sum += c[id] - sum + a[i];
	}
	cout << "Yes" << endl;
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}