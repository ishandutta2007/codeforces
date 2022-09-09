#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 1'000'000'007;
void add(int& x, int y) {
    if ((x += y) >= mod) x -= mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector c(n, vector<int>(n));
    vector<int> g = {0};
    for (int i = 0; i < 5; i += 1) {
        for (int j = 0; j < (1 << i); j += 1)
            g.push_back((1 << i) | g[(1 << i) - j - 1]);
    }
    vector<pair<int, int>> p(1024, {-1, -1});
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < n; j += 1) {
            for (int k = 0; k < 5; k += 1) {
                c[i][j] |= ((g[i] >> k) & 1) << (2 * k);
                c[i][j] |= ((g[j] >> k) & 1) << (2 * k + 1);
            }
            //assert(p[c[i][j]].first == -1);
            p[c[i][j]] = {i, j};
        }
    int ans = 0;
    for (int i = 0; i < n; i += 1) {
        for (int j = 1; j < n; j += 1) {
            ans += c[i][j] ^ c[i][j - 1];
            cout << (c[i][j] ^ c[i][j - 1]) << " ";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            ans += c[i][j] ^ c[i - 1][j];
            cout << (c[i][j] ^ c[i - 1][j]) << " ";
        }
        cout << endl;
    }
    //assert(ans <= 48000);
    int cx = 0, cy = 0;
    for (int i = 0; i < k; i += 1) {
        int x;
        cin >> x;
        tie(cx, cy) = p[c[cx][cy] ^ x];
        cout << cx + 1 << " " << cy + 1 << endl;
    }
}