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
	ll s, x;
	scanf("%lld%lld", &s, &x);
	ll memo_s = s;
	ll memo_x = x;
	vector<ll> w;
	int c = 0;
	for(int i = 0; i < 50; ++i) {
		ll tmp = 1LL << i;
		if(x & tmp) {
			s -= tmp;
			++c;
		}
		else w.pb(tmp * 2);
	}
	if(s < 0) {
		puts("0");
		return 0;
	}
	for(ll tmp : w) if(s & tmp) {
		//++c;
		s -= tmp;
	}
	if(s != 0) {
		puts("0");
		return 0;
	}
	ll answer = 1LL << c;
	if(memo_s == memo_x) answer -= 2;
	printf("%lld\n", answer);
	//printf("%lld\n", 1LL << c);
	//ll answer = 0;
	//printf("%lld\n", s);
	//for(ll tmp : w) printf("%lld ", tmp);
	//10111
	return 0;
}