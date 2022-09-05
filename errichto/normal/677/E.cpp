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
const int nax = 1005;

int n;
char sl[nax];
int t[nax][nax];
int len[nax][nax][8];
// pii dir[nax][nax][8];
pii X[nax][nax], Y[nax][nax], XY[nax][nax], XV[nax][nax];

int dx[8] = {1,1,1,0,-1,-1,-1,0};
int dy[8] = {1,0,-1,-1,-1,0,1,1};

bool inside(int x, int y) {
	return 0 <= min(x, y) && max(x, y) <= n - 1;
}

void add(pii & a, pii b) {
	a.first += b.first;
	a.second += b.second;
}
void sub(pii & a, pii b) {
	add(a, mp(-b.first, -b.second));
}

int heh;
ld heh_heh = -1;
const ld TWO = logl(2);
const ld THREE = logl(3);
int pow2[nax*50], pow3[nax*50];

const int mod = 1e9 + 7;

void consider(pii maybe) {
	ld lol = maybe.first * TWO + maybe.second * THREE;
	if(lol > heh_heh) {
		heh_heh = lol;
		heh = (ll) pow2[maybe.first] * pow3[maybe.second] % mod;
	}
}

int main() {
	pow2[0] = pow3[0] = 1;
	RI(i, nax * 50 - 1) {
		pow2[i] = 2LL * pow2[i-1] % mod;
		pow3[i] = 3LL * pow3[i-1] % mod;
	}
	scanf("%d", &n);
	REP(y, n) {
		scanf("%s", sl);
		REP(x, n) t[x][y] = sl[x] - '0';
	}
	REP(x, n) REP(y, n) if(min(x,y)==0 || max(x,y)==n-1) {
		REP(i, 8) if(!inside(x-dx[i],y-dy[i])) {
			pii memo = mp(x,y);
			int so_far = 0;
			//pii so_far = mp(0, 0);
			while(true) {
				if(t[x][y] == 0) so_far = 0;
				else ++so_far;
				/*if(t[x][y] == 0) so_far = mp(0, 0);
				if(t[x][y] == 2) so_far.first++;
				if(t[x][y] == 3) so_far.second++;*/
				x += dx[i];
				y += dy[i];
				if(!inside(x, y)) break;
				len[x][y][i] = so_far;
			}
			x = memo.first;
			y = memo.second;
		}
	}
	
	REP(x, n) REP(y, n) {
		X[x+1][y+1] = X[x][y+1];
		Y[x+1][y+1] = Y[x+1][y];
		XY[x+1][y+1] = XY[x][y];
		XV[x+1][y+1] = XV[x][y+2];
		if(t[x][y] == 2) {
			++x; ++y;
			++X[x][y].first;
			++Y[x][y].first;
			++XY[x][y].first;
			++XV[x][y].first;
			--x; --y;
		}
		if(t[x][y] == 3) {
			++x; ++y;
			++X[x][y].second;
			++Y[x][y].second;
			++XY[x][y].second;
			++XV[x][y].second;
			--x; --y;
		}
	}
	
	REP(y, n) {
		REP(x, n) {
			REP(i, 2) if(t[x][y]) {
				int best = inf;
				REP(j, 4) mini(best, len[x][y][i+2*j]);
				
				pii ans = mp(0, 0);
				if(i == 0) { // ukos
					add(ans, XY[x+1+best][y+1+best]);
					sub(ans, XY[x+1-best-1][y+1-best-1]);
					add(ans, XV[x+1+best][y+1-best]);
					sub(ans, XV[x+1-best-1][y+1+best+1]);
				}
				else {
					add(ans, X[x+1+best][y+1]);
					sub(ans, X[x+1-best-1][y+1]);
					add(ans, Y[x+1][y+1+best]);
					sub(ans, Y[x+1][y+1-best-1]);
				}
				// subtract center because it's counted two times
				if(t[x][y] == 2) --ans.first;
				if(t[x][y] == 3) --ans.second;
				consider(ans);
				//printf("(%d,%d)", ans.first, ans.second);
				// printf("%d", best);
				//if(i == 0) printf("/");
				//else printf(" ");
			}
		}
		//puts("");
	}
	//puts("---------");
	printf("%d\n", heh);
	return 0;
}