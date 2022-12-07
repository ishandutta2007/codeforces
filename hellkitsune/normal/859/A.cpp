#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int ans = 0;

int main() {
    int k;
    scanf("%d", &k);
    forn(i, k) {
        int x;
        scanf("%d", &x);
        ans = max(ans, x);
    }
    ans = max(0, ans - 25);
    cout << ans << endl;
    return 0;
}