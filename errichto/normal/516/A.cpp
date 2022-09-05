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

int t[12];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int d;
	scanf("%d", &d);
	char sl[20];
	scanf("%s", sl);
	REP(i, d) {
		char z = sl[i] - '0';
		if(z == 2) t[2]++;
		if(z == 3) t[3]++;
		if(z == 4) {
			t[3]++;
			t[2] += 2;
		}
		if(z == 5) {
			t[5]++;
		}
		if(z == 6) {
			t[5]++;
			t[3]++;
		}
		if(z==7) t[7]++;
		if(z == 8) {
			t[7]++;
			t[2] += 3;
		}
		if(z == 9) {
			t[7]++;
			t[3] += 2;
			t[2]++;
		}
	}
	FORD(i, 9, 1) while(t[i]--) printf("%d", i);
	puts("");
	
	return 0;
}