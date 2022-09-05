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

vector<pii > w;

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	RI(i, n) {
		int a;
		scanf("%d", &a);
		w.pb(make_pair(a,i));
	}
	sort(w.begin(), w.end());
	w.pb(make_pair(inf, 0));
	
	int i = 0;
	while(k >= w[i].st) {
		k -= w[i].st;
		++i;
	}
	printf("%d\n", i);
	REP(j, i) printf("%d ", w[j].nd);
	return 0;
}