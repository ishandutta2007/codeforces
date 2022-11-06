#include <bits/stdc++.h>

// Contest: Codeforces Round #586 (Div. 1 + Div. 2) (https://codeforces.com/contest/1220)
// Problem: C: Substring Game in the Lesson (https://codeforces.com/contest/1220/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    cout << "Mike\n";
    char mn = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] > mn)
            cout << "Ann\n";
        else
            cout << "Mike\n";
        mn = min(mn, s[i]);
    }

    return 0;
}