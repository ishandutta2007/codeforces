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
const int INF = 2e9;

int a[N];
vector <int> ans;
    
int main(){    
	ios_base::sync_with_stdio(0);
	cin.tie(0);                                                  
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout); 
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	n++;
	forab(i, 1, n)
		cin >> a[i];
	sort(a, a + n);
	a[0] = -1;
	int max_x = 0;
	forn(i, n) {
		if (max_x <= a[i]) 
			break;
		if (i == n - 1) {
			max_x = INF;
			break;
		}
		if (a[i] + 1 + s < a[i + 1]) {
			if (max_x < a[i + 1] - 1 + d) {
				max_x = a[i + 1] - 1 + d;
				ans.pb(i);
			}
		}		
	}	
	if (max_x < m) {
		puts("IMPOSSIBLE");
		return 0;
	}
	int x = 0;	
	forn(i, sz(ans)) {
		int to = a[ans[i] + 1] - 1, next;
		if (i < sz(ans) - 1) next = a[ans[i + 1]] + 1;
		else next = min(m, a[n - 1] + 1);
		cout << "RUN " << to - x << '\n';
		cout << "JUMP " << next - to << '\n';
		cout.flush();
		assert(to - x >= s && next - to > 0 && next - to <= d);
		x = next;
	}
	if (m != x) {
		cout << "RUN " << m - x << '\n';
	}
	return 0;	
}