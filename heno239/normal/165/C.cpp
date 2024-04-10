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
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

void solve() {
	int k; string s; cin >> k >> s;
	vector<int> ones;
	rep(i, s.size())if (s[i] == '1')ones.push_back(i);
	ll ans = 0;
	if (k > 0) {

		rep(i, ones.size()) {
			if (i + k > ones.size()) {
				break;
			}
			int pre = -1;
			if (i > 0)pre = ones[i - 1];
			int las = s.size();
			if (i + k < ones.size())las = ones[i + k];
			ll cl = ones[i] - pre;
			ll cr = las - ones[i + k - 1];
			ans += cl * cr;
			//cout << i << " " << cl << " " << cr << "\n";
		}
	}
	else {
		ones.insert(ones.begin(), -1);
		ones.push_back(s.size());
		rep(i, (int)ones.size() - 1) {
			ll len = ones[i + 1] - ones[i] - 1;
			ans += len * (len + 1) / 2;
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();

	solve();
	stop
		return 0;
}