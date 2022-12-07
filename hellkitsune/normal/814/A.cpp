#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[500], b[500];

int main() {
    cin >> n >> m;
    forn(i, n) cin >> a[i];
    forn(i, m) cin >> b[i];
    forn(i, m - 1) if (b[i] != b[i + 1]) {
        cout << "Yes" << endl;
        return 0;
    }
    forn(i, n) if (a[i] == 0) {
        a[i] = b[0];
    }
    forn(i, n - 1) if (a[i] >= a[i + 1]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}