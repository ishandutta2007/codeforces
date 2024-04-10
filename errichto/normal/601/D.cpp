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
const int nax = 3e5 + 5;

pii bazy, mody;

vi w[nax];
int juz[nax];
char sl_tmp[nax];
int sl[nax];
unordered_set<ll> h[nax];
ll hasz[nax];

void one(int a, int par, pii already) {
	already.st = ((ll) bazy.st * already.st + sl[a]) % mody.st;
	already.nd = ((ll) bazy.nd * already.nd + sl[a]) % mody.nd;
	hasz[a] = ((ll) already.st << 31) + already.nd;
	for(int b : w[a]) if(b != par)
		one(b, a, already);
}

int merge(int a, int b) {
	if(sz(h[a]) < sz(h[b])) swap(a, b);
	for(ll x : h[b]) h[a].insert(x);
	h[b].clear();
	return a;
}	

int two(int a, int par) {
	static int SZ = 0;
	int ja = ++SZ;
	h[ja].insert(hasz[a]);
	for(int b : w[a]) if(b != par) {
		int on = two(b, a);
		ja = merge(ja, on);
	}
	juz[a] += sz(h[ja]);
	//printf("%d\n", sz(h[ja]));
	return ja;
}

bool isPrime(int a) {
	for(int b = 2; b * b <= a; ++b) if(a % b == 0) return false;
	return true;
}

void makePrime(int & a) {
	while(!isPrime(a)) ++a;
}

int main() {
	bazy = mp(29, 31);
	const int mil = 1000 * 1000 * 1000;
	mody = mp(mil + 7, mil + 9);
	int n;
	scanf("%d", &n);
	//RI(i, n) sl[i] = rand() % 26;
	RI(i, n) scanf("%d", &juz[i]);
	scanf("%s", sl_tmp);
	RI(i, n) sl[i] = sl_tmp[i-1] - 'a';
	
	
	srand(n);
	int tot = 0;
	RI(i, n) if(rand() % 100 > 10) tot = (tot + 24622) % 1236325;
	srand(tot * 3);
	if(rand() % 3) {
		bazy.st += rand() % 5;
		makePrime(bazy.st);
	}
	if(rand() % 3) {
		bazy.nd += rand() % 30;
		makePrime(bazy.nd);
	}
	if(n > 5) srand(sl[2] + sl[3]);
	if(rand() % 3) {
		mody.st += rand() % 1000;
		makePrime(mody.st);
	}
	if(rand() % 3) {
		mody.nd += rand() % 100000;
		makePrime(mody.nd);
	}
	if(bazy.st == bazy.nd) {
		bazy.nd += 17;
		makePrime(bazy.nd);
	}
	if(mody.st == mody.nd) {
		mody.nd += 4561;
		makePrime(mody.nd);
	}
	
	
	/*FOR(i, 2, n) {
		int a = i;
		int b = i / 2;
		w[a].pb(b);
		w[b].pb(a);
	}*/
	REP(_, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	one(1, -1, mp(694645, 3436578));
	two(1, -1);
	int m = 0;
	RI(i, n) maxi(m, juz[i]);
	printf("%d\n", m);
	int c = 0;
	RI(i, n) if(juz[i] == m) ++c;
	printf("%d\n", c);
	//RI(i, n) printf("%d ", juz[i]);
	return 0;
}