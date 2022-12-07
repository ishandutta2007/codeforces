#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[24];
int b[24];
const int r[6][8] =
{{1, 3, 5, 7, 9, 11, 24, 22},
{2, 4, 6, 8, 10, 12, 23, 21},
{13, 14, 5, 6, 17, 18, 21, 22},
{15, 16, 7, 8, 19, 20, 23, 24},
{3, 4, 17, 19, 10, 9, 16, 14},
{1, 2, 18, 20, 12, 11, 15, 13}};

bool solve(int ind, int rot) {
    forn(i, 24) b[i] = a[i];
    if (rot == 0) {
        forn(i, 8) b[r[ind][i] - 1] = a[r[ind][(i + 2) % 8] - 1];
    } else {
        forn(i, 8) b[r[ind][(i + 2) % 8] - 1] = a[r[ind][i] - 1];
    }
    for (int i = 0; i < 24; i += 4) {
        if (b[i] != b[i + 1] || b[i] != b[i + 2] || b[i] != b[i + 3]) {
            return false;
        }
    }
    return true;
}

int main() {
    forn(i, 24) cin >> a[i];
    forn(i, 6) forn(j, 2) {
        if (solve(i, j)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}