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
const ll INF = (ll) inf * inf;
const int nax = 1e7 + 5;

bool ma[nax];
int nomi[5005];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, k;
	scanf("%d%d", &n, &k);
	RI(i, n) {
		scanf("%d", &nomi[i]);
		ma[nomi[i]] = true;
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int a;
		int r = inf;
		scanf("%d", &a);
		
		RI(i, n) RI(biore, k) {
			int b = a - nomi[i] * biore;
			if(b < 0) {
				biore = k + 2;
				break;
			}
			if(b == 0) mini(r, biore);
			RI(jeszcze, k - biore) {
				int by = b / jeszcze;
				if(by * jeszcze == b && by < nax && ma[by]) mini(r, biore + jeszcze);
			}
		}
		
		if(r == inf) r = -1;
		printf("%d\n", r);
	}
			
	
	return 0;
}