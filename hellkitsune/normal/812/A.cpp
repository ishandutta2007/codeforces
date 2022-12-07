#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a[4][4];

int main() {
    forn(i, 4) forn(j, 4) {
        cin >> a[i][j];
    }
    forn(i, 4) if (a[i][3]) {
        int pre = (i + 3) % 4;
        int nx = (i + 1) % 4;
        int op = (i + 2) % 4;
        if (a[i][0] || a[i][1] || a[i][2] || a[op][1] || a[pre][2] || a[nx][0]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}