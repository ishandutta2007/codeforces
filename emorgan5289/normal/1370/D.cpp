#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 200005;
int a[N], dp[N];

int solve(int n, int k) {
    int x = 1, y = *max_element(a, a+n);
    while (x < y) {
        int m = (x+y)/2;
        dp[0] = a[0] <= m ? 1 : 0;
        dp[1] = max(dp[0], a[1] <= m ? 1 : 0);
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i-1], dp[i-2]+(a[i] <= m ? 1 : 0));
        if (dp[n-1] >= k) y = m;
        else x = m+1;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int out;
    if (k%2) out = solve(n, (k+1)/2);
    else out = solve(n-1, k/2);
    debug(out);
    rotate(a, a+1, a+n);
    if (k%2) out = min(out, solve(n-2, k/2));
    else out = min(out, solve(n-1, k/2));
    cout << out << "\n";
}