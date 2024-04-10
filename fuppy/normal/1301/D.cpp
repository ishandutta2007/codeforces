#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
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


signed main() {
	fio();
	int h, w, k;
	cin >> h >> w >> k;
	if (k > 4 * h * w - 2 * h - 2 * w) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

	if (h == 1 or w == 1) {
		string t1, t2;
		if (h == 1) {
			t1 = "R";
			t2 = "L";
		}
		else {
			t1 = "D";
			t2 = "U";
		}
		if (w == 1) swap(h, w);
		cout << k << endl;
		rep (i, w - 1) {
			cout << 1 << " " << t1 << endl;
			k--;
			if (k == 0) break;
		}
		if (k > 0) {
			rep (i, w - 1) {
				cout << 1 << " " << t2 << endl;
				k--;
				if (k == 0) break;
			}
		}
		return 0;
	}

	vector<pair<int, string>> moves;
	moves.push_back({h - 1, "D"});
	moves.push_back({h - 1, "U"});
	rep (i, w - 1) {
		moves.push_back({1, "R"});
		moves.push_back({h - 1, "DLR"});
		moves.push_back({h - 1, "U"});
	}
	moves.push_back({w - 1, "L"});

	int i = 0;

	vi num;
	vector<string> ans;
	while (k > 0) {
		int x = moves[i].first * moves[i].second.size();
		if (x <= k) {
			k -= x;
			num.push_back(moves[i].first);
			ans.push_back(moves[i].second);
		}
		else {
			int y = moves[i].second.size();
			int z = k / y;
			if (z > 0) {
				num.push_back(z);
				ans.push_back(moves[i].second);
			}
			k %= y;
			if (k > 0) {
				num.push_back(1);
				ans.push_back(moves[i].second.substr(0, k));
				k = 0;
			}
		}
		i++;
	}

	cout << num.size() << endl;
	rep (i, num.size()) {
		cout << num[i] << " " << ans[i] << endl;
	}
}