#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 
#include <cstdio>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 1e5 + 100;
const int SQRT = 1500;

vector <int> up[N], down[N];
vector <pair<int, pii>> q[N];
set<int> pos;
int ans[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int m;
    scanf("%d%d", &n, &m);
	forn(i, m) {
		int l, r;
    	scanf("%d%d", &l, &r);
		l--, r--;
		up[l].pb(r);
		down[r].pb(l);
	}
	forn(i, n) {
		sort(all(up[i]));
		sort(all(down[i]));
	}
	int qq;
    scanf("%d", &qq);
	forn(i, qq) {
		int x, y;
    	scanf("%d%d", &x, &y);
		x--, y--;
		if (y - x <= SQRT) {
			int mx = x;
			forab(p, x, y + 1) {
				if (p > mx)
				 	break;
				auto ok = upper_bound(all(up[p]), y);
				if (ok == up[p].begin())
					continue;
				ok--;
				mx = max(mx, *ok);
			}
			ans[i] = mx;
		} else {
			q[x / SQRT].pb(mp(y, mp(x, i)));
		}
	}
	forn(i, n) {
		sort(all(q[i]));
	}
	forn(i, n / SQRT + 1) {
		if (sz(q[i]) == 0)
			continue;
		int start = SQRT * (i + 1) - 1, now = start;
		forn(j, n)
			pos.insert(j);
		for(auto query : q[i]) {
			int y = query.fst, x = query.snd.fst, id = query.snd.snd;
			while(now < y) {
				now++;
				auto ok = lower_bound(all(down[now]), start);
				if (ok == down[now].end())
					continue;
				int p = *ok;
				while(1) {
					auto it = pos.lower_bound(p);
					if (*it < now)
						pos.erase(it);
					else
						break;
				}
			}
			int mx = x;
			forab(p, x, start + 1) {
				if (p > mx)
				 	break;
				auto ok = upper_bound(all(up[p]), y);
				if (ok == up[p].begin())
					continue;
				ok--;
				mx = max(mx, *ok);
			}
			ans[id] = *pos.lower_bound(mx);
		}
	}
	forn(i, qq) {
		printf("%d\n", ans[i] + 1);
	}	
	return 0;
}