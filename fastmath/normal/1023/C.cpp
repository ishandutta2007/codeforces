#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

bool del[MAXN];
int p[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    stack <int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        }
        else {
            p[st.top()] = i;
            st.pop();
        }
    }

    int ost = (n - k) / 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' && ost) {
            del[i] = del[p[i]] = 1;
            --ost;
        }
    }

    string ans;
    for (int i = 0; i < n; ++i) {
        if (!del[i]) ans += s[i];
    }

    cout << ans << '\n';
    return 0;
}