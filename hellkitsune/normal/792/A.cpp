#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200000];

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    int mn = int(2e9) + 123;
    int cnt = 0;
    forn(i, n - 1) {
        int cur = abs(a[i] - a[i + 1]);
        if (cur < mn) {
            mn = cur;
            cnt = 1;
        } else if (cur == mn) {
            ++cnt;
        }
    }
    cout << mn << ' ' << cnt << endl;
    return 0;
}