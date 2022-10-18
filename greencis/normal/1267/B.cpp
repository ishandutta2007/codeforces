#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    deque<char> q(s.begin(), s.end());
    int ans = 0;
    while (true) {
        if (q[0] != q.back()) break;
        char cur = q[0];
        int L = 0; while (L < (int)q.size() && q[L] == cur) ++L;
        int R = 0; while (R < (int)q.size() && q[q.size() - R - 1] == cur) ++R;
        if (L == (int)q.size()) {
            ans = L + 1;
            if (L <= 1)
                ans = 0;
            break;
        }
        if (L + R <= 2)
            break;
        while (L--) q.pop_front();
        while (R--) q.pop_back();
    }
    cout << ans << endl;
}