#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

pii a[N];
int dp[N];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    sort(a, a + n);

    dp[0] = 1;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        int j = int(lower_bound(a, a + n, make_pair(a[i].f - a[i].s, 0)) - a);
        if(j == 0)
            dp[i] = 1;
        else
            dp[i] = 1 + dp[j - 1];
        ans = max(ans, dp[i]);
    }

    cout << n - ans << endl;
}