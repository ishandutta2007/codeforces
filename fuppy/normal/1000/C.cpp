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
	int n;
	cin >> n;
	vl l(n), r(n);
	vl a;
	rep(i, n) {
		cin >> l[i] >> r[i];
		a.push_back(l[i]); a.push_back(r[i]);
	}
	sort(all(a));
	UNIQUE(a);
	map<ll, int> mp;
	rep(i, a.size()) {
		mp[a[i]] = i + 1;
	}
	vl sum(400010);
	vl sub(400010);
	rep(i, n) {
		sum[mp[l[i]]]++;
		sum[mp[r[i]]]--;
		sub[mp[l[i]] + 1]++;
		sub[mp[r[i]]]--;
	}
	rep1(i, sum.size() - 1) {
		sum[i] += sum[i - 1];
		sub[i] += sub[i - 1];
	}
	vl cnt(n + 1);
	//DEBUG_VEC(a);
	rep1(i, a.size() - 1) {
		cnt[sum[i] + sum[i - 1] - sub[i]]++;
		cnt[sum[i]] += (a[i] - 1 - a[i - 1]);
	}
	cnt[sum[a.size()] + sum[a.size() - 1] - sub[a.size()]]++;
	rep1(i, n) {
		cout << cnt[i] << " ";
	}
	cout << endl;
}