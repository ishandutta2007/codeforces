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
ll x[1000],y[1000],a[1000],b[1000];
map<LP, bool> mp; int n;
bool valid(LP k) {
	rep(i, n) {
		LP z = { k.first - x[i],k.second - y[i] };
		if (!mp[z])return false;
	}
	return true;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)cin >> x[i] >> y[i];
	rep(i, n) {
		cin >> a[i] >> b[i];
		mp[{a[i], b[i]}] = true;
	}
	rep(i, n) {
		LP z = { x[0] + a[i],y[0] + b[i] };
		if (valid(z)) {
			cout << z.first << " " << z.second << endl;
			break;
		}
	}
	return 0;
}