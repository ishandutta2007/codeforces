#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int x[3], y[3];
set<PII> se;

int main() {
    forn(i, 3) cin >> x[i] >> y[i];
    forn(i, 3) {
        int xx = x[i];
        int yy = y[i];
        forn(j, 3) if (j != i) {
            xx += x[j] - x[i];
            yy += y[j] - y[i];
        }
        se.insert(mp(xx, yy));
    }
    cout << int(se.size()) << endl;
    for (PII x : se) {
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}