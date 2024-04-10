
#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

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
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	vector<string> t;
	rep(i, p) {
		s.push_back('#');
	}
	int i = 0;
	while (i < n) {
		t.push_back(s.substr(i, p));
		i += p;
	}
	bool flag = true;
	rep(i, t.size()) {
		rep(j, t.size()) {
			if (i == j) {
				continue;
			}
			rep(k, p) {
				if (t[j][k] == '.' && t[i][k] == '.') {
					t[i][k] = '1';
					t[j][k] = '0';
					flag = false;
				}
				else if (t[i][k] == '.' && t[j][k] !='#') {
					if (t[j][k] == '1') {
						t[i][k] = '0';
					}
					else {
						t[i][k] = '1';
					}
					flag = false;
				}
				else if (t[j][k] == '.' && t[i][k] !='#') {
					if (t[i][k] == '1') {
						t[j][k] = '0';
					}
					else {
						t[j][k] = '1';
					}
					flag = false;
				}
				else if (t[i][k] != t[j][k] && t[i][k]!='#' && t[j][k]!='#') {
					flag = false;
				}
			}
		}
		if (!flag) {
			break;
		}
	}
	if (flag) {
		cout << "No" << endl;
	}
	else {
		rep(i, t.size()) {
			rep(j, t[i].size()) {
				if (t[i][j] == '#') {
					cout << endl;
					return 0;
				}
				if (t[i][j] == '.') {
					cout << '1';
				}
				else {
					cout << t[i][j];
				}
			}
		}
	}

}