#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; ++i)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define ve vector
#define pa pair

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef ve<int> vi;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;

template<typename A, typename B> bool umx (A &a, B b) {if (a < b) {a = b; return 1;} return 0;}
template<typename A, typename B> bool umn (A &a, B b) {if (b < a) {a = b; return 1;} return 0;}

typedef pll pt;
#define x first
#define y second

pt operator + (const pt &a, const pt &b) {
	return pt(a.x + b.x, a.y + b.y);
}

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

ll operator * (const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y;
}

ll operator ^ (const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

const int N = 200010;

int nmx, nmn;
pt pmx[N], pmn[N];

void solve () {
	{
		int x, y;
		cin >> x >> y;
	}
	forn (i, nmx) {
		int x, y;
		scanf("%d%d", &x, &y);
		pmx[i] = pt(x, y);
	}
	forn (i, nmn) {
		int x, y;
		scanf("%d%d", &x, &y);
		pmn[i] = pt(x, y);
	}
	ve<pt> q;
	{
		ll mx_x = 0;
		ll mx_y = 0;
		forn (i, nmn) {
			umx(mx_x, pmn[i].x);
			umx(mx_y, pmn[i].y);
		}
		pmn[nmn++] = pt(mx_x, 0);
		pmn[nmn++] = pt(0, mx_y);
		sort(pmn, pmn + nmn, [&] (const pt &a, const pt &b) {
			return (a ^ b) > 0;
		});
		forn (i, nmn) {
			while (sz(q) > 1 && ((q[sz(q) - 1] - q[sz(q) - 2]) ^ (pmn[i] - q[sz(q) - 1])) <= 0) {
				q.pop_back();
			}
			q.pb(pmn[i]);
		}
	}
	sort(pmx, pmx + nmx, [&] (const pt &a, const pt &b) {
		return (a ^ b) > 0;
	});
	int j = 0;
	forn (i, nmx) {
		while (j + 2 < sz(q) && (pmx[i] ^ q[j + 1]) < 0) {
			++j;
		}
		if (((q[j] - pmx[i]) ^ (q[j + 1] - pmx[i])) <= 0) {
			puts("Max");
			return;
		}
	}
	puts("Min");
}

int main () {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while(cin >> nmx >> nmn) {
		solve();
	}
	return 0;
}