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
#define MOD 998244353LL
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
	ll n;
	cin >> n;
	vector<string> s(n);
	REP(i, n) cin >> s[i];
	ll cnt0 = 0;
	vector<ll> cnt1(505050, 0);
	vector<ll> cnt2(505050, 0);
	REP(i, n) {
		ll op = 0;
		REP(j, s[i].size()) {
			if(s[i][j] == '(') op++;
			else op--;
		}
		bool ok = true;
		if(op == 0) {
			op = 0;
			REP(j, s[i].size()) {
				if(s[i][j] == '(') op++;
				else op--;
				if(op < 0) ok = false;
			}
			if(ok) cnt0++;
		} else if(op > 0) {
			op = 0;
			REP(j, s[i].size()) {
				if(s[i][j] == '(') op++;
				else op--;
				if(op < 0) ok = false;
			}
			if(ok) cnt1[op]++;
		} else /* op < 0 */ {
			ll tmp = abs(op);
			op = tmp;
			REP(j, s[i].size()) {
				if(s[i][j] == '(') op++;
				else op--;
				if(op < 0) ok = false;
			}
			if(ok) cnt2[tmp]++;
		}
	}
	ll ans = cnt0 / 2;
	REP(i, 505050) ans += min(cnt1[i], cnt2[i]);
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */