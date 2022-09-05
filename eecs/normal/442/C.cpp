#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, a[maxn];
stack<int> st;
vector<int> V;
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        while (st.size() > 1) {
            int x = st.top(); st.pop();
            if (st.top() >= x && x <= a[i]) ans += min(a[i], st.top());
            else { st.push(x); break; }
        }
        st.push(a[i]);
    }
    while (!st.empty()) V.push_back(st.top()), st.pop();
    sort(V.begin(), V.end());
    for (int i = 0; i < (int)V.size() - 2; i++) ans += V[i];
    printf("%lld\n", ans);
    return 0;
}