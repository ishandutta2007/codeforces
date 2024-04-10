#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int c[100001];
bool cap[100001] = {};

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", c + i);
    c[n] = c[0];
    forn(i, k) {
        int x;
        scanf("%d", &x), --x;
        cap[x] = true;
    }
    LL sum = 0, sumCap = 0;
    forn(i, n) if (cap[i]) sumCap += c[i];
    else sum += c[i];
    LL ans = sum * sumCap;
    LL tmp = 0;
    forn(i, n) if (cap[i]) tmp += c[i] * (sumCap - c[i]);
    ans += tmp / 2;
    cap[n] = cap[0];
    forn(i, n) if (!cap[i] && !cap[i + 1]) {
        ans += c[i] * c[i + 1];
    }
    cout << ans << endl;
    return 0;
}