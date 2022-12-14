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

    int n, a; cin >> n >> a;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    
    a--;
    int sum = t[a];
    for (int d = 1; a - d >= 0 || a + d < n; d++) {
        if (a - d < 0 && t[a + d])
            sum++;
        else if (a + d >= n && t[a - d])
            sum++;
        else if (a - d >= 0 && a + d < n && t[a - d] && t[a + d])
            sum += 2;
    }

    cout << sum;

    return 0;
}