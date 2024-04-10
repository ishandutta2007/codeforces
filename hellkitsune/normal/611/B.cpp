#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL a, b;
int ans = 0;

int main() {
    cin >> a >> b;
    LL tot = 0;
    for (LL x = 1; x <= 1ll << 61; x <<= 1) {
        tot |= x;
        for (LL y = 1; y < x; y <<= 1) {
            LL z = tot ^ y;
            if (z >= a && z <= b) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}