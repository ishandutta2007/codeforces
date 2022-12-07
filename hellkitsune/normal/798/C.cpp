#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    int g = 0;
    forn(i, n) g = gcd(g, abs(a[i]));
    if (g != 1) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    forn(i, n) a[i] %= 2;
    for (int beg = 0; beg < n; ) {
        if (a[beg] == 0) {
            ++beg;
            continue;
        }
        int end = beg + 1;
        while (end < n && a[end] == 1) ++end;
        ans += (end - beg) / 2;
        if ((end - beg) % 2 == 1) ans += 2;
        beg = end;
    }
    cout << "YES" << endl;
    cout << ans << endl;
    return 0;
}