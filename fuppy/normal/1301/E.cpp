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


int a[500][500][4], sum[501][501][4], num[500][500];
int sum2[501][501][501];


signed main() {
	fio();
	int h, w, q;
	cin >> h >> w >> q;
	vector<string> s(h);
	rep (i, h) {
		cin >> s[i];
	}

	map<char, int> mp;
	string color = "RYGB";
	rep (i, 4) mp[color[i]] = i;

	rep (i, h) {
		rep (j, w) {
			int k = mp[s[i][j]];
			a[i][j][k] = 1;
		}
	}

	rep (i, h) {
		rep (j, w) {
			rep (k, 4) {
				sum[i + 1][j + 1][k] = sum[i + 1][j][k] + a[i][j][k];
			}
		}
	}
	rep (i, h) {
		rep (j, w + 1) {
			rep (k, 4) {
				sum[i + 1][j][k] += sum[i][j][k];
			}
		}
	}

	// 
	// 
	vii num(h, vi(w));
	rep (i, h) {
		int l = 0, r = 0;
		int cnt = 0;
		while (l < w) {
			while (r < w and s[i][r] == 'R') r++;
			while (l < r) {
				int d = r - l;
				if (i + 2 * d > h or l + 2 * d > w) {
					l++;
					continue;
				}
				vi sx = {l, l + d}, sy = {i, i + d};

				int k = 0;
				bool flag = true;
				for (int x: sx) {
					for (int y: sy) {
						ll wa = sum[y + d][x + d][k] - sum[y][x + d][k] - sum[y + d][x][k] + sum[y][x][k];
						if (wa < d * d) {
							flag = false;
							break;
						}
						k++;
					}
				}
				if (flag) {
					num[i][l] = 2 * d;
				}
				l++;
			}
			if (l == r) {
				l++;
				r++;
			}
		}
	}
	//DEBUG_MAT(num);

	int d = min(h, w);
	//vector<vii> sum2(h + 1, vii(w + 1, vi(d + 1)));
	rep (i, h) {
		rep (j, w) {
			for (int k = 0; k <= d; k += 2) {
				sum2[i + 1][j + 1][k] = sum2[i + 1][j][k] + (num[i][j] == k);
			}
		}
	}

	rep (i, h) {
		rep (j, w + 1) {
			for (int k = 0; k <= d; k += 2) {
				sum2[i + 1][j][k] += sum2[i][j][k];
			}
		}
	}

	while (q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		y1--; x1--;
		ll ans = 0;
		int ok = 0, ng = (d + 10) / 2;
		while (ok + 1 < ng) {
			int mid = (ok + ng) / 2;
			int k = mid * 2;
			if (y2 - k < y1 or x2 - k < x1) {
				ng = mid;
				continue;
			}
			ll num = sum2[y2 - k + 1][x2 - k + 1][k] - sum2[y2 - k + 1][x1][k] - sum2[y1][x2 - k + 1][k] + sum2[y1][x1][k];
			if (num > 0) ok = mid;
			else ng = mid;
		}
		cout << ok * ok * 4 << '\n';
	}
}