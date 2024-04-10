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

struct P {
	int w, h;
	bool juz;
	P(int w = 0, int h = 0) : w(w), h(h) {juz = false;}
	void wczytaj() { scanf("%d%d", &w, &h); juz = false; }
};

P p[nax], memo[nax];
int n;



int check(int H) {
	REP(i, n) p[i] = memo[i];
	int polozeni = 0;
	int W = 0;
	REP(i, n) if(p[i].h > H) {
		W += p[i].h;
		swap(p[i].h, p[i].w);
		if(p[i].h > H) return inf;
		p[i].juz = true;
		polozeni++;
	}
	if(polozeni > n / 2) return inf;
	int jeszcze = n / 2 - polozeni;
	vi roz;
	REP(i, n) if(!p[i].juz) if(p[i].w <= H && p[i].w > p[i].h) roz.pb(p[i].w - p[i].h);
	sort(roz.rbegin(), roz.rend());
	int oszcz = 0;
	REP(i, min(jeszcze, sz(roz))) oszcz += roz[i];
	REP(i, n) if(!p[i].juz) W += p[i].w;
	return H * (W - oszcz);
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	scanf("%d", &n);
	REP(i, n) p[i].wczytaj();
	REP(i, n) memo[i] = p[i];
	int r = inf;
	FORD(H, 1000, 1) mini(r, check(H));
	printf("%d\n", r);
			
	
	return 0;
}