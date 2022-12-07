#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, len;
int a[50], b[50];

bool check() {
    forn(i, n) if (a[i] != b[i]) {
        return false;
    }
    return true;
}

void sh() {
    forn(i, n - 1) {
        a[i] = a[i + 1];
    }
    a[n - 1] = len;
    int x = a[0];
    forn(i, n) {
        a[i] -= x;
    }
}

int main() {
    cin >> n >> len;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    int x = a[0];
    forn(i, n) a[i] -= x;
    x = b[0];
    forn(i, n) b[i] -= x;
    forn(i, n) {
        if (check()) {
            cout << "YES" << endl;
            return 0;
        }
        sh();
    }
    cout << "NO" << endl;
    return 0;
}