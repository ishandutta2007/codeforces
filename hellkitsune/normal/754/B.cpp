#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s[4];

void check() {
    forn(i, 2) forn(j, 4) {
        bool ok = true;
        forn(k, 3) if (s[i + k][j] != 'x') {
            ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            exit(0);
        }
    }
    forn(i, 4) forn(j, 2) {
        bool ok = true;
        forn(k, 3) if (s[i][j + k] != 'x') {
            ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            exit(0);
        }
    }
    forn(i, 2) forn(j, 2) {
        bool ok = true;
        forn(k, 3) if (s[i + k][j + k] != 'x') {
            ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            exit(0);
        }

        ok = true;
        forn(k, 3) if (s[i + 2 - k][j + k] != 'x') {
            ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    forn(i, 4) {
        cin >> s[i];
    }
    forn(i, 4) forn(j, 4) {
        if (s[i][j] == '.') {
            s[i][j] = 'x';
            check();
            s[i][j] = '.';
        }
    }
    cout << "NO" << endl;
    return 0;
}