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

int cnt[26];
char f[13][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	char x;
	forn(i, sz(s)) {
		cnt[s[i] - 'A']++;
		if (cnt[s[i] - 'A'] == 2) {
			x = s[i];
		}	
	}
	int l = -1, r;
	forn(i, sz(s)) {
		if (s[i] == x) {
			if (l == -1)
				l = i;
			else
				r = i;
		}
	}
	if (r - l == 1) {
		cout << "Impossible\n";
		return 0;
	}
	int len = r - l - 1;
	f[len / 2][0] = x;
	int pos = len / 2, t = 0;
	forab(i, l + 1, r) {
		if (t == 1)
			pos++;
		else if (pos == 0)
			t++;
		else
			pos--;
		f[pos][t] = s[i];
	}
	pos = len / 2, t = 0;
	fornr(i, l) {
		if (t == 1)
			pos--;
		else if (pos == 12)
			t++;
		else
			pos++;
		f[pos][t] = s[i];
	}
	forba(i, r + 1, sz(s)) {
		if (t == 1)
			pos--;
		else if (pos == 12)
			t++;
		else
			pos++;
		f[pos][t] = s[i];
	}
	forn(i, 13)
		cout << f[i][0];
	cout << '\n';
	forn(i, 13)
		cout << f[i][1];
	cout << '\n';
	return 0;
}