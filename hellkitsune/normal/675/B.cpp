#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b, c, d;

int main() {
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    int x = -c + b;
    int y = x - d + a;
    int z = y - b + c;
    int mn = min(min(min(0, x), y), z);
    int mx = max(max(max(0, x), y), z);
    LL ans = (LL)n * max(0, n - mx + mn);
    cout << ans << endl;
    return 0;
}