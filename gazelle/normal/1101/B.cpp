#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	ll n = s.size();
	ll lb = -1, rb = -1, lc = -1, rc = -1;
	REP(i, n) {
		if(s[i] == '[') {
			lb = i;
			break;
		}
	}
	for(ll i = n - 1; i >= 0; i--) {
		if(s[i] == ']') {
			rb = i;
			break;
		}
	}
	if(lb == -1 || rb == -1 || rb < lb) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = 2;
	for(ll i = lb; i <= rb; i++) {
		if(s[i] == ':') {
			lc = i;
			break;
		}
	}
	for(ll i = rb; i >= lb; i--) {
		if(s[i] == ':') {
			rc = i;
			break;
		}
	}
	if(lc == -1 || rc == -1 || lc == rc) {
		cout << -1 << endl;
		return 0;
	}
	ans += 2;
	for(ll i = lc; i <= rc; i++) {
		if(s[i] == '|') ans++;
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */