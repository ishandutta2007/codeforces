#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, a[maxn];
long long s[maxn];
double ans[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    }
    auto slope = [&](int i, int j) {
        return 1.0 * (s[j] - s[i]) / (j - i);
    };
    vector<int> st = {0};
    for (int i = 1; i <= n; i++) {
        while (st.size() > 1 && slope(st[st.size() - 2], i) > slope(st.back(), i)) st.pop_back();
        st.push_back(i);
    }
    for (int i = 1; i < st.size(); i++) {
        fill(ans + st[i - 1] + 1, ans + st[i] + 1, slope(st[i - 1], st[i]));
    }
    for (int i = 1; i <= n; i++) {
        printf("%.9f\n", ans[i]);
    }
    return 0;
}