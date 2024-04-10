#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mp make_pair
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9;
const int nax = 4e6 + 5;

// int t[nax];

int dzielnik(ll a) {
	for(int i = 2; (ll) i * i <= a; ++i) if(a % i == 0) return i;
	return 0;
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	//for(int i = 2; i * i <= nax; ++i) if(t[i] == 0) 
	//	for(int j = i * i; j <= nax; j += i) t[j] = i;
	
	ll n;
	scanf("%lld", &n);
	int pom = dzielnik(n);
	if(n == 1 || pom == 0) {
		printf("1\n0\n");
		return 0;
	}
	int pom2 = dzielnik(n / pom);
	if(pom2 == 0) {
		puts("2");
		return 0;
	}
	printf("1\n%lld\n", (ll) pom * pom2);
	
	return 0;
}