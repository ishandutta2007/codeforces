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
const ll mod = (1e+9) + 7;
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
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n; ll a[1 << 18];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	ll ma1=0, ma2=0;
	ll sum = 0;
	rep(i, n) {
		cin >> a[i]; sum += a[i];
		if (ma1 < a[i]) {
			ma2 = ma1; ma1 = a[i];
		}
		else if (ma2 < a[i]) {
			ma2 = a[i];
		}
	}
	vector<int> ans;
	rep(i, n) {
		if(a[i]==ma1){
			ll csum = sum - a[i] - ma2;
			if (ma2 == csum) {
				ans.push_back(i);
			}
		}
		else {
			ll csum = sum - a[i] - ma1;
			if (ma1 == csum) {
				ans.push_back(i);
			}
		}
	}
	cout << (int)ans.size() << endl;
	rep(i, (int)ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i]+1;
	}
	cout << endl;
	return 0;
}