#include<bits/stdc++.h>
using namespace std;
using LL = long long;
struct P{
    int a, b;
    P(): a(0), b(0){}
    void add(int x) {
        if (a == -1) return;
        if (x > b) b = x;
        else if (x > a) a = x;
        else a = b = -1;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& ai : a) cin >> ai;
    auto f = [&](vector<int> a) -> int {
        int mx = max_element(a.begin(), a.end()) - a.begin();
        if (mx == 0) return 0;
        vector<P> pre(n), suf(n);
        for (int i = 0; i < n; i += 1) {
            if (i) pre[i] = pre[i - 1];
            pre[i].add(a[i]);
        }
        for (int i = n - 1; i >= 0; i -= 1) {
            if (i + 1 < n) suf[i] = suf[i + 1];
            suf[i].add(a[i]);
        }
        if (suf[mx].a == -1) return 0;
        int ans = 0, L = suf[mx].a, R = a[mx];
        if (pre[mx - 1].a != -1 and a[mx - 1] > suf[mx].a)
            ans += 1;
        for (int i = mx - 1; i >= 1; i -= 1) {
            if (pre[i - 1].a != -1) {
                int x = pre[i - 1].a == a[i - 1] ? pre[i - 1].b: pre[i - 1].a;
                if (a[i - 1] > L and x < R
                    and ((a[i - 1] > a[i] and a[i] > L) or (x < a[i] and a[i] < R))) {
                    ans += 1;
                }
            }
            if (a[i] < L and a[i] > R) break;
            if (a[i] < L) R = a[i];
            else if (a[i] > R) L = a[i];
            else if (a[i - 1] > a[i]) L = a[i];
            else R = a[i];
        }
        return ans;
    };
    int ans = f(a);
    ranges::reverse(a);
    cout << ans + f(a) << "\n";
    return 0;
}