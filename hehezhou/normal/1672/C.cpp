#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
void rmain() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) a[i] = a[i] == a[i + 1];
    n--;
    int tag = 0;
    for (int i = 1; i <= n; i++) tag += a[i];
    if (tag <= 1) return cout << "0\n", void();
    int l = 1, r = n;
    while (a[l] == 0) l++;
    while (a[r] == 0) r--;
    cout << max(1, r - l - 1) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) rmain();
}