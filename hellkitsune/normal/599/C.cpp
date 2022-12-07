#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

map<int, int> cnt;
int bad = 0;
int n;
int a[100000], b[100000];

int main() {
    scanf("%d", &n);
    int ans = 0;
    REP(i, n) scanf("%d", a + i);
    REP(i, n) b[i] = a[i];
    sort(b, b + n);
    REP(i, n) {
        int val = ++cnt[a[i]];
        if (val == 0) --bad;
        else if (val == 1) ++bad;
        val = --cnt[b[i]];
        if (val == 0) --bad;
        else if (val == -1) ++bad;
        if (bad == 0) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}