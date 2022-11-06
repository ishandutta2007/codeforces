#include<bits/stdc++.h>
using namespace std;
using LL = long long;

bool solve() {
    int n, m, mx = 0;
    cin >> n >> m;
    int sum = m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i += 2) {
        if (m < 0) {
            return false;
        }
        if (m % (n - i + 1) == 0 && m / (n - i + 1) > mx) {
            int val = m / (n - i + 1);
            for (int j = i; j <= n; j++) {
                arr[j] = val;
            }
            break;
        }
        if (i + 1 <= n) {
            arr[i] = arr[i + 1] = mx = 1;
            m -= 2;
        }
    }
    if (m < 0) {
        return false;
    }
    for (int i = 1; i <= n; i++) {
        sum -= arr[i];
        if (arr[i] <= 0) {
            return false;
        }
    }
    if (sum != 0) {
        return false;
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        if (!solve()) {
            puts("No");
        }
    }
    return 0;
}