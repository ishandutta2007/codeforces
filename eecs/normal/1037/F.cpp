#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 1000000007;
int n, K, ans, a[maxn], L[maxn], R[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> st = {0};
    for (int i = 1; i <= n; i++) {
        while (st.size() > 1 && a[st.back()] < a[i]) st.pop_back();
        L[i] = st.back() + 1, st.push_back(i);
    }
    st = {n + 1};
    for (int i = n; i; i--) {
        while (st.size() > 1 && a[st.back()] <= a[i]) st.pop_back();
        R[i] = st.back() - 1, st.push_back(i);
    }
    auto calc = [&](int x, int y) {
        x++, y++;
        int ux = x / (K - 1), uy = y / (K - 1);
        int rx = x % (K - 1), ry = y % (K - 1);
        if (rx > ry) swap(ux, uy), swap(rx, ry);
        return 1LL * (ux + 1) * (uy + 1) * rx + 1LL * ux * (uy + 1) * (ry - rx) + 1LL * ux * uy * (K - 1 - ry);
    };
    for (int i = 1; i <= n; i++) {
        ans = (ans - a[i] + P) % P;
        long long ways = calc(i, R[i]) - calc(L[i] - 1, R[i]) - calc(i, i - 1) + calc(L[i] - 1, i - 1);
        ans = (ans + ways % P * a[i]) % P;
    }
    printf("%d\n", ans);
    return 0;
}