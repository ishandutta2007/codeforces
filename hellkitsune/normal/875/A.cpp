#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> ans;

int main() {
    cin >> n;
    for (int x = max(1, n - 1000); x <= n; ++x) {
        int cur = x;
        for (int y = x; y > 0; y /= 10) {
            cur += y % 10;
        }
        if (cur == n) {
            ans.pb(x);
        }
    }
    cout << (int)ans.size() << endl;
    for (int x : ans) cout << x << ' ' ;
    cout << endl;
    return 0;
}