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

const int N = 3e5 + 10;
const int INF = 2e9;


string s;
int a[N], used[N];

int main(){    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef EGOR                                                  
		assert(freopen("in", "r", stdin));
		assert(freopen("out", "w", stdout)); 
	#endif
	int n;
	cin >> n;
	cin >> s;
	forn(i, n)
		cin >> a[i];
	int now = 0;
	while(!used[now]) {
		used[now] = 1;
		if (s[now] == '<') {
			now -= a[now];
		} else {
			now += a[now];
		}
		if (now < 0 || now >= n) {
			cout << "FINITE\n";
			return 0;
		}
	}
	cout << "INFINITE\n";


	return 0;	
}