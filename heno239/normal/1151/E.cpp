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
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

int n;
vector<int> a;
vector<int> loc[1 << 17];


void solve() {
	cin >> n; a.resize(n); rep(i, n)cin >> a[i];
	rep(i, n) {
		loc[a[i]].push_back(i);
	}
	ll ans = 0;
	int c = 0;
	rep1(i, n) {
		rep(j, loc[i].size()) {
			int id = loc[i][j];
			c++;
			if (id - 1 >= 0 && a[id - 1] <= a[id])c--;
			if (id + 1 < n&&a[id + 1] < a[id])c--;
		}
		ans += c;
	}
	ll sum = ans;
	rep1(i, n) {
		//cout << i-1<<" "<<sum << endl;
		rep(j, loc[i].size()) {
			int id = loc[i][j];
			int le = -mod, ri = -mod;
			if (id - 1 >= 0) {
				le = a[id - 1];
			}
			if (id + 1 < n) {
				ri = a[id + 1];
			}
			if (le >= i&&ri > i) {
				int mi = min(le, ri), ma = max(le, ri);
				sum -= mi - i; sum += n + 1 - ma;
			}
			else if (le >= i) {
				sum -= le - i;
			}
			else if (ri > i) {
				sum -= ri - i;
			}
			else {
				sum -= n + 1 - i;
			}
		}
		ans += sum;
	}
	//cout << sum << endl;
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}