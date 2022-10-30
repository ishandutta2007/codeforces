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

int sumS[N], sumT[N];
int cntS[N], cntT[N];

bool ok(int numS, int numT, int cntSS, int cntTT) {
	 return ((numS % 2 == numT % 2) && (numS <= numT) && (cntSS >= cntTT) && (cntSS % 3 == cntTT % 3));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = sz(s);
	int m = sz(t);
	forn(i, n) {
		sumS[i + 1] = sumS[i];
		cntS[i + 1] = cntS[i] + 1;
		if (s[i] != 'A') sumS[i + 1]++, cntS[i + 1] = 0;
	}
	forn(i, m) {
		sumT[i + 1] = sumT[i];
		cntT[i + 1] = cntT[i] + 1;
		if (t[i] != 'A') sumT[i + 1]++, cntT[i + 1] = 0;
	}
	int q;
	cin >> q;
	forn(i, q) {
		int ls, rs, lt, rt;
		cin >> ls >> rs >> lt >> rt;
		int numS = (sumS[rs] - sumS[ls - 1]);
		int numT = (sumT[rt] - sumT[lt - 1]);
		int cntSS = min(cntS[rs], rs - ls + 1);
		int cntTT = min(cntT[rt], rt - lt + 1);
		bool can = false;
		if (numS != 0 || numT == 0)
			can |= ok(numS, numT, cntSS, cntTT);
		if (cntSS >= 1)
			can |= ok(numS + 2, numT, cntSS - 1, cntTT);
		if (cntSS >= 2)
			can |= ok(numS + 2, numT, cntSS - 2, cntTT);
		if (cntSS >= 3)
			can |= ok(numS + 2, numT, cntSS - 3, cntTT); 
		if (can) {
			cout << 1;	
		} else {
			cout << 0;
		}
	}
	cout << '\n';
	return 0;
}