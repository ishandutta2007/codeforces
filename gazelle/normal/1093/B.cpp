#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
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
using P=pair<ll,ll>;
#define MOD 1000000000000000007LL
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
	ll t;
	cin >> t;
	REP(testcase, t) {
		string s;
		cin >> s;
		if(s.size() == 1) {
			cout << -1 << endl;
			continue;
		}
		bool ok = false;
		REP(i, s.size() - 1) {
			if(s[i] != s[(ll)s.size() - 1]) {
				ok = true;
				string ans = "";
				ans += s[i];
				ans += s.substr(0, i);
				ans += s.substr(i + 1, (ll)s.size() - 1 - i);
				cout << ans << endl;
				break;
			}
		}
		if(!ok) cout << -1 << endl;
	}
	return 0;
}

/* --------------------------------------- */