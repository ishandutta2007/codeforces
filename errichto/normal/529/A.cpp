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
const int nax = 1e6 + 5;
const int D = 1;
const ll MM = 1000 * 1000 * 1000;
const ll m[5] = {MM + 7, MM + 9, MM + 21, MM + 33, 333333361LL};

char sl[nax];
ll preh[nax][D];
int n;
ll potega[nax][D];

ll h(pii a, int j) {
	ll x = preh[a.nd][j];
	if(a.st) x -= preh[a.st-1][j];
	if(x < 0) x += m[j];
	x = (x * potega[n - a.st][j]) % m[j];
	return x;
}
	

bool rowne(pii a, pii b) {
	REP(j, D) if(h(a, j) != h(b, j)) return false;
	return true;
}

int porow(pii a, pii b) {
	assert(a.nd - a.st == b.nd - b.st);
	if(a.st > a.nd) return true;
	/*REP(i, a.nd - a.st + 1) if(sl[a.st + i] != sl[b.st + i]) {
		if(sl[a.st + i] == '(') return 0;
		return 2;
	}
	return 1;*/
	if(rowne(a, b)) return 1;
	int low = 0, high = a.nd - a.st;
	// jaka jest dlugosc rownych?
	//while(rowne(mp(a.st, a.st + low), mp(b.st, b.st + low))) ++low;
	while(low != high) {
		int med = (low + high) / 2;
		if(rowne(mp(a.st, a.st + med), mp(b.st, b.st + med)))
			low = med + 1;
		else
			high = med;
	}
	// low==0 oznacza roznosc na najpierwszej pozycji
	if(sl[a.st + low] == '(') return 0;
	return 2;
}

int pref[nax];
int LICZ;
const int pot = 1024 * 1024;
int tr[2 * pot];

int mi(int a, int b) {
	a += pot;
	b += pot;
	int ku = min(tr[a], tr[b]);
	while(a < b - 1) {
		mini(ku, tr[a+1]);
		mini(ku, tr[b-1]);
		a /= 2;
		b /= 2;
	}
	return ku;
}

bool ok_podzial_szybkie(int i) {
	// od i+1 zaczynamy
	// do i wlacznie drugi kawalek
	int s1 = pref[i];
	int s2 = LICZ - pref[i];
	
	int k = 0;
	if(LICZ < 0) k = -LICZ;
	//printf("%d\n", LICZ);
	if(i + 1 <= n - 1 && k + mi(i + 1, n - 1) - s1 < 0) return false;
	
	if(0 <= i && k + s2 + mi(0, i) < 0) return false;
	
	return true;
}

bool ok_podzial(int i) {
	int teraz = 0;
	if(LICZ < 0) teraz = -LICZ;
	FOR(j, i + 1, n - 1) {
		if(sl[j] == '(') ++teraz;
		else --teraz;
		if(teraz < 0) return false;
	}
	FOR(j, 0, i) {
		if(sl[j] == '(') ++teraz;
		else --teraz;
		if(teraz < 0) return false;
	}
	return true;
}	

int best = -1;

bool jebaj(int i) {
	if(best == -1) return true;
	int kon = best + 1 + (n-1-(i+1));
	int pom = porow(mp(best + 1, kon), mp(i + 1, n - 1));
	if(pom == 0) return false;
	if(pom == 2) return true;
//	if(i == 4) puts("ok");
	int kon2 = n-1-(kon+1);
	pom = porow(mp(kon + 1, n - 1), mp(0, kon2));
	if(pom == 0) return false;
	if(pom == 2) return true;
//	if(i == 4) puts("ok2");
	pom = porow(mp(0, best), mp(kon2 + 1, i));
	if(pom == 0) return false;
	return true;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	scanf("%s", sl);
	n = strlen(sl);
	
	REP(i, n) {
		if(i) pref[i] = pref[i-1];
		if(sl[i] == '(') pref[i]++;
		else pref[i]--;
	}
	
	REP(i, 2 * pot) tr[i] = inf;
	REP(i, n) tr[pot + i] = pref[i];
	FORD(i, pot - 1, 1) tr[i] = min(tr[2*i], tr[2*i+1]);
	
	LICZ = 0;
	REP(i, n) {
		if(sl[i] == '(') ++LICZ;
		else --LICZ;
	}
	
	REP(j, D) {
		potega[0][j] = 1;
		RI(i, n) potega[i][j] = ((j == 2 ? 3 : 2) * potega[i-1][j]) % m[j];
	}
	REP(j, D) REP(i, n) {
		int teraz = int(sl[i] == '(');
		preh[i][j] = ((i ? preh[i-1][j] : 0LL) + teraz * potega[i][j]) % m[j];
	}
	
	REP(i, n)
		if(ok_podzial_szybkie(i)) if(jebaj(i)) best = i;
	
	assert(best != -1);
	
	if(LICZ < 0) REP(_, -LICZ) printf("(");
	
	FOR(j, best + 1, n - 1) printf("%c", sl[j]);
	FOR(j, 0, best) printf("%c", sl[j]);
	
	if(LICZ > 0) REP(_, LICZ) printf(")");
	
	puts("");
	
	return 0;
}