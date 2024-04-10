#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int dist, b, p, cnt, full;

int main() {
    cin >> dist >> full >> p >> cnt;
    b = full;
    int ans = 0;
    forn(i, cnt) {
        if (b < p) {
            b = full - p;
            ++ans;
            if (b < p) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (b < dist) {
            if (full < dist - p) {
                cout << -1 << endl;
                return 0;
            }
            b = full + p;
            ++ans;
        }
        b -= dist;
        p = dist - p;
    }
    cout << ans << endl;
    return 0;
}