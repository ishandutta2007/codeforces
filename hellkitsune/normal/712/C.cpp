#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int x, y;
int a[3];

int main() {
    cin >> x >> y;
    forn(i, 3) a[i] = y;
    int ans = 0;
    while (a[0] < x) {
        a[0] = min(x, a[1] + a[2] - 1);
        sort(a, a + 3);
        ++ans;
    }
    cout << ans << endl;
    return 0;
}