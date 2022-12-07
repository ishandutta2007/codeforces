#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
bool b[1000001] = {};
int le[1000001];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        b[x] = true;
    }
    le[0] = b[0] ? 0 : -1;
    for (int i = 1; i <= 1000000; ++i) {
        if (b[i]) le[i] = i;
        else le[i] = le[i - 1];
    }
    int ans = 0;
    REP(i, 1000001) if (b[i]) {
        for (int j = i; j < 1000000; j += i) {
            int x = le[min(1000000, j + i - 1)];
            if (x > -1) ans = max(ans, x % i);
        }
    }
    printf("%d\n", ans);
    return 0;
}