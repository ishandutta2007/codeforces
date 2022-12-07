#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100];

int main() {
    cin >> n;
    forn(i, n) cin >> a[i];
    sort(a, a + n);
    int m = n / 2;
    forn(i, m - 1) if (a[i] != a[i + 1]) {
        cout << "NO" << endl;
        return 0;
    }
    forn(i, m - 1) if (a[m + i] != a[m + i + 1]) {
        cout << "NO" << endl;
        return 0;
    }
    if (a[0] == a[m]) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << a[0] << ' ' << a[m] << endl;
    return 0;
}