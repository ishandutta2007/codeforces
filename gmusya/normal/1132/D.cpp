#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <queue>

using namespace std;

using ll = long long;

const ll INF = 2e12;

const int MAX_N = 2e5;

ll M;
ll a[MAX_N + 1], b[MAX_N + 1], x[MAX_N + 1];

ll Get(int i) {
    return -((a[i] + x[i] * M) / b[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll L = 0, R = INF;
    for (int i = 0; i < n; ++i) {
        L = max(L, (b[i] * 1ll * k - a[i]) / k - 10);
    }
    priority_queue<pair<ll, int>> brr;
    M = 0;
    for (int i = 0; i < n; i++) {
        brr.push(make_pair(Get(i), i));
    }
    while (L != R) {
        for (int i = 0; i < n; ++i) {
            x[i] = 0;
        }
        M = (L + R) / 2;
        priority_queue<pair<ll, int>> arr = brr;
        bool can = true;
        for (ll move = 0; move < k; ++move) {
            int ind = arr.top().second;
            arr.pop();
            if (a[ind] + x[ind] * M - b[ind] * move < 0) {
                can = false;
                break;
            }
            ++x[ind];
            arr.push(make_pair(Get(ind), ind));
        }
        if (!can) {
            L = M + 1;
        } else {
            R = M;
        }
    }
    if (L == INF) {
        L = -1;
    }
    cout << L;
    return 0;
}