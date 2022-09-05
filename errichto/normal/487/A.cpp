#include<cstdio>
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
#ifdef LOK
#define debug printf
#else
#define debug if(0)printf
#endif
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

struct s {
	int hp;
	int atk;
	int def;
};

s wczytaj() {
	s a;
	scanf("%d%d%d", &a.hp, &a.atk, &a.def);
	return a;
}

int main() {
	s ja = wczytaj();
	s monster = wczytaj();
	s cena = wczytaj();
	int res = inf;
	REP(def, 405) REP(atk, 405) {
		// ile hp potrzebuje?
		int zabieram = max(0, ja.atk + atk - monster.def);
		int on = max(0, monster.atk - ja.def - def);
		int tury = 0;
		if(zabieram == 0) continue;
		tury = (monster.hp + zabieram - 1) / zabieram;
		int min_hp = 1 + tury * on;
		int potrzeba = max(0, min_hp - ja.hp);
		mini(res, cena.hp * potrzeba + cena.atk * atk + cena.def * def);
	}
	printf("%d\n", res);
	return 0;
}