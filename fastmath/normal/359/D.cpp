#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;
const int INF = 1e9 + 7;
const int LG = 20;

int a[MAXN];

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int pw[MAXN];
int dp[LG][MAXN];

bool check(int l, int r, int x) {
    int p = pw[r - l + 1];
    return dp[p][l] % x == 0 && dp[p][r - (1 << p) + 1] % x == 0;    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int curr = 0;
    for (int i = 0; i < MAXN; ++i) {
        curr += (1 << (curr + 1)) < i;
        pw[i] = curr;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) dp[0][i] = a[i];
    for (int p = 1; p < LG; ++p) {
        for (int i = 0; i < n; ++i) dp[p][i] = gcd(dp[p - 1][i], dp[p - 1][i + (1 << (p - 1))]);
    }

    int best = -INF;
    set <int> ms;

    for (int i = 0; i < n; ++i) {
        int l = -1;
        int r = i;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (check(m, i, a[i])) {
                r = m;
            }   
            else {
                l = m;
            }
        }
        int newl = r;

        l = i;
        r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (check(i, m, a[i])) {
                l = m;
            }
            else {
                r = m;
            }
        }
        int newr = l;

        if (best < newr - newl) {
            ms.clear();
            ms.insert(newl + 1);
            best = newr - newl;
        }
        else if (best == newr - newl) {
            ms.insert(newl + 1);
        }
    }

    cout << ms.size() << ' ' << best << '\n';
    for (int elem : ms) cout << elem << ' ';
    cout << '\n'; 

    return 0;
}