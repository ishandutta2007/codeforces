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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[] = {4, 8, 15, 16, 23, 42};
	vector<int> p = {0, 1, 2, 3, 4, 5};
	int n12 = 0, n34 = 0, n15 = 0, n35 = 0;
	cout << "? 1 2" << endl;
	cin >> n12;
	cout << "? 3 4" << endl;
	cin >> n34;
	cout << "? 1 5" << endl;
	cin >> n15;
	cout << "? 3 5" << endl;
	cin >> n35;
	do {
		if(a[p[0]] * a[p[1]] != n12) continue;
		if(a[p[2]] * a[p[3]] != n34) continue;
		if(a[p[0]] * a[p[4]] != n15) continue;
		if(a[p[2]] * a[p[4]] != n35) continue;
		cout << "! ";
		REP(i, 6) {
			cout << a[p[i]];
			if(i != 5) cout << " ";
			else cout << endl;
		}
		return 0;
	} while(next_permutation(ALL(p)));
	return 0;
}
/* --------------------------------------- */