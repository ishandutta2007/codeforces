#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 1e5 + 5, INF = 1e9;

int a[MAX_N], b[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, cL, cE, v;
	scanf("%d%d%d%d%d", &n, &m, &cL, &cE, &v);
	forn (i, cL)
		scanf("%d", &a[i]);
	forn (i, cE)
		scanf("%d", &b[i]);
	int q;
	scanf("%d", &q);
	forn (qq, q) {
		int x_1, y_1, x_2, y_2;
		scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
		if (x_1 > x_2)
			swap(x_1, x_2);
		if (y_1 > y_2)
			swap(y_1, y_2);
		if (x_1 == x_2) {
		    printf("%d\n", abs(y_1 - y_2));
		    continue;
		}	
		int ans = INF;
		int ind = lower_bound(a, a + cL, y_1) - a;
		if (ind != cL) 
		 	ans = min(ans, abs(a[ind] - y_1) + abs(a[ind] - y_2) + (x_2 - x_1));
		if (ind != 0)
		 	ans = min(ans, abs(a[ind - 1] - y_1) + abs(a[ind - 1] - y_2) + (x_2 - x_1));
		ind = lower_bound(b, b + cE, y_1) - b;
		if (ind != cE) 
		 	ans = min(ans, abs(b[ind] - y_1) + abs(b[ind] - y_2) + (x_2 - x_1 + v - 1) / v);
		if (ind != 0)
		 	ans = min(ans, abs(b[ind - 1] - y_1) + abs(b[ind - 1] - y_2) + (x_2 - x_1 + v - 1) / v);
		printf("%d\n", ans);
	}

	return 0;
}