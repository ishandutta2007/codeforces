#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, cnt[26], inc[maxn];
char s[maxn];
pair<char, int> t[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1), m = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i < n; i++) if (s[i] == s[i + 1]) {
            t[++m] = make_pair(s[i], i), cnt[s[i] - 'a']++;
        }
        printf("%d\n", max(*max_element(cnt, cnt + 26), (m + 1) / 2) + 1);
        stack<int> st;
        for (int i = 1, _ = m; i <= _; i++) {
            inc[i] = inc[i - 1];
            int mx = max_element(cnt, cnt + 26) - cnt;
            bool chk1 = !st.empty() && t[st.top()].first != t[i].first;
            bool chk2 = !st.empty() && (t[st.top()].first == mx + 'a') != (t[i].first == mx + 'a');
            if (cnt[mx] < (m + 1) / 2 && chk1 || chk2) {
                int j = st.top(); st.pop();
                int l = t[j].second - inc[j] + 1, r = t[i].second - inc[i];
                printf("%d %d\n", l, r), n -= r - l + 1;
                m -= 2, inc[i] += r - l + 1;
                cnt[t[j].first - 'a']--, cnt[t[i].first - 'a']--;
            } else {
                st.push(i);
            }
        }
        while (!st.empty()) {
            int i = st.top(); st.pop();
            int l = t[i].second - inc[i] + 1;
            printf("%d %d\n", l, n), n = l - 1;
        }
        printf("%d %d\n", 1, n);
    }
    return 0;
}