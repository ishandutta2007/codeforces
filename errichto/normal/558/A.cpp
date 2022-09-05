#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
#include<set>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
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
const int nax = 1e6 + 5;



int main(int argc, char *argv[])
{
	debug = argc > 1;
	vector<pii> lewe, prawe;
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int x, a;
		scanf("%d%d", &x, &a);
		if(x > 0) prawe.pb(mp(x, a));
		else lewe.pb(mp(-x,a));
	}
	sort(lewe.begin(), lewe.end());
	sort(prawe.begin(), prawe.end());
	int res = 0;
	REP(_, 2) {
		
		int s = 0;
		int ile = min(sz(prawe), sz(lewe));
		REP(i, min(ile, sz(lewe))) s += lewe[i].nd;
		REP(i, min(ile+1, sz(prawe))) s += prawe[i].nd;
		maxi(res, s);
		
		swap(lewe,prawe);
	}
	printf("%d\n", res);
	return 0;
}