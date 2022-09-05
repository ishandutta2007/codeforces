#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
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
const int nax = 105;

int cel;
bool tak[nax][nax];

bool f(int n) {
	// printf("%d\n", n);
	RI(i,n) RI(j,n) tak[i][j] = false;
	assert(n % 2 == 1);
	int mam = 0;
	int k = (n+1)/2;
	RI(i, n) RI(j, n) if((i+j)%2 != cel % 2 &&
		(
		cel % 2 == 0 || !(abs(i-k)+abs(j-k) == 1)
		)
	) {
		tak[i][j] = true;
		++mam;
	}
	//printf("%d %d\n", cel, mam);
	if(cel > mam) return false;
	assert(cel % 2 == mam % 2);
	while(mam > cel) {
		bool pyklo = false;
		if(mam >= cel + 4) {
			RI(i, n/2) RI(j, n/2) if(tak[i][j]) {
				mam -= 4;
				tak[i][j] = false;
				i = inf;
				j = inf;
				pyklo = true;
			}
		if(!pyklo) RI(j, n/2) if(!pyklo) if(tak[(n+1)/2][j]) {
				mam -= 2;
				tak[(n+1)/2][j] = false;
				pyklo = true;
			}
		}
		if(!pyklo) RI(i,n/2) if(!pyklo) if(tak[i][(n+1)/2]) {
			mam -= 2;
			tak[i][(n+1)/2] = false;
			pyklo = true;
		}
		if(!pyklo) return false;
	}
	//if(cel % 2 == 1 && (n+1)/2-1 >= 1 && !tak[(n+1)/2][(n+1)/2-1]) return false;
	printf("%d\n", n);
	return true;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	scanf("%d", &cel);
	for(int n = 1; n < 99999; n += 2) if(f(n)) return 0;
	
	return 0;
}