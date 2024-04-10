#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

ll dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, c;
    cin >> n >> c;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0] = 0;
    multiset <int> cur;
    ll cur_sum = 0;
    for (int i = 1; i < N; ++i) dp[i] = 1e18;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + a[i - 1];
        cur.insert(a[i - 1]);
        cur_sum += a[i - 1];
        if (i == c) {
            dp[i] = min(dp[i], dp[i - c] + cur_sum - *cur.begin());
        }
        else if (i > c) {
            cur_sum -= a[i - c - 1];
            cur.erase(cur.find(a[i - c - 1]));
            dp[i] = min(dp[i], dp[i - c] + cur_sum - *cur.begin());
        }
    }
    cout << dp[n] << endl;
}