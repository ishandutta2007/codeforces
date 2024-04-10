#include <bits/stdc++.h>
using namespace std;
int n, m;
vector < string > a;
int sum[1000010];
int main() {
    ios :: sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            if (a[i][j - 1] == 'X' && a[i - 1][j] == 'X') {
                sum[j]++;
            }
        }
    for (int i = 1; i < m; i++) sum[i] += sum[i - 1];
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (sum[r] - sum[l]) puts("NO");
        else puts("YES");
    }
}