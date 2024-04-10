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

int n, val[2];
int sz[2];
pii a[2][MAXN];
int pref[2][MAXN];
bool t[MAXN];
int ans;

int main() {

    while (cin >> n >> val[0] >> val[1]) {
        sz[0] = sz[1] = 0;
        ans = 0;
        forn(i, n) {
            char c;
            pii p;
            scanf("%d %d %c\n", &p.Y, &p.X, &c);
            if (c == 'C') {
                a[0][sz[0]++] = p;   
            } else {
                a[1][sz[1]++] = p;   
            }
        }
        forn(id, 2) {
            sort(a[id], a[id] + sz[id]);   
        }
        
        forn(id, 2) {
            if (sz[id] > 0) {
                pref[id][0] = a[id][0].Y;
                for (int i = 1; i < sz[id]; i++) {
                    pref[id][i] = max(pref[id][i - 1], a[id][i].Y);   
                }
            }
        }
        
        //0 -- 1
        int cur = 0;
        if (sz[0] > 0 && sz[1] > 0) {
            bool fail = 0;
            forn(id, 2) {
                int cur2 = -1;
                forn(i, sz[id]) {
                    if (a[id][i].X <= val[id]) {
                        cur2 = max(cur2, a[id][i].Y);
                    }
                }
                if (cur2 == -1) {
                    fail = 1;   
                }
                cur += cur2;
            }
            if (!fail) {
                ans = max(ans, cur);      
            }
        }
        
        forn(id, 2) {
            if (sz[id] > 0) {
                int ptr1 = sz[id] - 1; //can all
                for (int ptr0 = 0; ptr0 < sz[id]; ptr0++) {
                    while (ptr1 >= 0 && a[id][ptr1].X + a[id][ptr0].X > val[id]) {
                        ptr1--;   
                    }
                    
                    int pos = min(ptr1, ptr0 - 1);
                    if (pos >= 0) {
                        ans = max(ans, a[id][ptr0].Y + pref[id][pos]);   
                    }
                }
            }
        }
        
        printf("%d\n", ans);
    }
    
    
    return 0;
}