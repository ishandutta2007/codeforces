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
typedef long long  ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;


int nex[300000][19];

bool exi[300000][19];

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	rep(i, n)rep(j, 19)if (a[i] & (1 << j))exi[i][j] = true;
	rep(i, n)rep(j, 19)nex[i][j] = n;
	int loc[19][19];
	rep(i, 19)Rep(j, i + 1, 19)loc[i][j] = n;
	per(i, n) {
		bitset<19> b = 0;
		rep(j, 19)if (a[i] & (1 << j))b[j] = true;
		rep(j, 19)if (b[j])rep(k, 19)if (!b[k]) {
			if (j < k) {
				nex[i][k] = min(nex[i][k],loc[j][k]);
			}
			else {
				nex[i][k] = min(nex[i][k],loc[k][j]);
			}
		}
		rep(j, 19)Rep(k, j + 1, 19)if (b[j] && b[k])loc[j][k] = i;
	}

	rep(aa, q) {
		int l, r; cin >> l >> r; l--; r--;
		if (a[r] == 0 || a[l] == 0) {
			cout << "Fou" << endl; continue;
		}
		if (a[r] & a[l]) {
			cout << "Shi" << endl; continue;
		}
		bitset<19> b = 0;
		bitset<19> c = 0;
		rep(i, 19)if (a[r] & (1 << i))c[i] = true;
		rep(i, 19)if (a[l] & (1 << i))b[i] = true;
		string ans = "Fou";
		int to[19];
		rep(i, 19)if (!b[i]) {
			to[i] = nex[l][i];
		}
		while (l<r) {
			int mi = mod;
			rep(j, 19) {
				if (!b[j]) {
					if (to[j] < mi) {
						mi = to[j];
					}
				}
			}
			l = mi;
			if (l > r)break;
			rep(j, 19) {
				if (exi[l][j])b[j] = true;
			}
			rep(j, 19) {
				if (!b[j]) {
					to[j] = min(to[j], nex[l][j]);
				}
				else if (c[j]) {
					ans = "Shi"; l = n; break;
				}
			}
		}

		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}