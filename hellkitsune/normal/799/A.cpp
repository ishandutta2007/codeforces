#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, t, k, d;

int main() {
    cin >> n >> t >> k >> d;
    int need = (n + k - 1) / k;
    need *= t;
    if (d + t < need) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}