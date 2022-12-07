#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[50][50];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n) forn(j, n) cin >> a[i][j];
    forn(i, n) forn(j, n) {
        bool ok = a[i][j] == 1;
        forn(ii, n) forn(jj, n) {
            if (a[ii][j] + a[i][jj] == a[i][j]) {
                ok = true;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}