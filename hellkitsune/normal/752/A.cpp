#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;

int main() {
    cin >> n >> m >> k;
    --k;
    cout << k / (2 * m) + 1 << ' ';
    cout << k % (2 * m) / 2 + 1 << ' ';
    if (k % 2 == 0) {
        cout << 'L' << endl;
    } else {
        cout << 'R' << endl;
    }
    return 0;
}