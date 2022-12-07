#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (n == 2 || n == 3 || (k != 2 && k != 3)) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 4 && k == 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << n - 1 << endl;
    if (n == 4 || k == 2) {
        forn(i, n - 1) {
            cout << i + 1 << ' ' << i + 2 << '\n';
        }
        return 0;
    }
    cout << "1 2\n";
    cout << "1 3\n";
    for (int i = 4; i <= n; ++i) {
        cout << "2 " << i << '\n';
    }
    return 0;
}