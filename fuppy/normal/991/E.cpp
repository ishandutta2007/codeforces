#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl


typedef long long ll;
#define int ll
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

vi cnt(10);
ll ans = 0;
vll C(20, vl(20));


/*
void dfs(vi &now, int i0) {
	if (i0 == 10) {
		return;
	}
	if (now[i0] == 0) {
		dfs(now, i0 + 1);
		return;
	}
	int sum = 0;
	rep(i, 10) {
		sum += now[i];
	}
	ll res = 1;
	rep(i, 10) {
		if (now[i] == 0) {
			continue;
		}
		if (i == 0) {
			res *= C[sum - 1][now[i]];
			sum -= now[i];
		}
		else {
			res *= C[sum][now[i]];
			sum -= now[i];
		}
	}
	ans += res;
	//DEBUG(ans);
	if (now[i0] < cnt[i0]) {
		now[i0]++;
		dfs(now, i0);
		now[i0]--;
	}
	i0++;
	while (i0 < 10 && now[i0] >= cnt[i0]) {
		i0++;
	}
	if (i0 < 10) {
		now[i0]++;
		dfs(now, i0);
		now[i0]--;
	}
}
*/

void dfs(vi now, int i0) {
	if (i0 == 10) {
		int sum = 0;
		rep(i, 10) {
			sum += now[i];
		}
		ll res = 1;
		rep(i, 10) {
			if (now[i] == 0) {
				continue;
			}
			if (i == 0) {
				res *= C[sum - 1][now[i]];
				sum -= now[i];
			}
			else {
				res *= C[sum][now[i]];
				sum -= now[i];
			}
		}
		ans += res;
		return;
	}
	if (cnt[i0] == 0) {
		dfs(now, i0 + 1);
		return;
	}
	for (now[i0] = 1; now[i0] <= cnt[i0]; now[i0]++) {
		dfs(now, i0 + 1);
	}
}

signed main() {
	string s;
	cin >> s;
	C[0][0] = 1;
	rep1(i, 19) {
		rep(j, i + 1) {
			if (j == 0 || j == i) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}
	rep(i, s.size()) {
		cnt[s[i] - '0']++;
	}
	vi now(10);
	rep(i, 10) {
		if (cnt[i]) {
			now[i] = 1;
		}
	}
	dfs(now, 0);
	cout << ans << endl;
}