#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int t;
string dir;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int cur = 0;
    bool ok = true;
    forn(i, n) {
        cin >> t >> dir;
        if (dir[0] == 'S') {
            cur += t;
        } else if (dir[0] == 'N') {
            cur -= t;
        } else if (cur == 0 || cur == 20000) {
            ok = false;
        }
        if (cur > 20000 || cur < 0) {
            ok = false;
        }
    }
    if (cur != 0) {
        ok = false;
    }
    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}