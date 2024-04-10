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
#define mp make_pair
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
	
	int x1, x2, a, b;
	scanf("%d%d%d%d", &x1, &x2, &a, &b);
	int roz = x2 - x1;
	if(a <= roz && roz <= b) {
		puts("FIRST");
		printf("%d\n", x2);
		return 0;
	}
	if(x1 < x2) {
		if(a <= 0) {
			puts("DRAW");
			return 0;
		}
		int s = a + b;
		if(roz % s == 0) {
			puts("SECOND");
			return 0;
		}
		else {
			if(a <= roz % s && roz % s <= b) {
				puts("FIRST");
				printf("%d\n", x1 + roz % s);
				return 0;
			}
			puts("DRAW");
			return 0;
		}
	}
	
	if(b >= 0) {
		puts("DRAW");
		return 0;
	}
	int s = -a - b;
	if(abs(roz) % s == 0) {
		puts("SECOND");
		return 0;
	}
	if(min(abs(a), abs(b)) <= abs(roz) % s && abs(roz) % s <= max(abs(a), abs(b))) {
		puts("FIRST");
		printf("%d\n", x1 - abs(roz) % s);
		return 0;
	}
	puts("DRAW");
	
	
	return 0;
}