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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

int n, k;
string s;
int a[MAXN], nxt[MAXN], prv[MAXN];
int ans;

int main() {

	cin >> n >> k;
	cin >> s;
	forn(i, n)
		a[i] = (s[i] == '1');

	nxt[n - 1] = -1;
	for (int i = n - 2; i >= 0; i--)
		if (a[i + 1] == 0)
			nxt[i] = i + 1;
		else
			nxt[i] = nxt[i + 1];
			
	prv[0] = -1;
	for (int i = 1; i < n; i++)
		if (a[i - 1] == 0)
			prv[i] = i - 1;
		else
			prv[i] = prv[i - 1];
	
	int L = 0, R;
	if (a[L] == 0)
		L = 0;
	else
		L = nxt[0];
		
	R = L;
	forn(i, k)
		R = nxt[R];
		
	ans = n;
	while (R != -1) {
	    if (k == 1) {
	    	ans = min(ans, R - L);	
	    } else {
	    	int mid = (L + R) >> 1;
	    	mid = prv[mid];
	    	if (mid != L)
	    		mid = prv[mid];

	    	forn(i, 5) {
	    		assert(a[mid] == 0);
	    		assert(L <= mid && mid <= R);
	    		ans = min(ans, max(mid - L, R - mid));
	    		
	    		if (mid == R)
	    			break;
	    		mid = nxt[mid];
	    	}
	    }
		
		L = nxt[L];
		R = nxt[R];		
	}

	cout << ans << '\n';		
	
	return 0;
}