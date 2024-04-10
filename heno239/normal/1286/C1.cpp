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
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}

int to[101];
ll alf[101][26];
int xr[101];
void solve() {
	int n; cin >> n;
	if (n <= 3) {
		string ans;
		rep1(i, n) {
			cout << "? " << i << " " << i << endl;
			char t; cin >> t; ans.push_back(t);
		}
		cout << "! "<<ans << endl;
		return;
	}
	rep(i, n) {
		if (i < n / 2) {
			to[i] = n - 2 - i;
		}
		else {
			to[i] = n - 1 - i;
		}
	}
	cout << "? " << 1 << " " << n << endl;
	vector<vector<string>> v(n + 1);
	rep(i, n*(n + 1) / 2) {
		string s; cin >> s;
		v[s.size()].push_back(s);
	}
	rep1(i, n) {
		rep(j, v[i].size()) {
			rep(k, v[i][j].size()) {
				alf[i][v[i][j][k] - 'a']++;
			}
		}
	}
	for (int i = 1; i <= n / 2; i++) {
		rep(j, 26) {
			alf[n + 1 - i][j] = alf[n + 1 - i][j] / i * (i + 1);
		}
		vector<int> rest;
		rep(j, 26) {
			int dif =alf[n + 1 - i][j]-alf[n-i][j];
			rep(k, dif)rest.push_back(j);
		}
		assert(rest.size() == 2);

		xr[n - i] = rest[0] ^ rest[1];
		rep(j, 2) {
			int x = rest[j];
			rep1(k, n) {
				alf[k][x] -= i;
			}
		}
	}
	n--;
	cout << "? " << 1 << " " << n << endl;
	v.clear();
	v.resize(n + 1);
	//vector<vector<string>> v(n + 1);
	rep(i, n*(n + 1) / 2) {
		string s; cin >> s;
		v[s.size()].push_back(s);
	}
	rep1(i, n)rep(j, 26)alf[i][j] = 0;


	rep1(i, n) {
		rep(j, v[i].size()) {
			rep(k, v[i][j].size()) {
				alf[i][v[i][j][k] - 'a']++;
			}
		}
	}
	for (int i = 1; i <= n / 2; i++) {
		rep(j, 26) {
			alf[n + 1 - i][j] = alf[n + 1 - i][j] / i * (i + 1);
		}
		vector<int> rest;
		rep(j, 26) {
			int dif = alf[n + 1 - i][j] - alf[n - i][j];
			rep(k, dif)rest.push_back(j);
		}
		assert(rest.size() == 2);

		xr[i-1] = rest[0] ^ rest[1];
		rep(j, 2) {
			int x = rest[j];
			rep1(k, n) {
				alf[k][x] -= i;
			}
		}
	}
	cout << "? " << n+1 << " " << n+1 << endl;
	char t; cin >> t;
	int z = t - 'a';
	string out; out.resize(n + 1);
	int cur = n;
	out[cur] = 'a'+z;

	rep(i, n) {
		int nex = to[cur];
		z = xr[cur] ^ z;
		cur = nex;
		out[cur] = 'a'+z;
	}
	cout << "! " << out << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}