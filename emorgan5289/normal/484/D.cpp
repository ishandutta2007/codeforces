#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1000005;
ll a[maxn], d[maxn], p[maxn], s[maxn], dp[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            d[i-1] = a[i]-a[i-1];
            s[i-1] = (i == 1 || (d[i-1] > 0) != (d[i-2] > 0)) ? i-1 : s[i-2];
            p[i-1] = d[i-1]+(i == 1 ? 0 : p[i-2]);
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (s[i] == 0)
            dp[i] = abs(p[i]);
        else {
            dp[i] = dp[s[i]-1]+abs(p[i]-p[s[i]]);
            dp[i] = max(dp[i], (s[i] == 1 ? 0 : dp[s[i]-2])+abs(p[i]-p[s[i]-1]));
        }
        debug(i, d[i], dp[i], p[i], s[i]);
    }
    cout << dp[n-2] << "\n";
}