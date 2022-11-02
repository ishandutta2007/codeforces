#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);
const int maxA = 1000000;
const int maxN = 6 + 5;
const int maxM = 50 + 2;
const int INF = 0x3f3f3f3f;
int a[maxN], b[maxN], c[maxN], na, nb, nc;
int f[maxM][maxN][maxN][maxN][2];
int ans = INF;

struct Seven{
	int i, j, k, t, da, db, dc;
	bool empty() {
		return !(i || j || k || t || da || db || dc);
	}
	void print() {
		printf("%d %d %d %d %d %d %d\n", i, j, k, t, da, db, dc);
	}
} p[maxM][maxN][maxN][maxN][2], final;
int ans_at_len = -1;

inline void readint(int *a, int &na) {
	na = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) a[++na] = c - '0', c = getchar();
}
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline bool chmin(int &a, int b) { return a > b ? a = b, true : false; }
inline bool chmax(int &a, int b) { return a < b ? a = b, true : false; }

int main() {
	memset(a, -1, sizeof(a)); memset(b, -1, sizeof(b)); memset(c, -1, sizeof(c));
	readint(a, na); readint(b, nb); readint(c, nc);
	std::reverse(a + 1, a + na + 1); std::reverse(b + 1, b + nb + 1); std::reverse(c + 1, c + nc + 1);
	memset(f, INF, sizeof(f));
	memset(p, 0, sizeof(p));
	f[0][0][0][0][0] = 0;
	for(int len = 0; len < maxM-2; ++len) {
	for(int i = 0; i <= min(na+1, len); ++i) {
	for(int j = 0; j <= min(nb+1, len); ++j) {
	for(int k = 0; k <= min(nc+1, len); ++k) {
	// i, j, k = nx + 1 for leading zero's
		for(int t = 0; t < 2; ++t) {
			int val = f[len][i][j][k][t];
			if(val < INF)
			for(int da = 0; da <= 9; ++da) if(i != na + 1 || da == 0) {
			for(int db = 0; db <= 9; ++db) if(j != nb + 1 || db == 0) {
			for(int dc = 0; dc <= 9; ++dc) if(k != nc + 1 || dc == 0) {
				int nt;
				if(dc == da + db + t) nt = 0;
				else if(dc == da + db + t - 10) nt = 1;
				else continue;
				
				int fa = 1, fb = 1, fc = 1, sa = 1, sb = 1, sc = 1;
				if(da == 0 && i == na) fa = sa = 0;
				if(db == 0 && j == nb) fb = sb = 0;
				if(dc == 0 && k == nc) fc = sc = 0;
//				printf("j = %d, nb = %d\n", j, nb);
				
				BEGIN:
				int ni = da == a[i+1] ? i + 1 : i;
				int nj = db == b[j+1] ? j + 1 : j;
//				printf("nj = %d\n", nj);
				int nk = dc == c[k+1] ? k + 1 : k;
				if(!fa) ni = na + 1;
				if(!fb) nj = nb + 1;
				if(!fc) nk = nc + 1;
				
				int nv = val;
				if(ni != na + 1) ++nv;
				if(nj != nb + 1) ++nv;
				if(nk != nc + 1) ++nv;
				
				if(chmin(f[len+1][ni][nj][nk][nt], nv)) {
					p[len+1][ni][nj][nk][nt] = Seven{i, j, k, t, da, db, dc};
//					printf("Status freshened from f(%d,%d,%d,%d,%d)->f(%d,%d,%d,%d,%d) %d %d %d : v = %d\n",
//						len, i, j, k, t, len+1, ni, nj, nk, nt, da, db, dc, nv);
					if(ni >= na && nj >= nb && nk >= nc && nt == 0) {
						if(chmin(ans, nv)) final = p[len+1][ni][nj][nk][nt], ans_at_len = len + 1;
//						printf("Answer freshened from f(%d,%d,%d,%d,%d)->f(%d,%d,%d,%d,%d) %d %d %d : v = %d\n",
//							len, i, j, k, t, len+1, ni, nj, nk, nt, da, db, dc, nv);
//						system("pause");
					}
				}
				
				if(!fa || !fb || !fc) {
					do {
//						printf("%d %d %d %d %d %d\n", fa, fb, fc, sa, sb, sc);
						++fc;
						fb += fc / 2; fc %= 2;
						fa += fb / 2; fb %= 2;
					} while(!(fa >= sa && fb >= sb && fc >= sc));
					goto BEGIN;
				}
			}
			}
			}
		}
	}
	}
	}
	}
//	printf("ans = %d\n", ans);
	vector<int> aa, bb, cc;
	while(ans_at_len) {
//		final.print();
		if(final.i != na + 1) aa.push_back(final.da);
		if(final.j != nb + 1) bb.push_back(final.db);
		if(final.k != nc + 1) cc.push_back(final.dc);
		final = p[--ans_at_len][final.i][final.j][final.k][final.t];
	}
	while(aa.size() && aa.front() == 0) aa.erase(aa.begin(), aa.begin()+1);
	while(bb.size() && bb.front() == 0) bb.erase(bb.begin(), bb.begin()+1);
	while(cc.size() && cc.front() == 0) cc.erase(cc.begin(), cc.begin()+1);
	for(int x : aa) printf("%d", x);
	printf("+");
	for(int y : bb) printf("%d", y);
	printf("=");
	for(int z : cc) printf("%d", z);
	printf("\n");
	return 0;
}