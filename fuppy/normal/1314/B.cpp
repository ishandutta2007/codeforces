#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
//#define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

int n, k;
int m;
vector<int> a;

vi calc(int l, int r) {
	if (l + 2 == r) {
		int cnt = (int)a[l] + (int)a[r - 1];
		vi res;
		if (cnt == 0) {
			res = {0, -1, -1, -1};
		}
		else if (cnt == 1) {
			res = {-1, 1, 1, -1};
		}
		else {
			res = {-1, -1, -1, 1};
		}
		return res;
	}

	vi s1 = calc(l, (l + r) / 2), s2 = calc((l + r) / 2, r);

	vi res(4, -1);
	rep (i, 4) {
		rep (j, 4) {
			if (s1[i] == -1 or s2[j] == -1) continue;
			int u1 = i & 1, u2 = j & 1;
			int v1 = (i & 2) >> 1, v2 = (j & 2) >> 1;
			rep (wu, 2) rep (wv, 2) {
				int nu, nv;
				if ((wu == 0 and u1) or (wu == 1 and u2)) nu = 1;
				else nu = 0;
				if ((wv == 0 and v1) or (wv == 1 and v2)) nv = 1;
				else nv = 0;

				int nnu = 0;
				if ((wu == 0 and u2) or (wu == 1 and u1)) nnu = 1;

				int num = s1[i] + s2[j];
				if (u1 or u2) num++;
				if (v1 or v2) num++;
				if (nv or nnu) num++;

				rep (wk, 2) {
					int nnv;
					if ((wk == 0 and nv) or (wk == 1 and nnu)) nnv = 1;
					else nnv = 0;

					int ni = 0;
					if (nu) ni += 1;
					if (nnv) ni += 2;
					chmax(res[ni], num);
				}
			}
		}
	}
	return res;
}

signed main() {
	fio();
	cin >> n >> k;
	m = pow(2, n);
	a.resize(m);
	//DEBUG(m);
	fill(all(a), 0);
	rep (i, k) {
		int x;
		cin >> x;
		x--;
		a[x] = 1;
	}
	//DEBUG_VEC(a);

	vi last = calc(0, m);
	for (int i = 1; i < 4; i++) last[i]++;
	int ma = 0;
	rep (i, 4) chmax(ma, last[i]);
	cout << ma << endl;
}