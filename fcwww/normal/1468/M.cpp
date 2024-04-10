#include <bits/stdc++.h>

#define For(i, l, r) for (register int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for (register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Rep(i, r) for (register int i = (0), i##end = (int)(r); i < i##end; ++i)
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define debug(x) cout << #x << ": " << (x) << endl

using namespace std;

template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

inline int read() {
	int x(0), sgn(1); char ch(getchar());
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
	return x * sgn;
}

void File() {
#ifdef zjp_shadow
	freopen ("M.in", "r", stdin);
	freopen ("M.out", "w", stdout);
#endif
}

const int N = 2e5 + 1e3;

int n, blksz, tot, id[N];

map<int, int> S[N];
vector<int> a[N];

int lis[N], cnt;
int ansx, ansy; bool tag[N];

int main () {

	File();

	int cases = read();

	while(cases--) {
		tot = 0;

		n = read(); cnt = 0;
		For(i, 1, n) {
			a[i].clear(); id[i] = i;
			int sz = read(); tot += sz;
			For(j, 1, sz) a[i].push_back(lis[++cnt] = read());
		}
		sort(lis + 1, lis + cnt + 1);
		cnt = unique(lis + 1, lis + cnt + 1) - lis - 1;
		For(i, 1, n) Rep(j, a[i].size())
			a[i][j] = lower_bound(lis + 1, lis + cnt + 1, a[i][j]) - lis;

		For (i, 1, n) sort(a[i].begin(), a[i].end());
		sort(id + 1, id + n + 1,
				[&](int &lhs, int &rhs) { return a[lhs].size() > a[rhs].size(); });

		ansx = ansy = 0;

		blksz = sqrt(tot) / 8;
		For(i, 1, n) {
			int cur = id[i];
			if(int(a[cur].size()) > blksz) {
				for(int v : a[cur]) tag[v] = true;
				For(j, i + 1, n) {
					int nxt = id[j], sum = 0;
					for(int v : a[nxt]) if (tag[v]) ++sum;
					if (sum >= 2) {
						ansx = cur; ansy = nxt; break;
					}
				}
				for(int v : a[cur]) tag[v] = false;
				if (ansx) break;
			} else {
				Rep(x, a[cur].size()) {
					Rep(y, x) {
						int colx = a[cur][x], coly = a[cur][y];
						if(S[colx].find(coly) == S[colx].end())
							S[colx][coly] = cur;
						else {
							ansx = cur; ansy = S[colx][coly]; break;
						}
					}
					if(ansx) break;
				}
			}
		}

		For(i, 1, n) for(int v : a[i]) S[v].clear();
		if(ansx) printf("%d %d\n", ansx, ansy);
		else puts("-1");
	}

	return 0;

}