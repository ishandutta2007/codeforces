#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#ifndef LOK
#define cerr if(0) cout
#endif
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5, nax = 1e6 + 5;



int main() {
	int t[nax];
	int n, k;
	scanf("%d%d", &n, &k);
	RI(i, n) scanf("%d", &t[i]);
	vector<pii > res;
	while(k--) {
		RI(i, n) cerr << t[i] << " ";
		cerr << "\n";
		auto mi = min_element(t + 1, t + n + 1);
		auto ma = max_element(t + 1, t + n + 1);
		cerr << mi - t << " " << ma - t << "\n";
		cerr << *mi << " " << *ma << "\n";
		int a = mi - t, b = ma - t;
		if(*mi < *ma - 1) {
			res.pb(mp(b, a));
			t[b]--;
			t[a]++;
		}
	}
	auto mi = min_element(t + 1, t + n + 1);
	auto ma = max_element(t + 1, t + n + 1);
	printf("%d %d\n", *ma - *mi, (int) res.size());
	for(auto p : res) printf("%d %d\n", p.st, p.nd);
	return 0;
}