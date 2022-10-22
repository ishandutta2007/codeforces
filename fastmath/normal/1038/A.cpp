#include <bits/stdc++.h>

using namespace std;

const int K = 26;
const int INF = 1e9 + 7;

int cnt[K];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (char c : s) {
        ++cnt[c - 'A'];
    }

    int mn = INF;
    for (int i = 0; i < k; ++i) {
        mn = min(mn, cnt[i]);
    }

    cout << mn * k << '\n';
    return 0;
}