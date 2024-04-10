#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, a[maxn];
char str[maxn];
vector<int> st, d[maxn], V[maxn];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%s", str + 1);
    for (int i = 2; i < maxn; i++) if (d[i].empty()) {
        for (int j = i; j < maxn; j += i) {
            int x = j;
            while (!(x % i)) x /= i, d[j].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        st.push_back(i);
        for (int j : d[a[i]]) {
            if (str[i] == '*') {
                V[j].push_back(i);
            } else {
                while (!st.empty() && (V[j].empty() || st.back() > V[j].back())) st.pop_back();
                if (!V[j].empty()) V[j].pop_back();
            }
        }
        ans += st.size();
    }
    printf("%lld\n", ans);
    return 0;
}