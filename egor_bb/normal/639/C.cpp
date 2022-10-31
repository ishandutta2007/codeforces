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


int d[2][N], a[N];

bool cmp() {
	fornr(i, N) {
		if (d[0][i] > d[1][i])
			return true;
		else if (d[0][i] < d[1][i])
			return false;
	}
	assert(0);
	return false;
}

void sub(int i, int j) {
	int carry = 0;
	forn(q, N - 1) {
		if (d[i][q] >= d[j][q] + carry) {
			d[i][q] -= d[j][q] + carry;
			carry = 0;
		} else {
			d[i][q] = (d[i][q] + 2) - (d[j][q] + carry);
			carry = 1;
		}
	}
}

int main(){    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef EGOR                                                  
		assert(freopen("in", "r", stdin));
	//	assert(freopen("out", "w", stdout)); 
	#endif
	int n, k;
	cin >> n >> k;
	forn(i, n + 1) {
		int t; cin >> t;
		a[i] = t;
		int sign = 0;
		if (t < 0)
			sign = 1, t *= -1;
		forn(j, 31) {
			if ((1ll << j) & t) {
				d[sign][i + j]++;
			}
		}
	}
	forn(i, N - 1) {
		forn(j, 2) {
			d[j][i + 1] += d[j][i] / 2;
			d[j][i] %= 2;		
		}
	}
	if (cmp()) {
		sub(0, 1);
		int l = 0;
		while (!d[0][l])
			l++;
		int r = N - 1;
		while (!d[0][r])
			r--;
		if (r - l > 31)
			cout << 0 << '\n';
		else {
			LL ans = 0, add = 0;
			forab(i, l, r + 1) {
				if (d[0][i])
					add |= (1ll << (i - l));
			}
	//		cerr  << add << " " << l << '\n';
			forn(i, min(l + 1, n + 1)) {
				if (i + 32 >= r) {
					LL delta = (k + a[i]);
		//			cerr << delta << '\n';
					if (delta >= (add << (l - i))) {
						if (i == n && (add << (l - i)) == a[i])						
							continue;							
						else 
							ans++;  
					}
				}
			}
			cout << ans << '\n';
		}
	} else {
		sub(1, 0);
		int l = 0;
		while (!d[1][l])
			l++;
		int r = N - 1;
		while (!d[1][r])
			r--;
		if (r - l > 31)
			cout << 0 << '\n';
		else {
			LL ans = 0, add = 0;
			forab(i, l, r + 1) {	
				if (d[1][i])
					add |= (1ll << (i - l));
			}
			forn(i, min(l + 1, n + 1)) {
				if (i + 32 >= r) {
					LL delta = (k - a[i]);
					if (delta >= (add << (l - i))) {
						if (i == n && (add << (l - i)) == -a[i])
							continue;
						else 					
							ans++;  
					}
				}
			}
			if (l == n && add == -a[l])
				ans--;
			cout << ans << '\n';
		}
	}
	return 0;	
}