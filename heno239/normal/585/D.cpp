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

//struct cc {
//	int dif1, dif2, aval, id1, id2;
//	bool operator<(const cc &c)const {
//		if (dif1 != c.dif1 || dif2 != c.dif2) {
//			return vector<int>{ dif1, dif2 } < vector<int>{c.dif1, c.dif2};
//		}
//		return vector<int>{ c.aval,c.id1,c.id2 } < vector<int>{aval,id1,id2};
//
//	}
//};
struct aa {
	int aval, id1, id2;
	bool operator<(const aa &c)const {
		return vector<int>{ c.aval, c.id1, c.id2 } < vector<int>{aval, id1, id2};
	}
};
map<P, aa> mp;
int s[2][3] = {};

void solve() {
	int n; cin >> n;
	vector<vector<int>> v(n);
	rep(i, n) {
		v[i].resize(3);
		rep(j, 3)cin >> v[i][j];
	}
	int d = (n + 1) / 2; int d2 = n - d;
	int k = (1 << d2) - 1;

	rep(i, 3) {
		rep(j, d) {
			s[0][i] += v[j][i];
		}
		Rep(j, d, n) {
			s[1][i] += v[j][i];
		}
	}

	int plu = 300000000;
	rep(i, (1 << d2)) {
		int b = s[1][0];

		vector<int> r;
		rep(j, d2) {
			if (i&(1 << j)) {
				b -= v[d + j][0];
			}
			else {
				r.push_back(j + d);
			}
		}
		int len = r.size();
		rep(j, (1 << len)) {
			int bb = s[1][1], bc = s[1][2];
			int ss = 0;
			rep(k, len) {
				if (j&(1 << k)) {
					bb -= v[r[k]][1];
					ss += (1 << (r[k] - d));
				}
				else {
					bc -= v[r[k]][2];
				}
			}
			aa &a = mp[{bb - b, bc - b}];
			if (a.aval < b + plu) {
				mp[{bb - b, bc - b}] = { b + plu,i,ss };
			}
			//va.push_back(cc{ bb - b,bc - b,b,i,ss });
			//cout <<"hello "<< bb - b << " " << bc - b << endl;
		}
	}
	//sort(va.begin(), va.end());
	//vector<cc> cop;
	/*rep(i, va.size()) {
	if (i > 0&&va[i].dif1==va[i-1].dif1&&va[i].dif2==va[i-1].dif2) {
	continue;
	}
	cop.push_back(va[i]);
	}
	va = cop;*/
	/* rep(i, va.size()) {
	cout << va[i].dif1 << " " << va[i].dif2 << " " << va[i].aval << endl;
	}*/
	int ma = -mod; int chk1, chk2;
	int zz = (1 << d);
	rep(i, (1 << d)) {
		int b = s[0][0];

		vector<int> r;
		rep(j, d) {
			if (i&(1 << j)) {
				b -= v[j][0];
			}
			else {
				r.push_back(j);
			}
		}
		int len = r.size();
		rep(j, (1 << len)) {
			int bb = s[0][1], bc = s[0][2];
			int ss = 0;
			rep(k, len) {
				if (j&(1 << k)) {
					bb -= v[r[k]][1];
					ss += (1 << r[k]);
				}
				else {
					bc -= v[r[k]][2];
				}
			}
			int db = b - bb, dc = b - bc;
			//cout << db << " " << dc << endl;
			//cc ex = { db,dc,mod,mod,mod };
			//int id = lower_bound(va.begin(), va.end(), ex) - va.begin();
			//if (id == va.size())continue;
			//if (va[id].dif1 != db || va[id].dif2 != dc)continue;

			aa a = mp[{db, dc}];
			if (a.aval == 0)continue;
			int sum = a.aval + b - plu;
			if (sum > ma) {
				ma = sum; chk1 = i + zz * a.id1, chk2 = ss + zz * a.id2;
			}
		}
	}
	//cout << chk1 << " " << chk2 << endl;
	if (ma == -mod) {
		cout << "Impossible" << endl;
	}
	else {
		vector<vector<bool>> ans(n);
		rep(i, n) {
			ans[i].resize(3, true);
			if (chk1&(1 << i)) {
				ans[i][0] = false;
			}
			else if (chk2&(1 << i)) {
				ans[i][1] = false;
			}
			else {
				ans[i][2] = false;
			}
		}
		string anstool = "LMW";
		rep(i, n) {
			rep(j, 3) {
				if (ans[i][j])cout << anstool[j];
			}
			cout << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}