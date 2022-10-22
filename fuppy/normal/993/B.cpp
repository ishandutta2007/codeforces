

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

/*
pair<vector<pii>, int> know(int n, vector<pii> a, int m, vector<pii> b) {
	bool flag = true;
	int cnt = 0;
	rep(i, n) {
		pii mine = a[i];
		bool f = false, s = false;
		rep(j, m) {
			if (mine == b[j]) {
				continue;
			}
			if (mine.first == b[j].first || mine.first == b[j].second) {
				f = true;
			}
			if(mine.second == b[j].first || mine.second == b[j].second) {
				s = true;
			}
		}
		if (f && s) {
			flag = false;
			return make_pair(false, 0);
		}
		else if ((f && !s) || (!f && s)) {
			cnt++;
		}
	}
	return make_pair(flag, cnt);
}
//*/

int know(pii mine, vector<pii> b) {
	bool f = false, s = false;
	int m = b.size();
	rep(j, m) {
		if (mine == b[j]) {
			continue;
		}
		if (mine.first == b[j].first || mine.first == b[j].second) {
			f = true;
		}
		if (mine.second == b[j].first || mine.second == b[j].second) {
			s = true;
		}
	}
	if (f && s) {
		return 0;
	}
	else if (f && !s) {
		return mine.first;
	}
	else if	(!f && s) {
		return mine.second;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pii> a(n), b(m);
	rep(i, n) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first > a[i].second) {
			swap(a[i].first, a[i].second);
		}
	}
	rep(i, m) {
		cin >> b[i].first >> b[i].second;
		if (b[i].first > b[i].second) {
			swap(b[i].first, b[i].second);
		}
	}
	vii hyou(n, vi(m, -1));
	rep(i, n) {
		rep(j, m) {
			pii f = a[i], s = b[j];
			if (f == s) {
				continue;
			}
			if (f.first == s.first || f.first == s.second || f.second == s.first || f.second == s.second) {
				int froma = know(f, b), fromb = know(s, a);
				if (froma*fromb == 0) {
					hyou[i][j] = 0;
					cout << -1 << endl;
					return 0;
				}
				else {
					hyou[i][j] = froma;
				}
			}
		}
	}
	vi cnt(10);
	rep(i, n) {
		rep(j, m) {
			if (hyou[i][j] > 0) {
				cnt[hyou[i][j]]++;
			}
		}
	}
	int ans = 0;
	rep(i, 10) {
		if (cnt[i]) {
			if (ans == 0) {
				ans = i;
			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;

}