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
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n) cin >> a[i];
    int sum = 0;
    forn(i, n) {
        sum += a[i];
    }
    if (sum != 0) {
        cout << "YES" << endl << 1 << endl;
        cout << 1 << ' ' << n << endl;
        return 0;
    }
    sum = 0;
    forn(i, n) {
        sum += a[i];
        if (sum != 0) {
            cout << "YES" << endl << 2 << endl;
            cout << 1 << ' ' << i + 1 << endl;
            cout << i + 2 << ' ' << n << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}