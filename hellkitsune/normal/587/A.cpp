#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int w[1000222] = {};

int main() {
    scanf("%d", &n);
    int ans = 0;
    REP(i, n) {
        int x;
        scanf("%d", &x);
        ++w[x];
    }
    REP(i, 1000111) {
        w[i + 1] += w[i] >> 1;
        ans += w[i] & 1;
    }
    printf("%d\n", ans);
    return 0;
}