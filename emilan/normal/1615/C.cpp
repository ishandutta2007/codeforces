#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int same[2] = {};
    int diff[2] = {};
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) same[a[i] - '0']++;
        else diff[a[i] - '0']++;
    }

    int ans = n + 1;
    if ((same[0] + same[1]) & 1 &&
            (same[1] == same[0] || same[1] == same[0] + 1)) {
        ans = min(same[0] + same[1], ans);
    }
    if (~(diff[0] + diff[1]) & 1 &&
            (diff[1] == diff[0] || diff[1] == diff[0] + 1)) {
        ans = min(diff[0] + diff[1], ans);
    }

    if (ans == n + 1) return -1;
    else return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}