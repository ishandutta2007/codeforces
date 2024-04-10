#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<complex>

#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	bool d = false;
	vector<bool> a(26, false);
	vector<int> c(26, 0);
	REP(i, n) {
		++c[s[i] - 'A'];
	}
	REP(i, n) {
		if(!a[s[i] - 'A']) a[s[i] - 'A'] = true;
		int cnt = 0;
		REP(j, 26) {
			if(a[j]) ++cnt;
		}
		if(cnt > k) d = true;
		--c[s[i] - 'A'];
		if(c[s[i] - 'A'] == 0) a[s[i] - 'A'] = false;
	}
	if(d) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}