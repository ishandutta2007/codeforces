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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 55;

int n;
int a[MAXN][MAXN];
int used[MAXN], res[MAXN];

int main() {

    cin >> n;
    forn(i, n)
    	forn(j, n) {
    		cin >> a[i][j];
    		a[i][j]--;	
    	}
    	
    memset(res, -1, sizeof(res));
    
    forn(i, n) {
    	forn(j, n) {
    		bool ok = 1;
    		forn(k, n)
    			if (!used[k] && a[j][k] != -1 && a[j][k] != i) {
    				ok = 0;
    				break;
    			}
    			
    		if (ok) {
    			res[j] = i;
    			used[j] = 1;
    			break;
    		}
    	}
    }
    
    forn(i, n)
    	if (res[i] == -1)
    		res[i] = n - 1;

    forn(i, n)
    	cout << res[i] + 1 << ' ';
    cout << '\n';
     
	return 0;
}