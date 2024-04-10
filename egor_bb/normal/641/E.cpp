#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

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

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 1e6 + 10;
const int INF = 2e9;

struct Q{
	int a, t, x, id;
	Q(int a, int t, int x, int id) : a(a), t(t), x(x), id(id) {}
	Q() = default;
};

bool cmp(Q a, Q b){ 
	return a.t < b.t;
}

Q quer[N];
int val[N];
vector <int> add[N], del[N];
int answer[N];

int main(){    
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
	#ifdef EGOR                                                  
		assert(freopen("in", "r", stdin));
//		assert(freopen("out", "w", stdout)); 
	#endif
	int n;
	assert(scanf("%d", &n) == 1);
	forn(i, n) {
		answer[i] = INF;
		int a, t, x;
		assert(scanf("%d%d%d", &a, &t, &x) == 3);
		quer[i] = Q(a, t, x, i);
		val[i] = x;
	}
	sort(quer, quer + n, cmp);
	sort(val, val + n);
	int m = unique(val, val + n) - val;
	forn(i, n) {
		quer[i].x = lower_bound(val, val + m, quer[i].x) - val;
	}
	forn(i, n) {
		if (quer[i].a == 1) {
			add[quer[i].x].pb(quer[i].id);
		} else if (quer[i].a == 2) {
			del[quer[i].x].pb(quer[i].id);
		} else {
			int ans = lower_bound(all(add[quer[i].x]), quer[i].id) - add[quer[i].x].begin();
			ans -= lower_bound(all(del[quer[i].x]), quer[i].id) - del[quer[i].x].begin();
			assert(ans >= 0);
			answer[quer[i].id] = ans;
		}
	}
	forn(i, n) {
		if (answer[i] != INF) {
			printf("%d\n", answer[i]);
		}
	}
	return 0;	
}