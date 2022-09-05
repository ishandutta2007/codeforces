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
const int nax = 2e3 + 5;

int H, W;
char t[nax][nax];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool DUPA = false;

bool puste(int x, int y) {
	return x >= 0 && y >= 0 && x < W && y < H && t[y][x] == '.';
}
bool zaj(int x, int y) { return !puste(x, y); }

void f(int x, int y);

void kolo(int x, int y) {
	REP(i, 4) f(x + dx[i], y + dy[i]);
}

void f(int x, int y) {
	if(DUPA || zaj(x, y)) return;
	int a = 0;
	REP(i, 4) if(puste(x + dx[i], y + dy[i])) ++a;
	if(a == 0) {
		DUPA = true;
		if(debug) puts("Pole bez kandydata");
		return;
	}
	if(a > 1) return;
	assert(a == 1);
	if(puste(x + 1, y)) {
		t[y][x] = '<';
		t[y][x+1] = '>';
		kolo(x+1, y);
	}
	else if(puste(x, y + 1)) {
		t[y][x] = '^';
		t[y+1][x] = 'v';
		kolo(x, y+1);
	}
	else if(puste(x - 1, y)) {
		t[y][x] = '>';
		t[y][x-1] = '<';
		kolo(x-1, y);
	}
	else if(puste(x, y - 1)) {
		t[y][x] = 'v';
		t[y-1][x] = '^';
		kolo(x, y-1);
	}
	else assert(false);
	kolo(x, y);
}
	
char sl[nax];
int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	scanf("%d%d", &H, &W);
	REP(y, H) scanf("%s", t[y]);
	REP(y, H) REP(x, W) f(x, y);
	if(!DUPA) REP(y, H) REP(x, W) if((!DUPA) && puste(x, y)) {
		if(debug) puts("cykl znaleziony");
		DUPA = true;
	}
	if(DUPA) puts("Not unique");
	else REP(y, H) printf("%s\n", t[y]);
	return 0;
}