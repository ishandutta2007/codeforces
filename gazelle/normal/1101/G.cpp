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
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	ll bxor = 0;
	vector<bitset<30>> v(n);
	REP(i, n) {
		bxor ^= a[i];
		bitset<30> bi(bxor);
		v[i] = bi;
	}
	if(v[n - 1].to_ullong() == 0) {
		cout << -1 << endl;
		return 0;
	}
	ll fi = 0;
	REP(i, 30) if(v[n - 1][i]) fi = i;
	REP(i, n - 1) {
		if(v[i][fi]) v[i] = v[i] ^ v[n - 1];
	}
	vector<bool> used(n, false);
	used[n - 1] = true;
	ll ans = 1;
	REP(i, 30) {
		if(i == fi) continue;
		REP(j, n) {
			if(used[j]) continue;
			if(v[j][i]) {
				ans++;
				used[j] = true;
				REP(k, n) {
					if(used[k]) continue;
					if(v[k][i]) v[k] = v[k] ^ v[j];
				}
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */