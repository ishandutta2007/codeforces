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

int n;

int ask(int x1, int y1, int x2, int y2) {
	if(max({x1,y1,x2,y2}) > n) return 0;
	if(min({x1,y1,x2,y2}) < 1) return 0;
	if(x1 > x2 || y1 > y2) return 0;
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
	
	/* int ret = 0;
	if(x1 <= 17 && 57 <= x2 && y1 <= 80 && 80 <= y2) ++ret;
	if(x1 <= 25 && 88 <= x2 && y1 <= 51 && 61 <= y2) ++ret;
	// printf("%d %d %d %d\n", x1, y1, x2, y2);
	// printf("%d\n", ret);
	return ret; */
}

bool A(const pii & a) { return a.first != a.second; }
int B(const pii & a) { return (a.first + a.second) / 2; }
void C(pii & a) { mini(a.first, a.second); }
int D(const pii & a) { return (a.first + a.second + 1) / 2; }
void E(pii & a) { maxi(a.second, a.first); }

bool ok[3];
void firstOK(pii & x1, pii & y1, pii & x2, pii & y2) {
	// int ii = 0;
	while(A(x1) || A(y1) || A(x2) || A(y2)) {
		// if(++ii > 20) return;
		//printf("%d %d\n", x1.first, x1.second);
		if(ok[ ask(B(x1), B(y1), B(x2), B(y2)) ]) {
			x1 = {x1.first, B(x1)};
			x2 = {x2.first, B(x2)};
			y1 = {y1.first, B(y1)};
			y2 = {y2.first, B(y2)};
		}
		else {
			x1 = {B(x1)+1, x1.second};
			x2 = {B(x2)+1, x2.second};
			y1 = {B(y1)+1, y1.second};
			y2 = {B(y2)+1, y2.second};
			C(x1); C(x2); C(y1); C(y2);
		}
	}
}
void lastOK(pii & x1, pii & y1, pii & x2, pii & y2) {
	// int ii = 0;
	while(A(x1) || A(y1) || A(x2) || A(y2)) {
		// if(++ii > 20) return;
		//printf("%d %d\n", x1.first, x1.second);
		if(ok[ ask(D(x1), D(y1), D(x2), D(y2)) ]) {
			x1 = {D(x1), x1.second};
			x2 = {D(x2), x2.second};
			y1 = {D(y1), y1.second};
			y2 = {D(y2), y2.second};
		}
		else {
			x1 = {x1.first, D(x1)-1};
			x2 = {x2.first, D(x2)-1};
			y1 = {y1.first, D(y1)-1};
			y2 = {y2.first, D(y2)-1};
			E(x1); E(x2); E(y1); E(y2);
		}
	}
}

void ans(int minx1, int miny1, int maxx1, int maxy1,
		int minx2, int miny2, int maxx2, int maxy2) {
	if(max(minx1, minx2) <= min(maxx1, maxx2)
	&& max(miny1, miny2) <= min(maxy1, maxy2)) return;
	if(ask(minx1, miny1, maxx1, maxy1) != 1) return;
	if(ask(minx2, miny2, maxx2, maxy2) != 1) return;
	printf("! %d %d %d %d %d %d %d %d\n",
		minx1, miny1, maxx1, maxy1, minx2, miny2, maxx2, maxy2);
	fflush(stdout);
	exit(0);
}

int main() {
	scanf("%d", &n);
	pii x1 = {1, 1};
	pii y1 = {1, 1};
	pii x2 = {n, n};
	pii y2 = {n, n};
	ok[2] = true;
	
	ok[1] = false;
	x1 = {1, n};
	lastOK(x1, y1, x2, y2);
	int minx1 = x1.first;
	ok[1] = true;
	x1 = {1, n};
	lastOK(x1, y1, x2, y2);
	int minx2 = x1.first;
	x1 = {1, 1};
	
	ok[1] = false;
	y1 = {1, n};
	lastOK(x1, y1, x2, y2);
	int miny1 = y1.first;
	ok[1] = true;
	y1 = {1, n};
	lastOK(x1, y1, x2, y2);
	int miny2 = y1.first;
	y1 = {1, 1};
	
	// printf("%d %d %d %d\n", minx1, minx2, miny1, miny2);
	
	ok[1] = false;
	x2 = {1, n};
	firstOK(x1, y1, x2, y2);
	int maxx1 = x2.first;
	ok[1] = true;
	x2 = {1, n};
	firstOK(x1, y1, x2, y2);
	int maxx2 = x2.first;
	x2 = {n, n};
	
	ok[1] = false;
	y2 = {1, n};
	firstOK(x1, y1, x2, y2);
	int maxy1 = y2.first;
	ok[1] = true;
	y2 = {1, n};
	firstOK(x1, y1, x2, y2);
	int maxy2 = y2.first;
	y2 = {n, n};
	
	// printf("%d %d %d %d\n", maxx1, maxx2, maxy1, maxy2);
	
	ans(minx1, miny1, maxx1, maxy1, minx2, miny2, maxx2, maxy2);
	ans(minx1, miny1, maxx1, maxy2, minx2, miny2, maxx2, maxy1);
	ans(minx1, miny1, maxx2, maxy1, minx2, miny2, maxx1, maxy2);
	ans(minx1, miny2, maxx1, maxy1, minx2, miny1, maxx2, maxy2);
	ans(minx1, miny1, maxx2, maxy2, minx2, miny2, maxx1, maxy1);
	ans(minx1, miny2, maxx1, maxy2, minx2, miny1, maxx2, maxy1);
	ans(minx1, miny2, maxx2, maxy1, minx2, miny1, maxx1, maxy2);
	ans(minx1, miny2, maxx2, maxy2, minx2, miny1, maxx1, maxy1);
	assert(false);
	
	// printf("%d\n", x1.first);
	return 0;
	
}