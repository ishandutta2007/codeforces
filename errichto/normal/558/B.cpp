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

int la[nax], t[nax], ile[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	int n;
	scanf("%d", &n);
	int m = 0;
	RI(i, n) {
		scanf("%d", &t[i]);
		ile[t[i]]++;
		maxi(m, ile[t[i]]);
		maxi(la[t[i]], i);
	}
	pii res = mp(0, n+1);
	RI(i, n) if(ile[t[i]] == m) {
		ile[t[i]] = 0;
		int low = i, high = la[t[i]];
		if(high - low < res.nd - res.st)
			res = mp(low, high);
	}
	printf("%d %d\n", res.st, res.nd);
	return 0;
}