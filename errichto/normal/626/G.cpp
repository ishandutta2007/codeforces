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
const int nax = 1e6 + 5;

int p[nax], oni[nax], ja[nax];
ld zysk[nax];
ld strata[nax];
ld ans;

ld value(int i, int x) {
	return (ld) p[i] * x / (x + oni[i]);
}

struct cmp_doda {
	bool operator()(int i, int j) const {
		if(zysk[i] == zysk[j]) return i < j;
		return zysk[i] > zysk[j];
	}
};
struct cmp_usu {
	bool operator()(int i, int j) const {
		if(strata[i] == strata[j]) return i < j;
		return strata[i] < strata[j];
	}
};

set<int, cmp_doda> dodawanie;
set<int, cmp_usu> usuwanie;

void zapomnij(int i) {
	ans -= value(i, ja[i]);
	dodawanie.erase(i);
	usuwanie.erase(i);
}
void act(int i) {
	if(ja[i] == oni[i]) zysk[i] = -inf;
	else zysk[i] = value(i, ja[i] + 1) - value(i, ja[i]);
	if(ja[i] == 0) strata[i] = inf;
	else strata[i] = value(i, ja[i]) - value(i, ja[i] - 1);
}
void przypomnij(int i) {
	ans += value(i, ja[i]);
	dodawanie.insert(i);
	usuwanie.insert(i);
}

int ruchy;
void dobieraj() {
	while(ruchy > 0 && zysk[*(dodawanie.begin())] >= 0) {
		--ruchy;
		int i = *(dodawanie.begin());
		zapomnij(i);
		// ans += zysk[i];
		++ja[i];
		act(i);
		przypomnij(i);
	}
}
void zabieraj() {
	for(int rep = 0; rep < 3 && strata[*(usuwanie.begin())] < inf / 2; ++rep) {
		++ruchy;
		int i = *(usuwanie.begin());
		zapomnij(i);
		assert(ja[i]);
		--ja[i];
		act(i);
		przypomnij(i);
	}
}

int main() {
	int n, q;
	scanf("%d%d%d", &n, &ruchy, &q);
	REP(i, n) scanf("%d", &p[i]);
	REP(i, n) scanf("%d", &oni[i]);
	REP(i, n) {
		act(i);
		przypomnij(i);
	}
	dobieraj();
	// printf("%Lf\n", ans);
	//REP(i, n) printf("%d ", ja[i]); puts("");
	//REP(i, n) printf("%Lf ", strata[i]); puts("");
	//puts("");
	while(q--) {
		int type, which;
		scanf("%d%d", &type, &which);
		--which;
		if(ja[which]) {
			++ruchy;
			int i = which;
			zapomnij(i);
			// ans -= strata[i];
			--ja[i];
			act(i);
			przypomnij(i);
		}
		zapomnij(which);
		if(type == 1) ++oni[which];
		else --oni[which];
		act(which);
		przypomnij(which);
		assert(oni[which] > 0);
		
		zabieraj();
		
		dobieraj();
		printf("%.10lf\n", double(ans));
	}
		
	
	/*REP(qqq, q) {
		int type, which;
		scanf("%d%d", &type, &which);
		--which;
		if(type == 1) ++cnt[which];
		else --cnt[which];
		assert(cnt[which] >= 1);
		vector<ld> w;
		REP(i, n) RI(x, cnt[i]) {
			w.pb(value(i, x) - value(i, x - 1));
		}
		sort(w.rbegin(), w.rend());
		ld ans = 0;
		REP(i, min(t, sz(w))) ans += w[i];
		printf("%Lf\n", ans);
	}*/
	return 0;
}