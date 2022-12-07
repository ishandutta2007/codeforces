#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];
int pos[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), --a[i];
    REP(i, n) pos[a[i]] = i;
    int ans = 0;
    for (int beg = 0; beg < n; ) {
        int end = beg + 1;
        while (end < n && (pos[end] > pos[end - 1])) {
            ++end;
        }
        ans = max(ans, end - beg);
        beg = end;
    }
    ans = n - ans;
    printf("%d\n", ans);
    return 0;
}