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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1000500;
const ll LINF = (ll)1E18;

int n;
ll a, b;
int p[MAXN];
ll dpL[MAXN], dpR[MAXN];
int ok[MAXN][3];
int sz;
int divs[MAXN];
ll ans;        

int main() {

    cin >> n >> a >> b;
    forn(i, n)
    	scanf("%d", &p[i]);
    if (n == 1) {
    	cout << 0 << '\n';
    	return 0;
    }
    
    ans = LINF;	
    sz = 0;
    for (int d = -1; d <= 1; d++) {
    	for (int i = 0; i < n; i += n - 1) {
    		int x = p[i] + d;

    		for (ll p = 2; p * p <= x; p++) {
    			if (x % p == 0) {
    				divs[sz++] = p;
    				while (x % p == 0)
    					x /= p;	
    			}
    		}
    		
    		if (x > 1)
    			divs[sz++] = x;    		
    	}
    }
    
    sort(divs, divs + sz);
    sz = unique(divs, divs + sz) - divs;
    
    for (int num = 0; num < sz; num++) {
    	int D = divs[num];

    	forn(i, n + 3) {
    		dpL[i] = dpR[i] = LINF;	
    	}
    	
    	for (int i = 0; i < n; i++)
    		for (int d = -1; d <= 1; d++)
    			ok[i][d + 1] = ((p[i] + d) % D == 0);
    			
    		
    	dpL[0] = 1ll * a * n;
    	for (int i = 0; i < n; i++) {
    		for (int d = -1; d <= 1; d++) {
    			if (ok[i][d + 1]) {
    				dpL[i + 1] = min(dpL[i + 1], dpL[i] - a + b * abs(d));	
    			}
    		}
    	}
    	
    	dpR[n] = 0;
    	for (int i = n - 1; i >= 0; i--) {
    		for (int d = -1; d <= 1; d++) {
    			if (ok[i][d + 1]) {
    				dpR[i] = min(dpR[i], dpR[i + 1] - a + b * abs(d));	
    			}
    		}
    	}
    	
    	ll curMin;
    	
    	curMin = LINF;
        for (int i = n; i > 0; i--) {
    		curMin = min(curMin, dpR[i]);
    		ans = min(ans, dpL[i] + curMin);	
    	}
    	
    	curMin = LINF;
        for (int i = n - 1; i >= 0; i--) {
    		curMin = min(curMin, dpR[i]);
    		ans = min(ans, dpL[i] + curMin);	
    	}
    }
    
    cout << ans << '\n';
    
    return 0;
}