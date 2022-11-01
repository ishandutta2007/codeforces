#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<math.h>
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
	string t1, t2;
	cin >> t1 >> t2;
	int h1 = stoi(t1.substr(0, 2)), m1 = stoi(t1.substr(3, 2));
	int h2 = stoi(t2.substr(0, 2)), m2 = stoi(t2.substr(3, 2));
	int dur = (h2 - h1) * 60 + (m2 - m1);
	int h = h1, m = m1;
	REP(i, dur / 2) {
		m++;
		if(m == 60) {
			m = 0;
			h++;
		}
	}
	string ans = "";
	if(h <= 9) ans += "0";
	ans += to_string(h);
	ans += ":";
	if(m <= 9) ans += "0";
	ans += to_string(m);
	cout << ans << endl;
	return 0;
}
/* --------------------------------------- */