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

const int N = 1005;

int a[N], b[N];

int main(){    
	ios_base::sync_with_stdio(0);
	cin.tie(0);                                                  
	#ifdef LOCAL    
   		freopen(".in", "r", stdin);
   		freopen(".out", "w", stdout); 
	#endif     
	int n; cin >> n;  
	forn(i, n)
		cin >> a[i];
	forn(i, n)
		cin >> b[i];
	int ansA = a[0];
	forab(i, 1, n)
		ansA |= a[i];
	int ansB = b[0];
	forab(i, 1, n)
		ansB |= b[i];
	cout << ansA + ansB;		  
	return 0;
}