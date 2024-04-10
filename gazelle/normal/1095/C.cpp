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
	ll n, k;
	cin >> n >> k;
	bitset<32> bi(n);
	if(bi.count() > k || n < k) {
		cout << "NO" << endl;
		return 0;
	}
	stack<ll> q;
	REP(i, 32) if(bi[i]) {
		q.push((1ll << i));
	}
	cout << "YES" << endl;
	vector<ll> ans;
	while(!q.empty()) {
		ll num = q.top();
		q.pop();
		if(num == 1) {
			ans.pb(num);
			continue;
		}
		if((ll)ans.size() + (ll)q.size() + 1 < k) {
			q.push(num / 2);
			q.push(num / 2);
		} else ans.pb(num);
	}
	sort(ALL(ans));
	DUMP(ans);
	return 0;
}

/* --------------------------------------- */