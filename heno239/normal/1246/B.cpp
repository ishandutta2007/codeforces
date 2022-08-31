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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

const ll sup = 100000;

ll inf_pow(ll x, ll k) {
	ld z = (ld)k*log(x);
	if (z > 17)return INF;
	ll res = 1;
	while (k > 0) {
		if (k % 2)res = res * x;
		x = x * x; k >>= 1;
	}
	return res;
}
ll inf_multi(ll x, ll y) {
	ld z = log(x) + log(y);
	if (z > 17)return INF;
	return x * y;
}
vector<ll> powk;

bool isp[100001];
vector<int> ch[100001];

int k;
ll need[100001];
void init() {
	fill(isp + 2, isp + sup + 1, true);
	Rep1(i, 2, sup) {
		if (!isp[i])continue;
		ch[i].push_back(i);
		for (int j = 2 * i; j <= sup; j += i) {
			isp[j] = false;
			ch[j].push_back(i);
		}
	}
	rep1(i, sup) {
		ll s = 1;
		int cop = i;
		rep(j, ch[i].size()) {
			int cnt = 0;
			int d = ch[i][j];
			while (cop%d == 0) {
				cnt++; cop /= d;
			}
			cnt = k - cnt;
			cnt = (cnt%k + k) % k;
			ll u = inf_pow(d, cnt);
			s = inf_multi(s, u);
		}
		need[i] = s;
	}
}

ll cnt[1 << 17];
void solve() {
	int n; cin >> n >> k;
	init();
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i]; cnt[a[i]]++;
	}
	if (k > 35) {
		ll ans = 0;
		rep(i, n)if (a[i] == 1)ans++;
		ans = ans * (ans - 1) / 2;
		cout << ans << endl; return;
	}
	for (ll x = 1; x <= (1 << 17); x++) {
		ll z = inf_pow(x, k);
		if (z > sup)break;
		powk.push_back(z);
	}
	ll ans = 0;
	rep(i, n) {
		ll z = need[a[i]];
		//cout << a[i] << " " << z << endl;
		if (z > sup)continue;
		rep(j, powk.size()) {
			ll x = z * powk[j];
			if (x > sup)break;
			ans += cnt[x];
			if (x == a[i])ans--;
		}
		//cout << ans << endl;
	}
	cout << ans / 2 << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}