#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int sum(int a, int b) {
    a += b;
    if(a >= M)
        a -= M;
    return a;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].f;
    }
    sort(a.begin(), a.end());

    vector<int> dp(n, 0);
    vector<int> s(n + 1, 0);

//    int l = -1, lst = -1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].s == 0)
            dp[i] = 1;

        int l = lower_bound(a.begin(), a.end(), make_pair(a[i].s, -1)) - a.begin();
        int r = lower_bound(a.begin(), a.end(), make_pair(a[i].f, -1)) - a.begin();

        dp[i] = sum(dp[i], dif(s[r], s[l]));
        s[i + 1] = sum(s[i], dp[i]);
        if(a[i].f == m)
            ans = sum(ans, dp[i]);
    }

    cout << ans << endl;
}