#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
    freopen("io\\err.txt", "w", stderr);
#endif
}

using   ll        = long long;
#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

int main() {
    ioThings();

    dotc() {
        int n, m; cin >> n >> m;
        vector<int> time(n);
        vector<int> low(n);
        vector<int> high(n);
        for (int i = 0; i < n; i++)
            cin >> time[i] >> low[i] >> high[i];
        
        int mini = m, maxi = m, t = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int deltaT = time[i] - t;
            if (low[i] > mini)
                mini = min(low[i], mini + deltaT);
            else
                mini = max(low[i], mini - deltaT);
            if (high[i] > maxi)
                maxi = min(high[i], maxi + deltaT);
            else
                maxi = max(high[i], maxi - deltaT);
            
            if (mini > high[i] || maxi < low[i]) {
                ok = false;
                break;
            }

            mini = max(mini, low[i]);
            maxi = min(maxi, high[i]);
            t = time[i];
        }
        
        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}