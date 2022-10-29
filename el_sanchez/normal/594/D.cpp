#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 200500;
const int MAXM = 1005000;
const int MAXK = 262144;
const ll MOD = (int)1E9 + 7;    

ll inv(ll x) {
	ll ans = 1, pw = MOD - 2;
	while (pw > 0) {
		if (pw & 1)
			ans = (ans * x) % MOD;
		x = (x * x) % MOD;
		pw >>= 1;
	}
	return ans;
}

ll t[2 * MAXK + 3];

void mul(int pos, int val) {
	pos = MAXK + pos;
	t[pos] = (t[pos] * val) % MOD;
	while (pos > 1) {
		pos >>= 1;
		t[pos] = (t[pos * 2] * t[pos * 2 + 1]) % MOD;
	}
}

ll get(int v, int L, int R, int lx, int rx) {
	if (rx <= L || R <= lx)
		return 1;
	if (lx <= L && R <= rx)
		return t[v];
	return get(v * 2, L, (L + R) >> 1, lx, rx) * get(v * 2 + 1, (L + R) >> 1, R, lx, rx) % MOD;
}

ll get(int L, int R) {
	return get(1, 1, MAXK + 1, L + 1, R + 1);	
}

int n, m;
int lp[MAXM], invp[MAXM], last[MAXM];
int a[MAXN];
vector<pii> f[MAXN];
vector<pii> q[MAXN];
int ans[MAXN];

int main() {
	
	for (int i = 2; i < MAXM; i++)
		if (lp[i] == 0) {
			lp[i] = i;
			invp[i - 1] = inv(i - 1);  
			invp[i] = inv(i);  
			for (int j = i * 2; j < MAXM; j += i)
				lp[j] = i;
		}
		
    scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i]);
		f[i].clear();
		int x = a[i];
		while (x != 1) {
			int p = lp[x];
			f[i].pb({p, 0});
			while (x % p == 0) {
				f[i].back().Y++;
				x /= p;
			}
		}
		/*
		cout << a[i] << '\n';
		forn(j, f[i].size())
			cout << f[i][j].X << "^" << f[i][j].Y << "*\n"[j == f[i].size() - 1];
		*/
	}
	
	scanf("%d", &m);
	forn(i, m) {
		int L, R;
		scanf("%d%d", &L, &R);
		L--, R--;
		q[R].pb({L, i});
	}
	
	forn(i, 2 * MAXK + 3)
		t[i] = 1;

	memset(last, -1, sizeof(last));
	
	forn(i, n) {
		mul(i, a[i]);
		forn(j, f[i].size()) {
			int P = f[i][j].X;
			if (last[P] != -1) {
				mul(last[P], invp[P - 1]);
				mul(last[P], P);
				//cout << (ip * (P - 1)) % MOD << '\n';
				//cerr << ip << '\n';
			}
			last[P] = i;
			mul(i, P - 1);
			mul(i, invp[P]);
		}
		
		forn(j, q[i].size()) {
			int L = q[i][j].X;
			int id = q[i][j].Y;
			ans[id] = get(L, i + 1);	
		}
	}        	
	
	forn(i, m)
		printf("%d\n", ans[i]);      		
		
	return 0;
}