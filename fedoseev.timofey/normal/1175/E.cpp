#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 7;
const int K = 20;

int go[K][N];
vector <int> bg[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        bg[l].push_back(r);
    }
    multiset <int> cur;
    for (int i = 0; i < N; ++i) {
        for (auto r : bg[i]) cur.insert(r);
        if (cur.empty()) {
            go[0][i] = -1;
        }
        else {
            go[0][i] = *cur.rbegin();
        }
        cur.erase(i);
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int k = 1; k < K; ++k) {
            if (go[k - 1][i] == -1) go[k][i] = -1;
            else {
                go[k][i] = go[k - 1][go[k - 1][i]];
            }
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (go[K - 1][l] < r) {
            cout << "-1\n";
        }
        else {
            int ans = 0;
            for (int i = K - 1; i >= 0; --i) {
                if (go[i][l] < r) {
                    ans += (1 << i);
                    l = go[i][l];
                }
            }
            ++ans;
            cout << ans << '\n';
        }
    }
}