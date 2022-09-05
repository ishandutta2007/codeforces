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
	/*double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	double delta = b * b - 4 * a * c;
	double one = (-b - sqrt(delta)) / (2 * a);
	double two = (-b + sqrt(delta)) / (2 * a);
	if(one < two) swap(one, two);
	printf("%.10lf\n%.10lf\n", one, two);
	*/int a = 1;
	FOR(i,2,10) a = a * i / __gcd(a, i);
	int c = 0;
	REP(i, a) {
		bool ok = true;
		FOR(j,2,10) if(i % j == 0) ok = false;
		if(ok) ++c;
	}
	
	ll n;
	scanf("%lld", &n);
	ll ans = c * (n / a);
	n %= a;
	RI(i, (int) n) {
		bool ok = true;
		FOR(j,2,10) if(i % j == 0) ok = false;
		if(ok) ++ans;
	}
	printf("%lld\n", ans);
	return 0;
}