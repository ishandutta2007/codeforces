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

const int N = 1e6 + 10;
const int INF = 2e9;
                  
LL t[N], rt[N];

int main(){    
	ios_base::sync_with_stdio(0);
	cin.tie(0);                                                  
	#ifdef LOCAL    
   		freopen(".in", "r", stdin);
   		freopen(".out", "w", stdout); 
	#endif              
	LL n, a, b, T;
	cin >> n >> a >> b >> T;
	string s;
	cin >> s;  
	t[0] = 1;      
	if (s[0] == 'w')
		t[0] += b;
	forab(i, 1, n) {
		t[i] = t[i - 1] + 1 + a;
		if (s[i] == 'w')
			t[i] += b;
	}   
	rt[n - 1] = 1;
	if (s[n - 1] == 'w')	
		rt[n - 1] += b;
	fornr(i, n - 1) {
		rt[i] = rt[i + 1] + 1 + a;
		if (s[i] == 'w')
			rt[i] += b;
	}
	LL ans = 0;	
	forn(i, n) {
		if (t[i] > T)
			break;
		ans = max(ans, i + 1ll);
		int l = i, r = n;
		while (r - l > 1) {
			int m = (l + r) / 2;
			LL Time = t[i] + rt[m] + a * (i + 1);
			if (Time <= T)
				r = m;
			else
				l = m;
		}         
		ans = max(ans, i + 1 + n - r);	
	}
	string ss = s;
	ss[0] = s[0];
	forab(i, 1, n){
		ss[i] = s[n - i];
	}
	s = ss;
	t[0] = 1;      
	if (s[0] == 'w')
		t[0] += b;
	forab(i, 1, n) {
		t[i] = t[i - 1] + 1 + a;
		if (s[i] == 'w')
			t[i] += b;
	}   
	rt[n - 1] = 1;
	if (s[n - 1] == 'w')	
		rt[n - 1] += b;
	fornr(i, n - 1) {
		rt[i] = rt[i + 1] + 1 + a;
		if (s[i] == 'w')
			rt[i] += b;
	}
	forn(i, n) {
		if (t[i] > T)
			break;
		ans = max(ans, i + 1ll);
		int l = i, r = n;
		while (r - l > 1) {
			int m = (l + r) / 2;
			LL Time = t[i] + rt[m] + a * (i + 1);
			if (Time <= T)
				r = m;
			else
				l = m;
		}         
		ans = max(ans, i + 1 + n - r);	
	}
	cout << ans << '\n';	
	return 0;
}