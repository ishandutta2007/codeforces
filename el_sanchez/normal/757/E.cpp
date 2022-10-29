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
const int INF = (int)1e9;
const int MAXN = 50;
const int MAXM = 2000500;
const int MOD = (int)1e9 + 7;
const int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};

int inv(int x) {
	int res = 1;
	int pw = MOD - 2;
	while (pw > 0) {
		if (pw & 1) {
			res = 1ll * res * x % MOD;
		}
		x = 1ll * x * x % MOD;
		pw >>= 1;
	}
	return res;
}

vi cur;
map<vi, int> chars;
int ptr = 0;
vi ch[MAXM];

void gen(int x, int pos) {
	if (pos == 8) {
	    ch[ptr] = cur;
		chars[cur] = ptr++;
	    
		return;	
	}
	
	int nx = x;
	cur.pb(0);
	while (nx < MAXM) {
		gen(nx, pos + 1);
		nx *= x;
		cur.back()++;

		int sz = (int)cur.size();
		if (sz > 1 && cur[sz - 1] > cur[sz - 2]) {
			break;
		}
	}
	
	cur.pop_back();
}

int f[MAXM], _f[MAXM];
int divs[MAXM];
int T, n, r;

int ans;

int main() {
	
	f[0] = 1;
	forab(i, 1, MAXM) {
		f[i] = 1ll * f[i - 1] * i % MOD;
	}
	_f[0] = 1;
	forab(i, 1, MAXM) {
		_f[i] = inv(f[i]);
	}
	
	memset(divs, -1, sizeof(divs));
	divs[1] = 1;
	for (int i = 2; i < MAXM; i++) {
		if (divs[i] == -1) {
			for (int j = i; j < MAXM; j += i) {
				divs[j] = i;	
			}
		}
	}
	
	cur.clear();
	//gen(1, 0);
	
	scanf("%d", &T);
	forn(tt, T) {
		scanf("%d%d", &r, &n);
		
		cur.clear();
		int x = n;
		while (x != 1) {
			cur.pb(0);
			int y = divs[x];  
			while (x % y == 0) {
				//cerr << x << endl;
				x /= y;
				cur.back()++;	
			}
		}
		
		sort(all(cur));
		reverse(all(cur));
		
		r--;
		//cerr << "---\n";
		ans = 1;
		forn(i, cur.size()) {
			int mult = 0;
			//cerr << cur[i] << endl;
			if (r >= 0) {
				forn(j, cur[i] + 1) {
					int z = (j == cur[i] ? 1 : 2);
					mult = (mult + 1ll * z * f[j + r] * _f[j] % MOD * _f[r] % MOD) % MOD;	
				}
			} else {
				mult = 2;	
			}
			
			ans = (1ll * ans * mult) % MOD;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}