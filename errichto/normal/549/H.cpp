#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1005;

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	ll a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	if(a * d == b * c) {
		puts("0");
		return 0;
	}
	if(a * d > b * c) {
		swap(a, b);
		swap(c, d);
	}
	ld low = 0, high = 1e12;
	REP(_, 10123) {
		ld med = (low + high) / 2;
		ld one = max({(a+med)*(d+med), (a-med)*(d+med), (a+med)*(d-med), (a-med)*(d-med)});
		ld two = min({(b+med)*(c+med), (b-med)*(c+med), (b+med)*(c-med), (b-med)*(c-med)});
		if(one < two) low = med;
		else high = med;
	}
	printf("%.10lf\n", (double) low);
	
	return 0;
}