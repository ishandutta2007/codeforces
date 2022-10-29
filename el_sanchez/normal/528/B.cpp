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

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const ld eps = 1e-14;
const int INF = 1E9;		
const int MAXN = 200500;
const int MAXM = 262144;     

int n, ans;
pair<ll, ll> a[MAXN];
pair<ll, int> weights[MAXN];
int dp[MAXN], pos[MAXN];
int t[2 * MAXM + 300];

int getMax(int v, int l, int r, int lx, int rx) {
	if (rx < l || r < lx)
		return 0;
	if (lx <= l && r <= rx)
		return t[v];
	return max(getMax(v * 2, l, (l + r) >> 1, lx, rx),
	           getMax(v * 2 + 1, ((l + r) >> 1) + 1, r, lx, rx));
}

int getMax(int l, int r) {
	return getMax(1, 1, MAXM, l + 1, r + 1);
}

void setElem(int id, int x) {
	id = MAXM + id;
	t[id] = x;
	while (id > 1) {
		id >>= 1;
		t[id] = max(t[id * 2], t[id * 2 + 1]);	
	}
}
int main() {
                                                            
    cin >> n;
    forn(i, n)
    	scanf("%I64d %I64d", &a[i].X, &a[i].Y);
    sort(a, a + n);
    forn(i, n)
    	weights[i] = {a[i].X + a[i].Y, i};	
    sort(weights, weights + n);
    forn(i, n)
    	pos[weights[i].Y] = i;
    	
    dp[0] = 1;
    setElem(pos[0], dp[0]);
    ans = 1;
    
    for (int i = 1; i < n; i++) {
    	int id = lower_bound(weights, weights + n, mp(a[i].X - a[i].Y + 1, -INF)) - weights;
    	id--;
    	if (id < 0) {
    		dp[i] = 1;
    		setElem(pos[i], dp[i]);
    		continue;
    	}
    	dp[i] = getMax(0, id) + 1;
    	setElem(pos[i], dp[i]);
    	ans = max(ans, dp[i]);	
    }
    
    cout << ans;
	        	
	return 0;	
}