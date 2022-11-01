#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<pint> process(vector<pint>& v) {
	vector<pint> ret;
	REP(i, v.size()) swap(v[i].first, v[i].second);
	sort(ALL(v));
	REP(i, v.size()) swap(v[i].first, v[i].second);
	int idx = -1;
	REP(i, v.size()) {
		if(idx < v[i].first) {
			ret.pb(v[i]);
			idx = v[i].second;
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	map<int, vector<pint>> s;
	REP(i, n) {
		ll sum = 0;
		FOR(j, i, n) {
			sum += a[j];
			s[sum].pb({i, j});
		}
	}
	int ans = 0, idx = 0;
	for(auto v: s) {
		vector<pint> tmp = process(v.second);
		if((int)tmp.size() > ans) {
			ans = (int)tmp.size();
			idx = v.first;
		}
	}
	for(auto v: s) {
		vector<pint> tmp = process(v.second);
		if(v.first == idx) {
			cout << (int)tmp.size() << endl;
			REP(i, tmp.size()) {
				cout << tmp[i].first + 1 << " " << tmp[i].second + 1 << endl;
			}
			break;
		}
	}
	return 0;
}

/* --------------------------------------- */