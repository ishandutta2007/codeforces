#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

int main() {
    LL ans = 0;
    cin >> n >> k;
    REP(i, k) {
        if (n < 2) break;
        ans += 2 * n - 3;
        n -= 2;
    }
    cout << ans << endl;
    return 0;
}