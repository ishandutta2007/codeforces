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

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<pii> w;
	REP(_, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		w.pb(mp(a, 0));
		w.pb(mp(b, 1));
	}
	sort(w.begin(), w.end());
	int curr = 0;
	vi ans;
	REP(i, sz(w)) {
		bool extra = false;
		bool notExtra = false;
		int x = w[i].st;
		if(curr >= k) {
			ans.pb(x);
			notExtra = true;
		}
		while(i < sz(w) && w[i].st == x) {
			if(w[i].nd) --curr;
			else ++curr;
			if(curr >= k) extra = true;
			++i;
		}
		if(curr >= k) {
			ans.pb(x);
			notExtra = true;
		}
		if(extra && !notExtra) {
			ans.pb(x);
			ans.pb(x);
		}
		--i;
	}
	assert(curr == 0);
	assert(sz(ans) % 2 == 0);
	vector<pii> write;
	
	REP(i, sz(ans)) {
		int a = ans[i];
		++i;
		while(i+1 < sz(ans) && ans[i] == ans[i+1]) i += 2;
		write.pb(mp(a, ans[i]));
	}
	
	printf("%d\n", sz(write));
	for(pii p : write) printf("%d %d\n", p.st, p.nd);
	return 0;
}