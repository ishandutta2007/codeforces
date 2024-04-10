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
const int MAXN = 1000500;

int f[MAXN];

int rsq(int rx) {
	if (rx < 0) {
		return 0;
	}
	
	rx++;
	int ans = 0;
	for (int a = rx; a > 0; a -= a & -a)
		ans += f[a];
	return ans;
}

void add(int rx, int k) {
	rx++;
	for (int a = rx; a < MAXN; a += a & -a)
		f[a] += k;
}

int n, k;

int get(int L, int R) {
	if (L <= R) {
		return rsq(R) - rsq(L - 1);
	} else {
		return get(0, R) + get(L, n - 1);	
	}
}

ll ans;

int main() {
	
	while (cin >> n >> k) {
		k = min(k, n - k);
		int v = 0, nv, L, R;
		memset(f, 0, sizeof(f));
		
		ans = 1;
		forn(i, n) {
			nv = v + k;
			if (nv >= n) {
				nv -= n;
			}
			
			L = v + 1;
			if (L >= n) {
				L -= n;
			}
			
			R = nv - 1;
			if (R < 0) {
				R += n;
			}
			
			ans += get(L, R) + 1;
			add(v, 1);
			add(nv, 1);
			
			printf("%I64d ", ans);
			
			v = nv;
		}
		
		cout << '\n';
	}
		
	return 0;
}