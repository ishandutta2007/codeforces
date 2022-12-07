#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
set<int> se;

int main() {
    scanf("%d%d", &n, &k);
    int mask = 0;
    forn(i, k) mask |= 1 << i;
    forn(i, n) {
        int cur = 0;
        forn(j, k) {
            int x;
            scanf("%d", &x);
            if (x == 0) cur |= 1 << j;
        }
        if (cur == mask) {
            cout << "YES" << endl;
            return 0;
        }
        se.insert(cur);
    }
    for (int x : se) for (int y : se) {
        if ((x | y) == mask) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}