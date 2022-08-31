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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int k, n;
ll a[1 << 18];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
	}
	string s; cin >> s;
	ll ans = 0;
	rep(i, n) {
		int le = i;
		vector<ll> v; v.push_back(a[i]);
     	while (i + 1 < n&&s[i] == s[i + 1]) {
			i++; v.push_back(a[i]);
		}
		sort(v.begin(), v.end(), greater<ll>());
		rep(j, min(k, (int)v.size())) {
			ans += v[j];
		}
	}
	cout << ans << endl;
	//stop
	return 0;
}