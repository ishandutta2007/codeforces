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
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

void solve() {
	int n; ll x; cin >> n >> x;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	x = x * 8 / n;
	if (x > 19) {
		cout << 0 << endl; return;
	}
	int sup = (1 << x);
	//cout << "! " << sup << endl;
	int tmp = 0; int ri = 0;
	int ans = mod;
	rep(i, n) {
		while (tmp < sup&&ri<n) {
			tmp++; ri++;
			while (ri < n&&a[ri - 1] == a[ri])ri++;
		}
		int num = n - ri + i;
		//cout << i << " " << num <<" "<<ri<< endl;
		ans = min(ans, num);
		while (i+1 < n&&a[i + 1] == a[i])i++;
		tmp--;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}