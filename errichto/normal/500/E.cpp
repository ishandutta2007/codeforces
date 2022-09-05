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
const int nax = 2e5 + 5;
const int pot = 256 * 1024;

int x[nax], zas[nax];
int tr[2 * pot + 5];

int max_tr(int a, int b) {
	int r = a;
	if(zas[b] > zas[r]) r = b;
	a += pot; b += pot;
	while(a + 1 < b) {
		if(a % 2 == 0) if(zas[tr[a+1]] > zas[r]) r = tr[a+1];
		if(b % 2 == 1) if(zas[tr[b-1]] > zas[r]) r = tr[b-1];
		a /= 2;
		b /= 2;
	}
	return r;
}

#define _koszt d[0]
#define _jak_daleko d[1]
#define _nast d[2]

struct Kubek {
	int d[3];
};
Kubek t[nax][19];

struct Prawda {
	int jak_daleko, nast;
};
Prawda prawda[nax];

Kubek f(int a, int b) {
	Kubek k;
	if(a == b) {
		k._koszt = 0;
		k._jak_daleko = prawda[a].jak_daleko;
		k._nast = prawda[a].nast;
		return k;
	}
	assert(a < b);
	if(a + 1 == b) {
		if(zas[a] >= x[b]) {
			k._koszt = 0;
			k._jak_daleko = prawda[a].jak_daleko;
			k._nast = prawda[a].nast;
			return k;
		}
		k._koszt = x[b] - zas[a];
		k._jak_daleko = prawda[b].jak_daleko;
		k._nast = prawda[b].nast;
		return k;
	}
	int lvl = 0;
	while((1 << (lvl + 1)) < b - a)
		++lvl;
	// t[a][k] - koszt, nastepny, jak daleko do nastepnego
	if(t[a][lvl]._nast > b) return t[a][lvl];
	k = f(t[a][lvl]._nast, b);
	k._koszt += t[a][lvl]._koszt + t[a][lvl]._jak_daleko;
	// skoro nie siegal, to .nast bierzemy z k
	return k;
}

int main() {
	int n;
	scanf("%d", &n);
	RI(i, n) scanf("%d%d", &x[i], &zas[i]);
	x[n+1] = (int) 2e9 + 5;
	RI(i, n+1) zas[i] += x[i];
	set<pii > s;
	RI(i, n+1) s.insert(mp(x[i], i));
	RI(i, n) tr[pot + i] = i;
	FORD(i, pot-1, 1) {
		if(zas[tr[2*i]] > zas[tr[2*i+1]])
			tr[i] = tr[2*i];
		else
			tr[i] = tr[2*i+1];
	}
	prawda[n].nast = n+1;
	FORD(a, n-1, 1) {
		auto it = s.lower_bound(mp(zas[a], inf)); // to, co juz nie pasuje
		--it;
		int b = (*it).nd;
		if(b > a) b = max_tr(a, b);
		if(b > a) prawda[a] = prawda[b];
		else {
			++it;
			int pom = (*it).nd;
			prawda[a].nast = pom;
			prawda[a].jak_daleko = x[pom] - zas[a];
		}
	}
	s.clear();
	// RI(a, n) debug("%d %d\n", prawda[a].nast, prawda[a].jak_daleko);
	FORD(a, n, 1) {
		int k = 0;
		while(a + (1 << k) <= n) {
			t[a][k] = f(a, a + (1 << k));
			++k;
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", f(a, b)._koszt);
	}
	return 0;
}