#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e6 + 5;

const int magic = 49;

const int D = 105;
pii p[nax];
ld half[D], two[D];


int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	assert(__gcd(5,0) == 5 && __gcd(0,5) == 5);
	
	half[0] = 1;
	RI(i, D-1) half[i] = half[i-1] / 2;
	two[0] = 1;
	RI(i, D-1) two[i] = two[i-1] * 2;
	
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	
	ld area = 0, border = 0;
	
	REP(i, n) FOR(j, i + 1, min(i + n - 2, i + magic)) {
		
		
		ld now;
		if(n > 50) now = half[j - i + 1];
		else {
			ld z = two[n] - 1 - n - n*(n-1)/2;
			now = two[n-(j-i+1)] - 1;
			now /= z;
		}
		
		int memo_j = j;
		j %= n;
		assert(i != j);
		
		int a = abs(p[i].x-p[j].x);
		int b = abs(p[i].y-p[j].y);
		int line = __gcd(a,b);
		border += line * now;
		area += 0.5L * now * (  (ld)p[i].x*p[j].y - (ld)p[i].y*p[j].x );
		
		j = memo_j;
	}
	
	printf("%.10lf\n", double(area - border / 2 + 1));
	
	return 0;
}