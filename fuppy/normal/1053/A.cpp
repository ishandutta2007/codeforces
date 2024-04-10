
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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep1(i,n) for(int i=n;i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


void dfs(int i, int now, vl &yaku, vector<pii> &p) {
	if (i == p.size()) {
		yaku.push_back(now);
		return;
	}
	dfs(i + 1, now, yaku, p);
	rep(j, p[i].second) {
		now *= p[i].first;
		dfs(i + 1, now, yaku, p);
	}
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	if (k == 2) {
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << n << " " << 0 << endl;
		cout << 0 << " " << m << endl;
		return 0;
	}
	if (2 * n * m % k != 0) {
		cout << "NO" << endl;
		return 0;
	}
	ll seki = 2 * n * m / k;
	vector<pii> pm, pn;
	ll m2 = m, n2 = n;
	for (ll i = 2; i*i <= m; i++) {
		if (m2 % i == 0) {
			pm.push_back(pii(i, 0));
		}
		while (m2 % i == 0) {
			pm[pm.size() - 1].second++;
			m2 /= i;
		}
	}
	if (m2 > 1) {
		pm.push_back(pii(m2, 1));
	}
	for (ll i = 2; i*i <= n; i++) {
		if (n2 % i == 0) {
			pn.push_back(pii(i, 0));
		}
		while (n2 % i == 0) {
			pn[pn.size() - 1].second++;
			n2 /= i;
		}
	}
	if (n2 > 1) {
		pn.push_back(pii(n2, 1));
	}
	vl yakum, yakun;
	dfs(0, 1, yakum, pm);
	dfs(0, 1, yakun, pn);
	sort(all(yakum));
	sort(all(yakun));
	//DEBUG_VEC(yakum);
	//DEBUG_VEC(yakun);
	for (ll k = 1; k <= 2; k *= 2) {
		rep(i, yakum.size()) {
			rep(j, yakun.size()) {
				ll m3 = yakum[i] * yakun[j] * k;
				if (seki % m3 != 0) {
					continue;
				}
				ll n3 = seki / m3;
				if (m3 <= n && n3 <= m) {
					swap(m3, n3);
				}
				if (n3 <= n && m3 <= m) {
					ll x2 = n3, y3 = m3;
					ll x3 = 0, y2 = 0;
					cout << "YES" << endl;
					cout << 0 << " " << 0 << endl;
					cout << x2 << " " << y2 << endl;
					cout << x3 << " " << y3 << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}