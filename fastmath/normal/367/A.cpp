#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int p[N][3];
int have[3];
vector <vector<int>> v = {{2, 1, 0}, {0, 2, 1}, {1, 0, 2}};
bool check(int l, int r) {
    for (int i = 0; i < 3; ++i) {
        have[i] = p[r + 1][i] - p[l][i];
    }   
    int len = r - l + 1;
    if (len < 3) return 1;
    for (auto p : v) {
        bool c = 1;
        for (int i = 0; i < 3; ++i) {
            c &= have[p[i]] == ((len - i) + 2) / 3;
        }   
        if (c) return 1;
    }   
    return 0;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) p[i + 1][j] = p[i][j];
        ++p[i + 1][s[i] - 'x'];
    }   
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if (check(l, r)) cout << "YES\n";
        else cout << "NO\n";
    }   
}