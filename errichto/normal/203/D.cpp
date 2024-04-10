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
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;



int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int a, c, odl;
	scanf("%d%d%d", &a, &c, &odl);
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	y = abs(y);
	int mnoznik = 2 * y;
	int mianownik = mnoznik * a;
	// a / 2 + x * odl / y
	// (ay + 2xodl) / 2y
	int pom = a * y + 2 * x * odl;
	if(pom < 0) pom = 2 * mianownik - (-pom) % (2 * mianownik);
	pom %= 2 * mianownik;
	if(pom >= mianownik) pom = 2 * mianownik - pom;
	printf("%.7lf ", (double) pom / mnoznik);
	
	mnoznik = y;
	mianownik = mnoznik * c;
	pom = z * odl;
	pom = 2 * mianownik - (-pom) % (2 * mianownik);
	pom %= 2 * mianownik;
	if(pom >= mianownik) pom = 2 * mianownik - pom;
	printf("%.7lf\n", (double) pom / mnoznik);
	//if(pom >= 0) pom %= 2 * ;
	//else pom = a * 2 * y - 1 - (-pom) % (a * 2 * y);
	//int pom = (a * y + 2 * x * odl) % (a * 2 * y)
	//printf("%Lf\n", a / 2.L + x * (ld) odl / -y);
	
	return 0;
}