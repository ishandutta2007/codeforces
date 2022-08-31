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
map<int, int> mp;
int n;
int a[1 << 18];
vector<int> v,c;
int ma = 0;
bool can(int le, int ri) {
	int loc = 0;
	while (le <= ri) {
		if (loc == c.size())return false;
		if (c[loc] < ri)return false;
		ri >>= 1; loc++;
	}
	return true;
}
int maximum(int le) {
	int ri = le; int sum = le;
	while (ri * 2 <= ma) {
		ri <<= 1;
		sum += ri;
	}
	while (le <= ri) {
		if (can(le, ri))return sum;
		sum -= ri; ri >>= 1;
	}
	return 0;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		if (!mp[a[i]])v.push_back(a[i]);
		mp[a[i]]++;
		ma = max(ma, mp[a[i]]);
	}
	rep(i, v.size()) {
		c.push_back(mp[v[i]]);
	}
	sort(c.begin(), c.end(), greater<int>());
	int ans = 0;
	rep1(i, ma) {
		ans = max(ans, maximum(i));
	}
	cout << ans << endl;
	//cout << maximum(2) << endl;
	return 0;
}