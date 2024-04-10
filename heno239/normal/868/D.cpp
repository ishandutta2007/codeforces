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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

const int sz = 18;

struct strbl {
	string fr; string las;
	
};

vector<bool> exi[200][sz];
strbl sv[200];
void solve() {
	int n; cin >> n;
	rep(i, 200)rep(j, sz)exi[i][j].resize(1 << j,false);
	rep(i, n) {
		string s; cin >> s;
		sv[i].fr = sv[i].las = s;
		rep(j, s.size()) {
			int u = 0;
			int tmp = 0;
			Rep(k, j, s.size()) {
				tmp++;
				u *= 2;
				if (s[k] == '1')u++;
				exi[i][tmp][u] = true;
				if (tmp == sz-1)break;
			}
		}
	}
	int m; cin >> m;
	rep(i, m) {
		int l, r; cin >> l >> r; l--; r--;
		rep(j, sz)rep(k, (1 << j)) {
			exi[i + n][j][k] = (exi[l][j][k] | exi[r][j][k]);
		}
		string s = sv[l].las + sv[r].fr;
		rep(j, s.size()) {
			int u = 0;
			int tmp = 0;
			Rep(k, j, s.size()) {
				tmp++;
				u *= 2;
				if (s[k] == '1')u++;
				exi[i+n][tmp][u] = true;
				if (tmp == sz-1)break;
			}
		}
		sv[i + n].fr = sv[l].fr;
		if (sv[i + n].fr.size() < sz) {
			int dif = sz - sv[i + n].fr.size();
			dif = min(dif, (int)sv[r].fr.size());
			string u = sv[r].fr.substr(0, dif);
			sv[i + n].fr += u;
		}
		sv[i + n].las = sv[r].las;
		if (sv[i + n].las.size() < sz) {
			int dif = sz - sv[i + n].las.size();
			dif = min(dif, (int)sv[l].las.size());
			string u = sv[l].las.substr(sv[l].las.size() - dif, dif);
			sv[i + n].las = u + sv[i + n].las;
		}
		//cout << sv[i + n].fr << " " << sv[i + n].las << endl;
		int chk = -1;
		rep1(j, sz-1) {
			rep(k, (1 << j)) {
				if (!exi[i + n][j][k]) {
					chk = j-1; break;
				}
			}
			if (chk >= 0)break;
		}
		if (chk < 0)chk = 0;
		cout << chk << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	solve();
	//stop
	return 0;
}