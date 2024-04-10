#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 7;

int n, a, b, t;
string s;

int pref[MAXN], post[MAXN];

int get(int i, int j) {
    return (n - j + i) * a + (pref[i] + post[j]) * b + (n - j + i + 1) + min(n - j, i) * a;
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> t;
    cin >> s;
    
    for (int i = n - 1; i >= 0; --i) post[i] = post[i + 1] + (s[i] == 'w');

    pref[0] = (s[0] == 'w');
    for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + (s[i] == 'w');

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (t < pref[i] * b + a * i + (i + 1)) break;

        int l = i;
        int r = n;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (get(i, m) <= t) r = m;
            else l = m;
        }

        ans = max(ans, (n - r) + i + 1);
    }   
    cout << ans << '\n';

    return 0;
}