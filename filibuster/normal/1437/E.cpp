#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

/*
1
228 21 11 3
*/

int solve(vector<int> a, int l, int r) {
//    cout << l << ' ' << r << endl;
//    for(auto x : a)
//        cout << x << ' ';
//    cout << endl;
    if(r < l) {
        cout << -1 << endl;
        exit(0);
    }
    int n = a.size();
    vector<int> dp(n + 1, INF);
    dp[0] = -INF;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(l <= a[i] && a[i] <= r) {
            int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[j] = a[i];
//            cout << i << ' ' << a[i] << ' ' << dp[i] << endl;
            res = max(res, j);
        }
    }

    return res;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 2);
    a[0] = -INF;
    a[n + 1] = INF;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }

    n += 2;

    vector<int> b(k + 2);
    b[0] = 0;
    b[k + 1] = n - 1;
    for(int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    k += 2;

//    for(auto x : a)
//        cout << x << ' ';
//    cout << endl;
//    for(auto x : b)
//        cout << x << ' ';
//    cout << endl;

    int ans = 0;
    for(int i = 0; i < k - 1; i++) {
        vector<int> c;
        for(int j = b[i] + 1; j < b[i + 1]; j++) {
            c.push_back(a[j]);
        }

        ans += solve(c, a[b[i]], a[b[i + 1]]);
    }

    cout << n - k - ans;
}