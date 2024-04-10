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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	forn(q, t) {
		int n;
		cin >> n;
		vector <int> mn, mx;
		for (int i = 1; i < n; i += 2) {
			cout << "? " << i << " " << i + 1 << endl;
			char c; cin >> c;
			if (c == '>')
				mx.pb(i), mn.pb(i + 1);
			else
				mx.pb(i + 1), mn.pb(i);
		}
		if (n & 1)
			mx.pb(n), mn.pb(n);
		while(sz(mx) > 1) {
			vector <int> new_mx;
			for (int i = 0; i < sz(mx) - 1; i += 2) {
				cout << "? " << mx[i] << " " << mx[i + 1] << endl;
				char c; cin >> c;
				if (c == '>')
					new_mx.pb(mx[i]);
				else
					new_mx.pb(mx[i + 1]);
			}
			if (sz(mx) & 1)
				new_mx.pb(mx.back());
			mx = new_mx;
		}
		while(sz(mn) > 1) {
			vector <int> new_mn;
			for (int i = 0; i < sz(mn) - 1; i += 2) {
				cout << "? " << mn[i] << " " << mn[i + 1] << endl;
				char c; cin >> c;
				if (c == '>')
					new_mn.pb(mn[i + 1]);
				else
					new_mn.pb(mn[i]);
			}
			if (sz(mn) & 1)
				new_mn.pb(mn.back());
			mn = new_mn;
		}
		cout << "! " << mn.back() << " " << mx.back() << endl;
	}	
	return 0;
}