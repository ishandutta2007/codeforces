#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[200005];
int n;
int cnt[26] = {};
int bad = 0;

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) ++cnt[s[i] - 'a'];
    REP(i, 26) bad += cnt[i] & 1;
    int lo = 0, hi = 25;
    while (bad > 1) {
        while (!(cnt[lo] & 1)) ++lo;
        while (!(cnt[hi] & 1)) --hi;
        ++cnt[lo];
        --cnt[hi];
        bad -= 2;
    }
    if (bad) {
        bad = n / 2;
        int c = 0;
        while (!(cnt[c] & 1)) ++c;
        s[bad] = 'a' + c;
        REP(i, 26) cnt[i] >>= 1;
        int pos = 0;
        REP(i, bad) {
            while (!cnt[pos]) ++pos;
            --cnt[pos];
            s[i] = 'a' + pos;
        }
        for (int i = 1; i <= bad; ++i) {
            s[bad + i] = s[bad - i];
        }
    } else {
        REP(i, 26) cnt[i] >>= 1;
        int pos = 0;
        int half = n / 2;
        REP(i, half) {
            while (!cnt[pos]) ++pos;
            --cnt[pos];
            s[i] = 'a' + pos;
        }
        REP(i, half) {
            s[half + i] = s[half - 1 - i];
        }
    }
    printf("%s\n", s);
    return 0;
}