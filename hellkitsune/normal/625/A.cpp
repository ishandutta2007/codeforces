#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, a, b, c;

int main() {
    cin >> n >> a >> b >> c;
    LL ans = n / a;
    if (b - c < a) {
        ans = max(0ll, n - c) / (b - c);
        n -= ans * (b - c);
        ans += n / a;
    }
    cout << ans << endl;
    return 0;
}