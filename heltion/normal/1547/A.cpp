#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        P A, B, F;
        cin >> A.x >> A.y >> B.x >> B.y >> F.x >> F.y;
        int ans = abs(A.x - B.x) + abs(A.y - B.y);
        if (A.x == F.x and B.x == F.x and (A.y - F.y) * (B.y - F.y) < 0) ans += 2;
        if (A.y == F.y and B.y == F.y and (A.x - F.x) * (B.x - F.x) < 0) ans += 2;
        cout << ans << "\n";
    }
    return 0;
}