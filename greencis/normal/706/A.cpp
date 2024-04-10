#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ld a, b;
int n;
ld x, y, v, ans = 9e18;

int main()
{
    cin >> a >> b >> n;
    while (n--) {
        cin >> x >> y >> v;
        ans = min(ans, hypot(x - a, y - b) / v);
    }

    cout << setprecision(17) << fixed << ans << endl;

    return 0;
}