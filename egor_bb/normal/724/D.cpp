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

const int N = 1e5 + 100;

int sum[N], take[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> m;
	string s;
	cin >> s;
	n = sz(s);
	forn(i, 26) {
		char c = 'a' + i;
		forn(j, n) {
			if (s[j] == c)
				take[j] = 1;
		}
		forn(j, n) 
			sum[j + 1] = sum[j] + take[j];
		int ok = 1;
		forn(j, n - m + 1) {
			if (sum[j + m] - sum[j] == 0) {
				ok = 0;
				break;
			}
		}
		if (!ok)
			continue;
		forn(j, n) {
			if (s[j] == c)
				take[j] = 0;
		}
		forn(j, n) 
			sum[j + 1] = sum[j] + take[j];
		set <int> pos;
		forn(j, n) {
			if (s[j] == c)
				pos.insert(j);
		}
		forn(j, n - m + 1) { 
			if (sum[j + m] - sum[j] == 0) {
				auto it = pos.lower_bound(j + m);
				it--;
				int id = *it;
				pos.erase(id);
				take[id] = 1;
				j = id;
			}
		}
		vector <char> cc;
		forn(j, n) {
			if (take[j])
				cc.pb(s[j]);
		}
		sort(all(cc));
		for(char ccc : cc)
			cout << ccc;
		cout << '\n';
		return 0;
	}
	assert(0);
	return 0;
}