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
#include<cassert>
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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string t;
	cin >> t;
	string s;
	REP(i, t.size()) {
		if(t[i] != 'a') s += t[i];
	}
	if((ll)s.size() % 2) {
		cout << ":(" << endl;
		return 0;
	}
	bool ok =true;
	REP(i, (ll)s.size() / 2) {
		if(s[i] != s[(ll)s.size() / 2 + i]) ok = false;
	}
	if(!ok) {
		cout << ":(" << endl;
		return 0;
	}
	REP(i, (ll)s.size() / 2) {
		if(t[(ll)t.size() - 1 - i] == 'a') ok = false;
	}
	if(!ok) {
		cout << ":(" << endl;
		return 0;
	}
	cout << t.substr(0, (ll)t.size() - (ll)s.size() / 2) << endl;
	return 0;
}
/* --------------------------------------- */