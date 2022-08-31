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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	int ans = a.back();
	rep(i, n) {
		int id = n - 1;
		while (id > i) {
			if (a[id] % a[i] == 0) {
				id--; continue;
			}
			else {
				ans = max(ans, a[id] + a[i]);
				break;
			}
		}
	}
	per(i, n) {
		per(j, i) {
			if (a[i] + a[j] + a[j] <= ans)break;
			if (a[i] % a[j] == 0)continue;
			per(k, j) {
				if (a[i] + a[j] + a[k] <= ans)break;
				if (a[i] % a[k] == 0 || a[j] % a[k] == 0)continue;
				ans = max(ans, a[i] + a[j] + a[k]);
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	int q; cin >> q;
	rep(i, q) {
		solve();
	}
	//stop
		return 0;
}