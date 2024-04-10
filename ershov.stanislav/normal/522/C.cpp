#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#define PROBLEM ""

const int N = 100500;

int a[N], t[N], r[N];
bool aft[N];
char ans[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#else
//  assert(freopen(PROBLEM".in", "r", stdin) != NULL);
//  assert(freopen(PROBLEM".out", "w", stdout));
#endif

    int tt;
    cin >> tt;
    for (; tt > 0; --tt) {
        int m, k;
        scanf("%d %d", &m, &k);
        for (int i = 1; i <= k; ++i) {
            scanf("%d", &a[i]);
            aft[i] = 0;
        }

        int id = INF, cnt = 0, bef = 0;
        for (int i = 1; i <= m - 1; ++i) {
            scanf("%d%d", &t[i], &r[i]);
            if (r[i] == 1) {
                id = min(id, i);
            }
            if (t[i] == 0) {
                ++cnt;
                if (id == INF) {
                    ++bef;
                }
            }
            else {
                a[t[i]]--;
                if (id < INF) {
                    aft[t[i]] = 1;
                }
            }
        }

        int mn = INF;
        for (int i = 1; i <= k; ++i) {
            if (!aft[i] && a[i] < mn) {
                mn = a[i];
            }
        }
        for (int i = 1; i <= k; ++i) {
            if ((!aft[i] && bef >= a[i]) || cnt - mn >= a[i]) {
                ans[i - 1] = 'Y';
            }
            else {
                ans[i - 1] = 'N';
            }
        }
        printf("%.*s\n", k, ans);
    }
    return 0;
}