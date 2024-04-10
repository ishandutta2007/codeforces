#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;



int main(int argc, char * argv[]) {
	debug = argc > 1;
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	a = max(3*a/10, a - a*c/250);
	b = max(3*b/10, b - b*d/250);
	if(a == b) puts("Tie");
	else if(a < b) puts("Vasya");
	else puts("Misha");
	
	return 0;
}