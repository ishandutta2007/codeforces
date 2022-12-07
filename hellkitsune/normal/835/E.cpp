#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, x, y;

bool ask(vector<int> v) {
    if (v.empty()) {
        return false;
    }
    cout << "? " << (int)v.size();
    for (int x : v) {
        cout << " " << x;
    }
    cout << endl;
    int res;
    cin >> res;
    return res == y || res == (x ^ y);
}

int dif = 0;
int mask1 = 0, mask2 = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    forn(bit, 10) {
        vector<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!(i & (1 << bit))) {
                q.pb(i);
            }
        }
        if (ask(q)) {
            dif ^= 1 << bit;
        }
    }
    int f = 0;
    while (!(dif & (1 << f))) {
        ++f;
    }
    mask2 = dif;
    forn(bit, 10) if (bit != f) {
        vector<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!(i & (1 << f)) && !(i & (1 << bit))) {
                q.pb(i);
            }
        }
        if (!ask(q)) {
            mask1 ^= 1 << bit;
            mask2 ^= 1 << bit;
        }
    }
    if (mask1 > mask2) swap(mask1, mask2);
    cout << "! " << mask1 << ' ' << mask2 << endl;
    return 0;
}