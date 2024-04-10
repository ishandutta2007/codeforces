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
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 1e3 + 5;

pii a[MAX_N];
vector<pii> ans;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i].fs), a[i].sc = i;
	if (a[0].fs == 0) {
	 	puts("-1");
	 	return 0;
	}
	sort(a + 1, a + n);
	reverse(a + 1, a + n);
	int toSendIt = 1;
	int curIt = 0;
	while (toSendIt < n) {
		while (curIt < n && a[curIt].fs == 0) 
			curIt++;
		if (curIt == n) {
		 	puts("-1");
		 	return 0;
		}
		a[curIt].fs--;
		ans.pb({a[curIt].sc, a[toSendIt++].sc});
	}
	printf("%d\n", sz(ans));
	for (auto np : ans)
		printf("%d %d\n", np.fs + 1, np.sc + 1);
	return 0;
}