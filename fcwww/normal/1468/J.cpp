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
	freopen ("j.in", "r", stdin);
	freopen ("j.out", "w", stdout);
#endif
}

const int N = 2e5 + 1e3;

int n, m, k; long long ans;

struct Edge {
	int u, v, w;
} E[N];

int fa[N];

int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }

int main() {

	File();
	
	int t = read();
	while(t--) {
		n = read(); m = read(); k = read();
		For(i, 1, n) fa[i] = i;
		For(i, 1, m) {
			E[i].u = read(), E[i].v = read(), E[i].w = read();
		}
		sort(E + 1, E + m + 1, [&](const Edge &lhs, const Edge &rhs) { return lhs.w < rhs.w; });

		int maxv = 0, minv = -1, tmpv = -1; long long sumv = 0;
		For(i, 1, m) {
			int u = E[i].u, v = E[i].v, w = E[i].w;
			if(find(u) != find(v)) {
				fa[find(u)] = find(v); maxv = w;
				if (w > k) sumv += w - k;
			} else {
				if (w > k && !~minv) minv = w;
				if (w <= k) chkmax(tmpv, w);
			}
		}

		if (maxv <= k) {
			ans = k - maxv;
			if(~tmpv) chkmin(ans, (long long)(k - tmpv));
			if(~minv) chkmin(ans, (long long)(minv - k));
		} else {
			ans = sumv;
		}
		printf("%lld\n", ans);

	}

	return 0;

}