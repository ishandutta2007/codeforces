#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

bool q(int x, int y) {
    cout << "1 " << x << ' ' << y << endl;
    string s;
    cin >> s;
    return s[0] == 'T';
}

int solve(int lo, int hi) {
    if (lo == hi) {
        return lo;
    }
    int mid = (lo + hi) / 2;
    if (q(mid, mid + 1)) {
        return solve(lo, mid);
    }
    return solve(mid + 1, hi);
}

bool check(int x, int y) {
    return q(x, y) && q(y, x);
}

int main() {
    cin >> n >> k;
    int x = solve(1, n);
    int y;
    if (x == 1) {
        y = solve(2, n);
    } else if (x == n) {
        y = solve(1, n - 1);
    } else {
        y = solve(x + 1, n);
        if (!check(x, y)) {
            y = solve(1, x - 1);
        }
    }
    cout << "2 " << x << ' ' << y << endl;
    return 0;
}