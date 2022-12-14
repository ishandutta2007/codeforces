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

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    adjacent_difference(all(a), b.begin());
    
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = 0;
        for (int j = i; j > 0; j--)
            if (b[j] >= 0)
                l++;
            else
                break;

        for (int j = i + 1; j < n; j++)
            if (b[j] <= 0)
                r++;
            else
                break;
        
        maxi = max(maxi, l + r + 1);
    }

    cout << maxi;

    return 0;
}