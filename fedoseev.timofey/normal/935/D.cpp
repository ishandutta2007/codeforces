#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

typedef long long ll;

using namespace std;

const int md = 1e9 + 7;

int mpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll t = mpow(a, n / 2);
        return t * t % md;
    }
    return (ll)mpow(a, n - 1) * a % md;
}

int inv(int a) {
    return mpow(a, md - 2);
}

const int N = 1e5 + 7;

int dp[N][3];

void add(int &a, int b) {
    a += b;
    a %= md;
}

int mul(int a, int b) {
    return (ll)a * b % md;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(n);
    int prob = (ll)m * inv((ll)m * m % md) % md;
    int p = ((ll)((1 - prob + md) % md) * inv(2)) % md;
    int im = inv(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[0][2] = 0;
    for (int i = 0; i < n; ++i) {
        add(dp[i + 1][0], dp[i][0]);
        add(dp[i + 1][2], dp[i][2]);
        if (a[i] != 0 && b[i] != 0) {
            if (a[i] > b[i]) {
                add(dp[i + 1][0], dp[i][1]);
                dp[i + 1][1] = 0;
            }
            else if (a[i] < b[i]) {
                add(dp[i + 1][2], dp[i][1]);
                dp[i + 1][1] = 0;
            }
            else {
                dp[i + 1][1] = dp[i][1];
            }
        }
        else if (a[i] == 0 && b[i] == 0){
            add(dp[i + 1][0], mul(dp[i][1], p));
            add(dp[i + 1][2], mul(dp[i][1], p));
            add(dp[i + 1][1], mul(dp[i][1], prob));
        }
        else {
            if (a[i] != 0) {
                add(dp[i + 1][0], mul(dp[i][1], mul(a[i] - 1, im)));
                add(dp[i + 1][2], mul(dp[i][1], mul(m - a[i], im)));
                add(dp[i + 1][1], mul(dp[i][1], im));
            }
            else {
                add(dp[i + 1][2], mul(dp[i][1], mul(b[i] - 1, im)));
                add(dp[i + 1][0], mul(dp[i][1], mul(m - b[i], im)));
                add(dp[i + 1][1], mul(dp[i][1], im));
            }
        }
    }
    cout << dp[n][0] << endl;
}