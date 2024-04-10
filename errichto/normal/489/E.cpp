#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#ifndef LOK
#define cerr if(0) cout
#endif
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5, nax = 1e3 + 5;

int far[nax], pic[nax];
ld fru[nax][nax];
pair<ld, int> res[nax];
int n, l;

bool da_sie(ld R) {
	RI(i, n) res[i] = mp(1e10, 0);
	res[0] = mp(0., -1);
	REP(i, n) FOR(j, i + 1, n)
		mini(res[j], mp(res[i].st + fru[i][j] - R * pic[j], i));
	if(res[n].st > 1e-12) return false;
	return true;
}

int main() {
	scanf("%d%d", &n, &l);
	RI(i, n) scanf("%d%d", &far[i], &pic[i]);
	FOR(i, 0, n) FOR(j, i + 1, n) fru[i][j] = sqrt(abs((ld) far[j] - far[i] - l));
	ld low = 0, high = fru[0][n] / pic[n] + 1e-5;
	REP(_, 100) {
		ld med = (low + high) / 2;
		if(da_sie(med)) high = med;
		else low = med;
	}
	da_sie(low);
	cerr << low << "\n";
	RI(i, n) cerr << res[i].nd << " ";
	vi w;
	for(int a = n; a > 0; a = res[a].nd)
		w.pb(a);
	FORD(i, w.size() - 1, 0) printf("%d ", w[i]);
	puts("");
	return 0;
}