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
constexpr ll mod = 998244353;
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


bool isp[25000001];
vector<int> ps;

void init(int sup=25000000) {
	fill(isp + 2, isp + sup + 1, true);
	for (int i = 2; i <= sup; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j <= sup; j += i) {
			isp[j] = false;
		}
	}
}

ll count_prime(ll n) {
	if (n < ps.back()) {
		return upper_bound(all(ps), n) - ps.begin();
	}

	ll t = 1;
	while (t*t*t <= n) {
		t++;
	}
	t--;

	int loc = 0;
	rep(i, ps.size())if (ps[i] > t) {
		loc = i; break;
	}

	//cout << "! " << t <<" "<<loc<< "\n";
	vector<bool> used(t*t+1,false);
	vector<vector<int>> ids(loc);
	rep(i, loc) {
		for (int j = ps[i]; j <= t * t; j += ps[i]) {
			if (!used[j]) {
				used[j] = true;
				ids[i].push_back(j);
			}
		}
	}

	function<ll(ll,ll)> calc=[&](ll n,ll m)->ll{
		if (m == 0)return n;
		if (n <= t * t) {
			ll res = n;
			rep(i, m) {
				res -= upper_bound(all(ids[i]), n) - ids[i].begin();
			}
			return res;
		}
		else {
			return calc(n, m - 1) - calc(n / ps[m-1], m-1);
		}
	};


	ll ans = calc(n, loc) + loc;
	ans--;
	int las = ps.size();
	rep(i, ps.size()) {
		if ((ll)ps[i] * ps[loc] > n) {
			las = i; break;
		}
	}
	while (true) {
		while (loc<las && (ll)ps[loc] * ps[las-1]>n) {
			las--;
		}
		if (loc >= las)break;
		//cout << ps[loc] << " " << ps[las - 1] << "\n";
		ans -= las - loc;
		loc++;
	}
	return ans;
}


void solve() {
	ll n; cin >> n;
	ll ans = 0;
	rep(i, ps.size()) {
		if ((ll)ps[i] * ps[i] > n)break;
		ans += count_prime(n / ps[i]) - (i+1);
		//cout << n / ps[i] << " " << count_prime(n / ps[i]) << "\n";
	}
	rep(i, ps.size()) {
		ll c = (ll)ps[i] * ps[i] * ps[i];
		if (c > n)break;
		ans++;
	}
	cout << ans << "\n";
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	init();
	solve();
	stop
		return 0;
}