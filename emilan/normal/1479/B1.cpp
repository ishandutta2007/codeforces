#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    a.push_back(-1);
    int p = 1, s = 0, t = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (; p < n && (a[p - 1] != a[p] || p < i); p++);

        if (s == a[i] && t == a[i]) continue;

        ans++;
        if (s == a[i]) t = a[i];
        else if (t == a[i]) s = a[i];
        else {
            if (s == a[p]) s = a[i];
            else t = a[i];
        }
    }

    cout << ans;
}