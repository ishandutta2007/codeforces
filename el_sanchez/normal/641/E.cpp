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
const int MAXN = 1000500;

int f[MAXN];

int rsq(int rx) {
	ll ans = 0;
	for (int a = rx; a > 0; a -= a & -a)
		ans += f[a];
	return ans;
}

void add(int rx, int k) {
	for (int a = rx; a < MAXN; a += a & -a)
		f[a] += k;
}

int n;
int id[MAXN], t[MAXN], x[MAXN];
int numx, allx[MAXN];
pair<int, pii> a[MAXN];
int Lx[MAXN], Rx[MAXN], times[MAXN];

int main() {

    scanf("%d", &n);
    forn(i, n) {
    	scanf("%d%d%d", &id[i], &t[i], &x[i]);
    	allx[i] = x[i]; 
    	a[i] = {x[i], {t[i], id[i]}};
    }
    sort(a, a + n);
    
    sort(allx, allx + n);
    numx = unique(allx, allx + n) - allx;
    
    int L = 0;
    int pos;
    for (int i = 1; i <= n; i++) {
    	if (i == n || a[L].X != a[i].X) {
    		int R = i - 1;
    		
    		pos = lower_bound(allx, allx + numx, a[L].X) - allx;
    		assert(allx[pos] == a[L].X);
    		Lx[pos] = L;
    		Rx[pos] = R;
    		
    		for (int j = L; j <= R; j++)
    			times[j] = a[j].Y.X;
    		
    		L = i;
    	}
    }
		
    int timeId, C, ans;
    forn(i, n) {
    	pos = lower_bound(allx, allx + numx, x[i]) - allx;
    	timeId = lower_bound(times + Lx[pos], times + Rx[pos] + 1, t[i]) - times;
    		
    	if (id[i] == 1 || id[i] == 2) {
    		C = (id[i] == 1 ? 1 : -1);
    		add(timeId + 1, C);
    	} else {
    		ans = rsq(timeId + 1);
    		if (Lx[pos] != 0)
    			ans -= rsq(Lx[pos]);
    		
    		printf("%d\n", ans);
    	}
    }
    
	return 0;
}