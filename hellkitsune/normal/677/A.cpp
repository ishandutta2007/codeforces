#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, h;

int main() {
    scanf("%d%d", &n, &h);
    int ans = n;
    REP(i, n) {
        int x;
        scanf("%d", &x);
        if (x > h) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}