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

int t[nax];
set<pii> se;

int main() {
	srand(42);
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &t[i]);
	int ans = 2;
	vector<pair<int,int>> w;
	REP(i,n)REP(j,n) if(i != j) w.push_back(mp(i,j));
	random_shuffle(w.begin(), w.end());
	multiset<int> s;
	REP(i, n) s.insert(t[i]);
	for(pii start : w) {
	//	puts("a");
		int a = t[start.st];
		int b = t[start.nd];
		if(se.find(mp(a,b)) != se.end()) continue;
		se.insert(mp(a,b));
	//	puts("x");
	//	printf("%d\n", (int) s.size());
		//for(int x : s) printf("%d ", x); puts("");
		//printf("> %d %d\n", a, b);
		s.erase(s.find(a));
		s.erase(s.find(b));
		int memo_a = a;
		int memo_b = b;
		int here = 2;
		//puts("");
		vi memo;
	//	puts("b");
		while(true) {
			//puts("a");
			int maybe = a + b;
			//printf("%d %d %d\n", a, b, maybe);
			auto it = s.find(maybe);
			if(it == s.end()) break;
			a = b;
			b = maybe;
			s.erase(it);
			memo.pb(maybe);
			se.insert(mp(a,b));
			++here;
			//puts("b");
		}
		for(int x : memo) s.insert(x);
		s.insert(memo_a);
		s.insert(memo_b);
		maxi(ans, here);
	//	puts("c");
	}
	printf("%d\n", ans);
	return 0;
}