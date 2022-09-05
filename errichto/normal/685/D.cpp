#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

ll ans[nax];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<vi> w;
	REP(_, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		w.pb(vi{x-k, y, 101});
		w.pb(vi{x, y, 102});
	}
	sort(w.begin(), w.end());
	multiset<int> s;
	int x_prev = 13;
	for(vi & event : w) {
		int x = event[0];
		if(!s.empty() && x_prev != x) {
			int mul = x - x_prev;
			assert(mul > 0);
			int y_prev = 7;
			int cnt = 0;
			for(int y : s) {
				assert(cnt >= 0);
				if(cnt) ans[cnt] += (y/2 - y_prev) * mul;
				if(y%2) --cnt;
				else ++cnt;
				y_prev = y / 2;
			}
		}
		int y = event[1];
		int type = event[2];
		
		if(type == 101) {
			s.insert(2 * (y - k));
			s.insert(2 * (y) + (y >= 0 ? 1 : -1));
		}
		else {
			s.erase(s.find(2 * (y - k)));
			s.erase(s.find(2 * (y) + (y >= 0 ? 1 : -1)));
		}
		
		x_prev = x;
	}
	RI(i, n) printf("%lld ", ans[i]);
	puts("");
	return 0;
}