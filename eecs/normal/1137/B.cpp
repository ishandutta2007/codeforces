#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int maxn = 500010, P = 1000000007;
int n, m, a[2], c[maxn][2];
char s[maxn], t[maxn];
vector<int> ans;
ll pw[maxn], h[maxn];

ll get(int l, int r) {
    return (h[r] - h[l - 1] * pw[r - l + 1] % P + P) % P;
}

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(t + 1), m = strlen(s + 1);
    for (int i = 1; i <= m; i++) {
        a[s[i] - '0']++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = c[i - 1][j] + (t[i] == j + '0');
        }
    }
    if (a[0] >= c[n][0] && a[1] >= c[n][1]) {
        a[0] -= c[n][0], a[1] -= c[n][1];
        for (int i = 1; i <= n; i++) {
            ans.push_back(t[i] - '0');
        }
        int fir = 0;
        for (int i = pw[0] = 1; i <= n; i++) {
            pw[i] = pw[i - 1] * 19260817 % P;
            h[i] = (h[i - 1] * 19260817 + t[i]) % P;
        }
        for (int i = n; i > 1; i--) {
            if (get(i, n) == get(1, n - i + 1)) fir = i;
        }
        if (!fir) {
            while (a[0] >= c[n][0] && a[1] >= c[n][1]) {
                a[0] -= c[n][0], a[1] -= c[n][1];
                for (int i = 1; i <= n; i++) {
                    ans.push_back(t[i] - '0');
                }
            }
        } else {
            int c0 = c[n][0] - c[n - fir + 1][0];
            int c1 = c[n][1] - c[n - fir + 1][1];
            while (a[0] >= c0 && a[1] >= c1) {
                a[0] -= c0, a[1] -= c1;
                for (int i = n - fir + 2; i <= n; i++) {
                    ans.push_back(t[i] - '0');
                }
            }
        }
    }
    while (a[0]--) {
        ans.push_back(0);
    }
    while (a[1]--) {
        ans.push_back(1);
    }
    for (int x : ans) {
        printf("%d", x);
    }
    return 0;
}