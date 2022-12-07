#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
char s[100005];
int ans = 0;

void solve(char c) {
    int l = 0, cnt = 0;
    REP(r, n) {
        if (s[r] != c) ++cnt;
        while (cnt > k) {
            if (s[l] != c) --cnt;
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    solve('a');
    solve('b');
    printf("%d\n", ans);
    return 0;
}