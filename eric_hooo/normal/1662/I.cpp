#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define tab "\t"
#define endl "\n"

#define ferr std::cerr

#ifdef DEBUG
std::ifstream fin("in");
std::ofstream fout("out");
#else
#define fin std::cin
#define fout std::cout
#endif

using i64 = long long;

inline void umax(i64 &x, i64 y) { if (y > x) x = y; }

const int mxn = 2e5 + 5;
int n, m;
int p[mxn], x[mxn];
i64 sp[mxn];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	fin >> n >> m;
	rep(i, n) fin >> p[i];
	rep(i, n) sp[i + 1] = sp[i] + p[i];
	rep(i, m) fin >> x[i];
	std::sort(x, x + m);
	i64 ans = 0;
	{
		i64 cur = 0;
		rep(i, n) if (i * 100 < x[0]) cur += p[i];
		umax(ans, cur);
	}
	{
		i64 cur = 0;
		rep(i, n) if (i * 100 > x[m - 1]) cur += p[i];
		umax(ans, cur);
	}
	rep(i, m - 1) {
		static int L = 0, R = 0;
		while (L < n && L * 100 <= x[i]) ++ L;
		while (R < n && R * 100 < x[i + 1]) ++ R;
		for (int a = L, b = L; a < R; ++ a) {
			while (b < R && (b - a) * 200 < (x[i + 1] - x[i])) ++ b;
			umax(ans, sp[b] - sp[a]);
		}
	}
	fout << ans << endl;
	return 0;
}