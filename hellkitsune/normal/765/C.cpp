#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int k, a, b;

int main() {
    cin >> k >> a >> b;
    int ans = 0;
    if (a % k != 0) {
        if (b < k) {
            cout << -1 << endl;
            return 0;
        }
        a -= a % k;
        b -= k;
        ++ans;
    }
    if (b % k != 0) {
        if (a < k) {
            cout << -1 << endl;
            return 0;
        }
        a -= k;
        b -= b % k;
        ++ans;
    }
    ans += a / k;
    ans += b / k;
    cout << ans << endl;
    return 0;
}