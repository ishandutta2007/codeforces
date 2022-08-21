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
const ll mod = (ll)(1e+9) + 7;
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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n; cin >> n;
	ll k = sqrt(n + 0.1);
	vector<ll> d;
	rep1(i, k) {
		if (n%i == 0) {
			d.push_back(i);
			d.push_back(n / i);
		}
	}
	sort(d.begin(), d.end());
	int len=unique(d.begin(), d.end())-d.begin();
	vector<ll> ans;
	rep(i, len) {
		ll z = n / d[i];
		ll calc = z;
		calc += z * (z - 1) / 2 * d[i];
		ans.push_back(calc);
	}
	sort(ans.begin(), ans.end());
	len = unique(ans.begin(), ans.end()) - ans.begin();
	rep(i, len) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout<<endl;
	return 0;
}