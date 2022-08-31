#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
inline int check(int x) {
    int l = 1, r = n;
    while (l <= r) {
        while (l <= r && a[l] == x) l++;
        while (l <= r && a[r] == x) r--;
        if (l > r) return 1;
        if (a[l] != a[r]) return 0;
        l++, r--;
    }
    return 1;
}
inline int rmain() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    while (l <= r) {
        if (a[l] == a[r]) l++, r--;
        else if (check(a[l]) || check(a[r])) return 1;
        else return 0;
    }
    return 1;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) puts(rmain() ? "YES" : "NO");
}