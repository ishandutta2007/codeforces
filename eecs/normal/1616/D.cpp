#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int T, n, X, f[maxn], lst[maxn];
long long a[maxn];
bool mark[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        scanf("%d", &X);
        for (int i = 1; i <= n; i++) {
            a[i] = a[i - 1] + a[i] - X;
        }
        for (int i = 1; i <= n; i++) {
            mark[i] = a[i - 1] <= a[i + 1] && a[i - 1] <= a[i + 2];
            lst[i] = mark[i] ? lst[i - 1] : i;
        }
        vector<pair<int, int>> st = {{0, 0}};
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            int j = i;
            if (j && (i == j || a[j - 1] <= a[j + 1] && (i - 1 == j || a[j - 1] <= a[j + 2]))) j--;
            if (j && (i == j || a[j - 1] <= a[j + 1] && (i - 1 == j || a[j - 1] <= a[j + 2]))) j--;
            if (j && (i == j || a[j - 1] <= a[j + 1] && (i - 1 == j || a[j - 1] <= a[j + 2]))) j--;
            j = lst[j];
            auto it = lower_bound(st.begin(), st.end(), make_pair(j, INT_MIN));
            if (it != st.end()) f[i] = max(f[i], it->second + i);
            int v = f[i - 1] - i;
            while (!st.empty() && v >= st.back().second) st.pop_back();
            st.emplace_back(i, v);
        }
        printf("%d\n", f[n]);
    }
    return 0;
}