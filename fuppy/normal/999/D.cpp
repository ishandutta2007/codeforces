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
	int n, m;
	cin >> n >> m;
	vl a(n);
	vl num(m);
	vector<set<int> > st(m);
	rep(i, n) {
		cin >> a[i];
		num[a[i] % m]++;
		st[a[i] % m].insert(i);
	}
	vl change(m);
	rep(i, 2 * m) {
		if (num[i % m] > n / m) {
			change[i % m] += num[i % m] - n / m;
			num[(i % m + 1) % m] += num[i % m] - n / m;
			num[i % m] = n / m;
		}
	}
	ll ans = 0;
	rep(i, m) {
		ans += change[i];
	}
	cout << ans << endl;
	int si;
	for (si = 0; si < n; si++) {
		if (change[si] == 0) {
			break;
		}
	}
	ll sum = 0;
	int prei = si;
	vii to(m);
	bool first = true;
	for (int i = (si + 1) % m; i != (si + 1) % m || first; i = (i + 1) % m) {
		first = false;
		//DEBUG(sum);
		//DEBUG(prei);
		//DEBUG(i);
		//DEBUG_VEC(change);

		if (sum > change[i]) {
			ll dif = sum - change[i];
			sum = change[i];
			change[i] = 0;
			while (dif) {
				if (change[prei] >= dif) {
					rep(_, dif) {
						to[prei].push_back(i);
					}
					change[prei] -= dif;
					dif = 0;
				}
				else {
					rep(_, change[prei]) {
						to[prei].push_back(i);
					}
					dif -= change[prei];
					change[prei] = 0;
					prei = (prei + 1) % m;
				}
			}
		}
		else {
			ll temp = change[i];
			change[i] -= sum;
			sum = temp;
		}
	}

	vi idx(m);
	rep(i, n) {
		if (idx[a[i] % m] >= to[a[i] % m].size()) {
			continue;
		}
		a[i] += (to[a[i] % m][idx[a[i] % m]++] - a[i] % m + m) % m;
	}
	rep(i, n) {
		cout << a[i] << " ";
	}
	cout << endl;
}