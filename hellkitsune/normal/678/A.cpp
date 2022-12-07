#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, k;

int main() {
    cin >> n >> k;
    LL ans = n / k * k;
    while (ans <= n) ans += k;
    cout << ans << endl;
    return 0;
}