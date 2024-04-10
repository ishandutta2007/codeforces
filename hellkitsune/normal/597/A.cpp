#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL k, a, b;

int main() {
    cin >> k >> a >> b;
    LL kk = k;
    while (kk < LL(1e18) + 10) kk <<= 1;
    a += kk;
    b += kk;
    LL ans = b / k - (a - 1) / k;
    cout << ans << endl;
    return 0;
}