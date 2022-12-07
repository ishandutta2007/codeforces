#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int mn[1005];
int vals[1005];
bool bad[1005];

const int INF = int(1e9) + 123;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n) mn[i] = INF;
    forn(i, 10) forn(val, 2) {
        vector<int> v;
        forn(j, n) {
            int bit = (j >> i) & 1;
            if (bit == val) {
                v.pb(j);
            }
        }
        if (v.empty()) {
            continue;
        }
        cout << int(v.size()) << endl;
        bool firstTime = true;
        for (int x : v) {
            if (!firstTime) {
                cout << ' ';
            }
            firstTime = false;
            cout << x + 1;
        }
        cout << endl;
        forn(i, n) {
            bad[i] = false;
        }
        for (int x : v) {
            bad[x] = true;
        }
        forn(i, n) {
            int x;
            cin >> x;
            if (!bad[i]) {
                mn[i] = min(mn[i], x);
            }
        }
    }
    cout << -1 << endl;
    forn(i, n) {
        if (i != 0) {
            cout << ' ';
        }
        cout << mn[i];
    }
    cout << endl;
    return 0;
}