#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int main() {
    LL a, b;
    cin >> a >> b;
    a = min(a, b);
    LL ans = 1;
    while (a > 1) {
        ans *= a;
        --a;
    }
    cout << ans << endl;
    return 0;
}