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

const int N = 1e6 + 100;

int used[N], a[N];
map<int, int> num;
bitset<N> bs;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	scanf("%d%d", &n, &k);
	forn(i, n) {
    	scanf("%d", &a[i]);
		a[i]--;
	}
	vector <int> len;
	forn(i, n) {
		if (used[i])
			continue;
		int v = i, l = 0;
		while(!used[v]) {
			used[v] = 1;
			l++;
			v = a[v];
		}
		len.pb(l);
	}
	sort(all(len));
	int mx = 0, odd = 0, kk = k;
	for(int x : len) {
		if (x & 1)
			odd++;
		mx += min(x / 2, kk) * 2;
		kk -= min(x / 2, kk);
	}
	mx += min(odd, kk);
	int mn = k;
	for(int l : len) {
		num[l]++;
	}
	set <int> lens;
	for (int l : len)
		lens.insert(l);
	auto it = lens.begin();
	while(it != lens.end()) {
		int l = *it;
		int cnt = num[l];
		if (cnt <= 2) {
			it++;
			continue;
		}
		int rem = cnt - 1;
		if (rem & 1)
			rem--;
		if (rem / 2 > 0)
			lens.insert(l * 2);
		num[l * 2] += rem / 2;
		num[l] -= rem;
		it++;
	}
	bs[0] = 1;
	for (pii p : num) {
		int val = p.fst;
		forn(i, p.snd) {
			bs = bs | (bs << val);
		}
	}
	if (bs[k] == 0)
		mn++;
	cout << mn << " " << mx << '\n';
	return 0;
}