#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n + 2);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i += 1) cin >> p[i];
    LL res = 0;
    auto G = [&](int i) {
        int a = 0, b = n + 1, j = i;
        while (j <= n) {
            if (p[j] < a and p[j] > b) break;
            else if (p[j] > b) a = max(p[j], a);
            else if (p[j] < a) b = min(p[j], b);
            else if (p[j + 1] > p[j]) a = max(p[j], a);
            else b = min(p[j], b);
            j += 1;
        }
        ans[i] = j;
    };
    function<void(int, int)> DFS = [&](int L, int R) {
        if (L + 1 >= R) return;
        if (ans[L] == ans[R]) {
            for (int i = L; i <= R; i += 1) ans[i] = ans[L];
            return;
        }
        int M = (L + R) / 2;
        G(M);
        DFS(L, M);
        DFS(M, R);
    };
    G(1);
    G(n);
    DFS(1, n);
    for (int i = 1; i <= n; i += 1)
        res += ans[i] - i;
    cout << res;
}