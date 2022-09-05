#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, cnt0, c1[maxn], c2[maxn];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> s;
        vector<char> st;
        int cnt = 0;
        for (char c : s) {
            if (c == '(') {
                st.push_back(c);
            } else {
                if (st.empty()) cnt++;
                else st.pop_back();
            }
        }
        if (!cnt && st.empty()) {
            cnt0++;
        } else if (!cnt) {
            c1[st.size()]++;
        } else if (st.empty()) {
            c2[cnt]++;
        }
    }
    int ans = cnt0 / 2;
    for (int i = 1; i <= 500000; i++) {
        ans += min(c1[i], c2[i]);
    }
    printf("%d\n", ans);
    return 0;
}