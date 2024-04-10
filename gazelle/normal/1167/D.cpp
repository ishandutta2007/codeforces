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
#include<random>
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

map<int, vector<int>> ma;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int ng = 0, ok = 1000000000;
	while(abs(ok - ng) > 1) {
		int th = (ng + ok) / 2;
		vector<int> ans(n);
		int cr = 0, cb = 0;
		bool good = true;
		REP(i, n) {
			if(s[i] == '(') {
				if(cr < th) {
					cr++;
					ans[i] = 0;
				} else if(cb < th) {
					cb++;
					ans[i] = 1;
				} else {
					good = false;
				}
			} else {
				if(cr > 0) {
					cr--;
					ans[i] = 0;
				} else {
					cb--;
					ans[i] = 1;
				}
			}
		}
		if(good) ok = th;
		else ng = th;
		ma[th] = ans;
	}
	REP(i, n) cout << ma[ok][i];
	cout << endl;
	return 0;
}
/* --------------------------------------- */