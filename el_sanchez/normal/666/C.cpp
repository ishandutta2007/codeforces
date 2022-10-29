#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 100500;
const int C = 600;
const int MOD = (int)1E9 + 7;

int inv(ll x) {
	int p = MOD - 2;
	ll res = 1;
	while (p > 0) {
		if (p & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		p >>= 1;
	}
	return res;
}

int T, t;
string s;
int len, n, z;
int sz;
pii queries[MAXN];
int dp[C][MAXN];
int numLen;
int lens[MAXN];
int pw25[2 * MAXN];
int inum[2 * MAXN];

int main() {

	inum[0] = 1;
	for (int i = 1; i < 2 * MAXN; i++)
		inum[i] = inv(i);
		
	pw25[0] = 1;
	forab(i, 1, 2 * MAXN)
		pw25[i] = (1ll * pw25[i - 1] * 25) % MOD;
		
	scanf("%d", &T);
	cin >> s;

	sz = 0;
	forn(i, T) {
		scanf("%d", &t);
		if (t == 1) {
			cin >> s;
		} else {
			scanf("%d", &len);
			queries[sz++] = {(int)s.size(), len};
		}
	}
	
	numLen = 0;
	forn(i, sz)
		lens[numLen++] = queries[i].X;
	sort(lens, lens + numLen);
	numLen = unique(lens, lens + numLen) - lens;
	
	assert(numLen <= C);
	
	for (int i = 0; i < numLen; i++) {
		ll res = 0;
		int m = lens[i] - 1;
		ll add = 1;
		
		for (int n = 0; n < MAXN; n++) {
			res = (res * 26) % MOD;
			res = (res + 1ll * pw25[n] * add) % MOD;
			
			dp[i][n] = res;
			
			add = (add * (m + n + 1) % MOD * 1ll * inum[n + 1] % MOD) % MOD;
		}
	}
	    
	//forn(i, 10)
	//	cout << dp[0][i] << '\n';
		
	forn(i, sz) {
		z = queries[i].X;
		len = queries[i].Y;
		
		if (len < z) {
			printf("0\n");	
		} else {
			int lenId = lower_bound(lens, lens + numLen, z) - lens;
			n = len - z;
			printf("%d\n", dp[lenId][n]);			
		}
	}   	
	
	return 0;
}