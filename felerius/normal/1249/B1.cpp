#include <bits/stdc++.h>

// Contest: Codeforces Round #595 (Div. 3) (https://codeforces.com/contest/1249)
// Problem: B2: Books Exchange (hard version) (https://codeforces.com/contest/1249/problem/B2)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<int> p(n);
        for (auto& pi : p) cin >> pi, --pi;
        vector<int> r(n, -1);
        for (int i = 0; i < n; ++i) {
            if (r[i] != -1)
                continue;
            vector<int> stack; stack.push_back(i);
            while (p[stack.back()] != i)
                stack.push_back(p[stack.back()]);
            for (auto j : stack)
                r[j] = stack.size();
        }

        for (auto i : r)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}