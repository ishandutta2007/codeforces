#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
set<int> se;

int main() {
    int res = -int(1e9);
    forn(i, 1005) {
        se.insert(i * i);
    }
    scanf("%d", &n);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        if (!se.count(x)) {
            res = max(res, x);
        }
    }
    cout << res << endl;
    return 0;
}