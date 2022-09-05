#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 105;

struct M {
	int t[nax][nax];
	M() {
		REP(i,nax)REP(j,nax) t[i][j] = 0;
	}
	M operator * (const M & b) const {
		M res;
		REP(i,nax)FOR(j,i,nax-1)FOR(k,j,nax-1)
			maxi(res.t[i][k], t[i][j] + b.t[j][k]);
		return res;
	}
} m[nax];

int a[nax], tmp[nax];

int main() {
	int n, z;
	scanf("%d%d", &n, &z);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) {
		set<int> s;
		REP(j, n) if(a[j] < a[i]) s.insert(a[j]);
		tmp[i] = sz(s);
	}
	REP(i, n) a[i] = tmp[i];
	//REP(i, n) printf("%d ", a[i]); puts("");
	REP(i, n)
		FOR(k, 0, a[i])
			FORD(j, a[i], k)
				maxi(m[0].t[k][a[i]], m[0].t[k][j] + 1);
	RI(i, 25) m[i] = m[i-1] * m[i-1];
	M r;
	REP(i,26) if(z & (1 << i)) r = r * m[i];
	int out = 0;
	REP(i,nax)REP(j,nax) maxi(out, r.t[i][j]);
	printf("%d\n", out);
	return 0;
}