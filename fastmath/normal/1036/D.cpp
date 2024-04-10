#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;

int n, m;
int a[MAXN], b[MAXN];
int p1[MAXN], p2[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];
}

int check(int l1, int r1, int l2) {
    int sum = p1[r1 + 1] - p1[l1];

    int l = l2 - 1;
    int r = m;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (p2[mid + 1] - p2[l2] < sum) l = mid;
        else r = mid;
    }

    if (p2[r + 1] - p2[l2] == sum) return r;
    else return -1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();

    int sum1 = 0;
    for (int i = 0; i < n; ++i) sum1 += a[i];
    int sum2 = 0;
    for (int i = 0; i < m; ++i) sum2 += b[i];

    if (sum1 != sum2) {
        cout << "-1\n";
        exit(0);
    }

    for (int i = 0; i < n; ++i) p1[i + 1] = p1[i] + a[i];
    for (int i = 0; i < m; ++i) p2[i + 1] = p2[i] + b[i];

    int ans = 0;
    int l1 = 0, l2 = 0;
    while (l1 < n) {
        for (int r1 = l1; ; ++r1) {
            int t = check(l1, r1, l2);
            if (t != -1) {
                ++ans;
                l1 = r1 + 1;
                l2 = t + 1;
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}