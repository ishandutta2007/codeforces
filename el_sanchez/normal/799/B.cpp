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
const int MAXN = 200500;

int n, cost[MAXN];
set<pii> c[2][3];
int a[MAXN], b[MAXN];

int main() {

    while (cin >> n) {
        forn(i, n) {
            scanf("%d", &cost[i]);
        }
        
        forn(i, n) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        forn(i, n) {
            scanf("%d", &b[i]);
            b[i]--;
        }
        
        forn(i, n) {
            c[0][a[i]].insert(mp(cost[i], b[i]));
            c[1][b[i]].insert(mp(cost[i], a[i]));
        }
        
        int m;
        scanf("%d", &m);
        forn(qq, m) {
            int id;
            scanf("%d", &id);
            id--;

            int cost0, cost1, ans;
            cost0 = 2 * INF;
            cost1 = 2 * INF;
            
            if (!c[0][id].empty()) {
                auto P = *c[0][id].begin();
                cost0 = P.X;
            }
            
            if (!c[1][id].empty()) {
                auto P = *c[1][id].begin();
                cost1 = P.X;
            }

            if (cost0 <= cost1 && cost0 < 2 * INF) {
                auto P = *c[0][id].begin();
            
                c[0][id].erase(P);

                int curCost = P.X;
                int id2 = P.Y;
                c[1][id2].erase(mp(curCost, id));   
                
                ans = curCost;
            } else if (cost0 >= cost1 && cost1 < 2 * INF) {
                auto P = *c[1][id].begin();
            
                c[1][id].erase(P);

                int curCost = P.X;
                int id2 = P.Y;
                c[0][id2].erase(mp(curCost, id));

                ans = curCost;                 
            } else {
                assert(cost0 == 2 * INF);
                assert(cost1 == 2 * INF);
                
                ans = -1;
            }
            
            printf("%d%c", ans, " \n"[qq == m - 1]);
        }
    }
    
    return 0;
}