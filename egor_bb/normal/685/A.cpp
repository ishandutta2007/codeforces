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

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

int calc(int x) {
	--x;
	if (!x)
		return 1;
	int ans = 0;
	while(x) {
		x /= 7;
		ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int c1 = calc(n), c2 = calc(m);	
	if (c1 + c2 > 7) {
		cout <<	0 << '\n';
		return 0;
	}	
	int k = c1 + c2, ans = 0;
	forn(mask, 1 << 7) {
		if (__builtin_popcount(mask) != k)
			continue;
		int c = 0;
		vector <int> v(k);
		forn(i, 7) {
			if ((1 << i) & mask)
				v[c++] = i; 
		}
		vector <int> perm(k);
		forn(i, k)
			perm[i] = i;
		do {
			LL v1 = 0;
			forn(i, c1)
				v1 = v1 * 7 + v[perm[i]];
			LL v2 = 0;
			forn(i, c2)
				v2 = v2 * 7 + v[perm[i + c1]];
			if (v1 < n && v2 < m)
				ans++;
		} while(next_permutation(all(perm)));
	}
	cout << ans << '\n';
	return 0;
}