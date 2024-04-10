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

char sl[15];

int f(int i) {
	return sl[i] - '0';
}

int main() {
	scanf("%s", sl);
	int n = f(1) + 10 * f(3) + 100 * f(4) + 1000 * f(2) + 10*1000 * f(0);
	ll ans = 1;
	REP(_, 5) ans = ans * n % 100000;
	vi w;
	REP(_, 5) {
		w.pb(int(ans % 10));
		ans /= 10;
	}
	reverse(w.begin(), w.end());
	for(int dig : w) printf("%d", dig);
	puts("");
	return 0;
}