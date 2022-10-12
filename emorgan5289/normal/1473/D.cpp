#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector<int> l(n+1), r(n+1), sl(n+1), sr(n+1), c(n+1);
        int x = 0;
        for (int i = 1; i <= n; i++) {
            x += (s[s.size()-i] == '-' ? 1 : -1);
            sl[i] = min(sl[i-1], x);
            sr[i] = max(sr[i-1], x);
        }
        x = 0;
        for (int i = 1; i <= n; i++) {
            x += (s[i-1] == '+' ? 1 : -1);
            l[i] = min(l[i-1], x);
            r[i] = max(r[i-1], x);
            c[i] = x;
        }
        while (m--) {
            int a, b; cin >> a >> b; a--;
            int last = c[a]+c[n]-c[b];
            cout << 1+max(r[a], last+sr[n-b])-min(l[a], last+sl[n-b]) << "\n";
        }
    }
}