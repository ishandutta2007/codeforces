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

typedef bitset<1001> bt;
map<string, pair<bt,bt>> mp;
map<string, bool> used;


bt trans(string s) {
	bt res = 0;
	rep(i, s.size()) {
		res[i] = (s[i]=='1');
	}
	return res;
}
bool isnum(char t) {
	return t == '0' || t == '1';
}
void solve() {
	int n, m; cin >> n >> m;
	string s; getline(cin, s);
	vector<pair<bt, bt>> alv;
	rep(i, n) {
		getline(cin, s);
		string k; int loc;
		rep(j, s.size()) {
			if (s[j] == ' ') {
				loc = j + 1;
				k = s.substr(0, j);
				break;
			}
		}
		loc += 3;
		bool exi = false;
		string le, mi, ri;
		for (int j = loc; j < s.size(); j++) {
			if (s[j] == ' ') {
				exi = true;
				le = s.substr(loc, j - loc);
				for (int jj = j + 1; jj < s.size(); jj++) {
					if (s[jj] == ' ') {
						mi = s.substr(j + 1, jj - (j + 1));
						ri = s.substr(jj + 1, s.size() - (jj + 1));
					}
				}
				break;
			}
		}
		used[k] = true;
		if (!exi) {
			le = s.substr(loc, s.size() - loc);
			if (le == "?") {
				bt l;
				bt r;
				rep(j, m) {
					l[j] = 0, r[j] = 1;
				}
				mp[k] = { l,r };
			}
			else if (isnum(le[0])) {
				bt nex = trans(le);
				mp[k] = { nex,nex };
			}
			else {
				mp[k] = mp[le];
			}
			
		}
		else {
			pair<bt, bt> pl, pr;
			if (le == "?") {
				bt l;
				bt r;
				rep(j, m) {
					l[j] = 0, r[j] = 1;
				}
				pl = { l,r };
			}
			else if (isnum(le[0])) {
				bt b = trans(le);
				pl = { b,b };
			}
			else {
				pl = mp[le];
			}
			if (ri == "?") {
				bt l;
				bt r;
				rep(j, m) {
					l[j] = 0, r[j] = 1;
				}
				pr = { l,r };
			}
			else if (isnum(ri[0])) {
				bt b = trans(ri);
				pr = { b,b };
			}
			else {
				pr = mp[ri];
			}
			bt nexle, nexri;
			if (mi == "AND") {
				rep(j, m) {
					rep(l, 2) {
						nexle[j] = pl.first[j] & pr.first[j];
						nexri[j] = pl.second[j] & pr.second[j];
					}
				}
			}
			else if (mi == "OR") {
				rep(j, m) {
					rep(l, 2) {
						nexle[j] = pl.first[j] | pr.first[j];
						nexri[j] = pl.second[j] | pr.second[j];
					}
				}
			}
			else {
				rep(j, m) {
					rep(l, 2) {
						nexle[j] = pl.first[j] ^ pr.first[j];
						nexri[j] = pl.second[j] ^ pr.second[j];
					}
				}
			}
			mp[k] = { nexle,nexri };
		}
		alv.push_back(mp[k]);
	}
	string ansmi, ansma;
	rep(i, m) {
		int c[2] = {};
		rep(j, n) {
			if (alv[j].first[i])c[0]++;
			if (alv[j].second[i])c[1]++;
		}
		if (c[0] == c[1]) {
			ansmi.push_back('0');
			ansma.push_back('0');
		}
		else if (c[0] < c[1]) {
			ansmi.push_back('0');
			ansma.push_back('1');
		}
		else {
			ansmi.push_back('1');
			ansma.push_back('0');
		}
	}
	cout << ansmi << endl;
	cout << ansma << endl;
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