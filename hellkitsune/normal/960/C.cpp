#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL x, d;
vector<LL> ans;

int main() {
    ios_base::sync_with_stdio(false);
    LL cur = 1;
    cin >> x >> d;
    while (x > 0) {
        ans.pb(cur);
        LL val = 1;
        while (2 * val + 1 <= x) {
            val = 2 * val + 1;
            ans.pb(cur);
        }
        x -= val;
        cur += d + 3;
    }
    cout << ans.size() << endl;
    for (LL x : ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}