#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define pb push_back
#define st first
#define nd second
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;
const int pot = 128 * 1024;

int H, W;
const pii LOOP = {-1,-1};
const pii NIC = {0,0};
pii tr[2 * pot + 5][10];
char sl[nax][12];

void ogarnij_wiersz(int y) {
	REP(x, W) {
		int memo_x = x;
		int gora = 15;
		while(gora-- > 0 && x >= 0 && x < W && sl[y][x] != '^') {
			if(sl[y][x] == '>') x++;
			else if(sl[y][x] == '<') x--;
		}
		if(x == -1 || x == W) tr[pot + y][memo_x] = {x, y};
		else if(sl[y][x] == '^') tr[pot + y][memo_x] = {x, y+1};
		else tr[pot + y][memo_x] = LOOP;
		x = memo_x;
	}
}

void popraw_komorke_drzewa(int i) {
	assert(i > 0 && i < pot);
	REP(x, W) {
		int lewy = 2 * i;
		int prawy = lewy + 1;
		pii pom = tr[lewy][x];
		if(pom == NIC) continue;
		if(pom == LOOP || pom.st == -1 || pom.st == W)
			tr[i][x] = pom;
		else if(tr[prawy][pom.st] == NIC)
			tr[i][x] = pom;
		else
			tr[i][x] = tr[prawy][pom.st]; // byc moze NIC
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int q;
	scanf("%d%d%d", &H, &W, &q);
	FORD(y, H, 1) {
		scanf("%s", sl[y]);
		ogarnij_wiersz(y);
	}
	FORD(i, pot-1, 1) popraw_komorke_drzewa(i);
	while(q--) {
		if(debug) puts("dajesz");
		char rodz[5];
		scanf("%s", rodz);
		if(rodz[0] == 'C') { // zmiana
			if(debug) puts("zmiana");
			int x, y;
			char na[3];
			scanf("%d%d%s", &y, &x, na);
			y = H + 1 - y;
			sl[y][x-1] = na[0];
			ogarnij_wiersz(y);
			for(int i = (pot + y) / 2; i > 0; i /= 2) popraw_komorke_drzewa(i);
		}
		else { // zapytanie
			if(debug) puts("zapytanie");
			int x, y;
			scanf("%d%d", &y, &x);
			if(debug) printf("jeb: %d %d\n", y, x);
			y = H + 1 - y;
			y += pot;
			pii pom = tr[y][x-1];
			while(y > 1 && pom != NIC && pom != LOOP && pom.st != -1 && pom.st != W) {
				if(debug) printf("%d %d\n", pom.st, pom.nd);
				if(y % 2 == 0 && tr[y + 1][pom.st] != NIC)
					pom = tr[y + 1][pom.st];
				y /= 2;
			}
			assert(pom != NIC);
			if(pom != LOOP) pom.st++;
			if(pom != LOOP) pom.nd = H + 1 - pom.nd;
			printf("%d %d\n", pom.nd, pom.st);
		}
	}
	return 0;
}