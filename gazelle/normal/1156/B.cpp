#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
#include<cassert>
using namespace std;
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	REP(testcase, t) {
		string s;
		cin >> s;
		int n = (int)s.size();
		vector<char> v1, v2;
		REP(i, n) {
			if((s[i] - 'a') % 2 == 0) v1.pb(s[i]);
			else v2.pb(s[i]);
		}
		if(v1.empty() || v2.empty()) {
			cout << s << endl;
			continue;
		}
		string ans = "";
		REP(i, v1.size()) REP(j, v2.size()) {
			if(ans != "") break;
			if(abs((int)(v1[i] - v2[j])) != 1) {
				ans += v1[i];
				ans += v2[j];
				v1.erase(v1.begin() + i);
				v2.erase(v2.begin() + j);
			}
		}
		if(ans == "") {
			cout << "No answer" << endl;
			continue;
		}
		REP(i, v1.size()) ans = v1[i] + ans;
		REP(i, v2.size()) ans += v2[i];
		cout << ans << endl;
	}
	return 0;
}
/* --------------------------------------- */