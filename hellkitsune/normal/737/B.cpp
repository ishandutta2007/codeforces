#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005;

int n, a, b, k;
char s[N];
vector<int> ans;

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &k);
    scanf("%s", s);
    int cur = 0;
    for (int beg = 0; beg < n; ) {
        if (s[beg] == '1') {
            ++beg;
            continue;
        }
        int end = beg + 1;
        while (end < n && s[end] == '0') {
            ++end;
        }
        int cnt = end - beg;
        beg = end;
        cur += cnt / b;
    }
    assert(cur >= a);
    int cnt = 0;
    forn(i, n) {
        if (s[i] == '1') {
            cnt = 0;
        } else if (++cnt == b) {
            cnt = 0;
            if (cur >= a) {
                ans.pb(i);
                --cur;
            }
        }
    }
    printf("%d\n", int(ans.size()));
    for (int x : ans) {
        printf("%d ", x + 1);
    }
    printf("\n");
    return 0;
}