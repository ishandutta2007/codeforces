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
const int INF = (int)1e9;
const int MAXN = 100500;

int start[2], aim[2], n;
int a[MAXN], dp[MAXN];

int main() {

    while (cin >> aim[0] >> aim[1]) {
        cin >> start[0] >> start[1] >> n;
        forn(i, n) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        reverse(a, a + n);
        n = min(n, 40);
        
        memset(dp, -1, sizeof(dp));
        dp[start[0]] = start[1];
        
        bool ok = 0;
        for (int i = 0; i <= n; i++) {
            //test
            for (int j = MAXN - 1; j >= 0; j--) {
                if ((j >= aim[0] && dp[j] >= aim[1]) ||
                    (j >= aim[1] && dp[j] >= aim[0])) {
                        ok = 1;
                    }
            }
            
            if (ok) {
                printf("%d\n", i);
                break;
            }
            
            if (i == n) {
                break;
            }
                
            for (int j = MAXN - 1; j >= 1; j--) {
                int nj = min(1ll * j * a[i], 1ll * MAXN - 1);
                dp[nj] = max(dp[nj], dp[j]);
                int nres = min(1ll * dp[j] * a[i], 1ll * MAXN - 1);
                dp[j] = max(dp[j], nres);           
            }
        }
        
        if (!ok) {
            printf("-1\n");   
        }
    }
    
    return 0;
}