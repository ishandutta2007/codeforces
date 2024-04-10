#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    LL ans = 0;
    int cur = min(a, min(c, d));
    a -= cur;
    c -= cur;
    d -= cur;
    ans += 256ll * cur;
    cur = min(a, b);
    a -= cur;
    b -= cur;
    ans += 32ll * cur;
    cout << ans << endl;
    return 0;
}