#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
set<int> se;
vector<int> v[300000];
int tot = 0;

int main() {
    scanf("%d%d", &n, &q);
    int zzz = 0;
    forn(i, q) {
        int qt, x;
        scanf("%d%d", &qt, &x), --x;
        if (qt == 1) {
            se.insert(zzz);
            v[x].pb(zzz);
            ++tot;
            ++zzz;
        } else if (qt == 2) {
            for (int z : v[x]) if (se.count(z)) {
                se.erase(z);
                --tot;
            }
            v[x].clear();
        } else if (qt == 3) {
            while (!se.empty()) {
                int val = *se.begin();
                if (val > x) break;
                se.erase(se.begin());
                --tot;
            }
        }
        printf("%d\n", tot);
    }
    return 0;
}