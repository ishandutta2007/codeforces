#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    int t;
    for (cin >> t; t; t -= 1) {
        int n, s;
        cin >> n >> s;
        vector<LL> a(n + 1), sum(n + 1);
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        vector<int> st;
        int ans = 0, f = 0, t = 0;
        for (int i = n; i >= 1; i -= 1) {
            while (not st.empty() and sum[i] <= sum[st.back()])
                st.pop_back();
            st.push_back(i);
            if (a[i] + s < 0) continue;
            int L = -1, R = (int)st.size() - 1;
            while (L < R) {
                int M = (L + R + 1) >> 1;
                if (sum[st[M]] + s >= sum[i - 1]) R = M - 1;
                else L = M;
            }
            int x = L == -1 ? n : st[L] - 1;
            if (x - i + 1 > ans) {
                ans = x - i + 1;
                f = i;
                t = x;
            }
        }
        if (ans) cout << f << " " << t << "\n";
        else cout << "-1\n";
    }
    return 0;
}