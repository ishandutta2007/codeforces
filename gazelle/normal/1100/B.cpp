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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	REP(i, m) cin >> a[i];
	ll cnt = 1;
	vector<ll> v1(n, 0);
	vector<ll> v2(m + 10, 0);
	v2[0] = n;
	REP(i, m) {
		a[i]--;
		v1[a[i]]++;
		v2[v1[a[i]]]++;
		if(v2[cnt] == n) {
			cnt++;
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << endl;
	return 0;
}

/* --------------------------------------- */