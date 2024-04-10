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

const int N = 2e5 + 10;
            
LL ans = 0;

unordered_map <int, int> cnt_x, cnt_y;
map <pii, int> point;

int main(){    
	ios_base::sync_with_stdio(0);
	cin.tie(0);                                                  
	#ifdef LOCAL    
   		freopen(".in", "r", stdin);
   		freopen(".out", "w", stdout); 
	#endif     
	int n; cin >> n;
	forn(i, n) {
		int x, y; cin >> x >> y;
		ans += cnt_x[x]; cnt_x[x]++;
		ans += cnt_y[y]; cnt_y[y]++;
		ans -= point[mp(x, y)]; point[mp(x, y)]++;
	} 
	cout << ans << '\n';


	return 0;
}