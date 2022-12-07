#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[300005], t[300005];
char ans[300005];

int main() {
    scanf("%s%s", s, t);
    n = strlen(s);
    sort(s, s + n);
    sort(t, t + n, greater<char>());
    int tsz = n / 2;
    int ssz = n - tsz;
    int spos = 0;
    int tpos = 0;
    int b = 0, e = n - 1;
    bool flag = false;
    forn(i, n) {
        if (flag || s[spos] >= t[tpos]) {
            if (!flag) {
                flag = true;
                reverse(s + spos, s + ssz);
                reverse(t + tpos, t + tsz);
            }
            if (i & 1) {
                ans[e] = t[tpos];
                ++tpos;
                --e;
            } else {
                ans[e] = s[spos];
                ++spos;
                --e;
            }
        } else {
            if (i & 1) {
                ans[b] = t[tpos];
                ++tpos;
                ++b;
            } else {
                ans[b] = s[spos];
                ++spos;
                ++b;
            }
        }
    }
    ans[n] = '\0';
    printf("%s\n", ans);
    return 0;
}