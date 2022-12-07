#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[2000];

int gcd(int a, int b) {
    while (a) b %= a, swap(a, b);
    return b;
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    int cnt = 0;
    forn(i, n) if (a[i] == 1) {
        ++cnt;
    }
    if (cnt > 0) {
        cout << n - cnt << endl;
        return 0;
    }
    cnt = n + 1;
    forn(i, n) {
        int g = 0;
        for (int j = i; j < n; ++j) {
            g = gcd(g, a[j]);
            if (g == 1) {
                cnt = min(cnt, j - i + 1);
                break;
            }
        }
        if (cnt > n) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n + cnt - 2 << endl;
    return 0;
}