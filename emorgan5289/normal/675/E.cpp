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

const int N = 1e5+5;
ll a[N], dp[N];
vector<int> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i];
    ll ans = 0;
    for (int i = n-2; i >= 0; i--) {
        while (!s.empty() && a[i] >= a[s.back()])
            s.pop_back();
        s.push_back(i);
        int x = s.size()-1;
        for (int j = 1<<30; j > 0; j /= 2)
            if (x-j >= 0 && s[x-j] < a[i]) x -= j;
        if (a[i] == n) dp[i] = n-i-1;
        else dp[i] = dp[s[x]]+n-a[i]+s[x]-i;
        ans += dp[i];
    }
    cout << ans << "\n";
}