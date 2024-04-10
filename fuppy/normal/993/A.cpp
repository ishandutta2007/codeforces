#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(ll)(n);i>0;i--)
#define REP(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const ll inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);



int main() {
	vii x(2, vi(4)), y(2, vi(4));
	rep(i, 2) {
		rep(j, 4) {
			cin >> x[i][j] >> y[i][j];
		}
	}
	vector<set<pii> > corner(2);
	rep(i, 2) {
		rep(j, 4) {
			corner[i].insert(pii(x[i][j], y[i][j]));
		}
	}
	vector<set<pii> > st(2);
	auto itr = corner[0].begin();
	itr++;
	int n = itr->second;
	itr--;
	n -= itr->second;
	int x0 = itr->first, y0 = itr->second;
	REP(i, x0, x0 + n + 1) {
		REP(j, y0, y0 + n + 1) {
			st[0].insert(pii(i, j));
		}
	}
	itr = corner[1].begin();
	x0 = itr->first; y0 = itr->second;
	itr = corner[1].end();
	itr--;
	int x1 = itr->first, y1 = itr->second;
	n = x1 - x0;
	int cnt = 0;
	REP(i, x0, x1 + 1) {
		REP(j, y0 - cnt, y0 + cnt + 1) {
			st[1].insert(pii(i, j));
		}
		if (i - x0 < n/ 2) {
			cnt++;
		}
		else {
			cnt--;
		}
	}

	/*
	rep(i, 2) {
		pii start = pii(x[i][0], y[i][0]);
		pii now = start;
		int j = 1;
		do {
			st[i].insert(now);
			DEBUG(now);
			int xdif = x[i][j] - now.first, ydif = y[i][j] - now.second;
			if (xdif == 0) {
				now.first += 0;
			}
			else {
				now.first += xdif / abs(xdif);
			}

			if (ydif == 0) {
				now.second += 0;
			}
			else {
				now.second += ydif / abs(ydif);
			}
			if (now == pii(x[i][j], y[i][j])) {
				j = (j + 1) % 4;
			}
		} while (now != start);
	}
	*/
	for (auto itr = st[0].begin(); itr != st[0].end(); itr++) {
		pii temp = *itr;
		if (st[1].count(temp)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}