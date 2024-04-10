#include <bits/stdc++.h>
using namespace std;

int n, m, id[1000010];
string s[1000010];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    iota(id + 1, id + n + 1, 1);
    stable_sort(id + 1, id + n + 1, [&](int x, int y) {
        for (int i = 0; i < m; i++) if (s[x][i] ^ s[y][i]) {
            if (i & 1) return s[x][i] > s[y][i];
            return s[x][i] < s[y][i];
        }
    });
    for (int i = 1; i <= n; i++) {
        cout << id[i] << " ";
    }
    return 0;
}