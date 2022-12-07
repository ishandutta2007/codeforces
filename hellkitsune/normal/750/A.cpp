#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

int main() {
    cin >> n >> k;
    k = 240 - k;
    int ans = 0;
    for (int i = 1; 5 * i <= k && i <= n; ++i) {
        k -= 5 * i;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}