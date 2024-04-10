#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	string seq;
	cin >> seq;
	ll x, y;
	cin >> x >> y;
	if(abs(x) + abs(y) > n || (abs(x) + abs(y)) % 2 != n % 2) {
		cout << -1 << endl;
		return 0;
	}
	ll cx = 0, cy = 0;
	REP(i,n) {
		if(seq[i] == 'U') cy++;
		if(seq[i] == 'D') cy--;
		if(seq[i] == 'R') cx++;
		if(seq[i] == 'L') cx--;
	}
	if(x == cx && y == cy) {
		cout << 0 << endl;
		return 0;
	}
	ll l = 0, r = n;
	while(r - l > 1) {
		ll m = (l + r) / 2;
		ll ox = 0, oy = 0;
		FOR(i,m,n) {
			if(seq[i] == 'U') oy++;
			if(seq[i] == 'D') oy--;
			if(seq[i] == 'R') ox++;
			if(seq[i] == 'L') ox--;
		}
		bool det = false;
		REP(i,n-m+1) {
			if(abs(x - ox) + abs(y - oy) <= m && (abs(x - ox) + abs(y - oy)) % 2 == m % 2) {
				det = true;
				// cout << m << " " << i << endl;
			}
			if(i != n - m) {
				if(seq[i] == 'U') oy++;
				if(seq[i] == 'D') oy--;
				if(seq[i] == 'R') ox++;
				if(seq[i] == 'L') ox--;
				if(seq[m + i] == 'U') oy--;
				if(seq[m + i] == 'D') oy++;
				if(seq[m + i] == 'R') ox--;
				if(seq[m + i] == 'L') ox++;
			}
		}
		if(det) r = m;
		else l = m;
	}
	cout << r << endl;
	return 0;
}