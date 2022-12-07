#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, k;

int solve(int n, LL len, LL k) {
    if (k == len / 2) {
        return n;
    }
    if (k < len / 2) {
        return solve(n - 1, len / 2, k);
    }
    return solve(n - 1, len / 2, k - len / 2 - 1);
}

int main() {
    cin >> n >> k;
    --k;
    LL len = 1;
    forn(i, n - 1) len = 2 * len + 1;
    cout << solve(n, len, k) << endl;
    return 0;
}