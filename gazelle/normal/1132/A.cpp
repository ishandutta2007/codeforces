#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(int i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if(2 * a + b + c != b + c + 2 * d) {
		cout << 0 << endl;
		return 0;
	}
	if(c > 0) {
		if(a == 0) {
			cout << 0 << endl;
			return 0;
		} else {
			cout << 1 << endl;
			return 0;
		}
	} else {
		cout << 1 << endl;
		return 0;
	}
	return 0;
}
/* --------------------------------------- */