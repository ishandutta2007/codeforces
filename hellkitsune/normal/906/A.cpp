#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char q[100005], buf[100005];
int mask[100005];
int cnt[26], need = 0;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf(" %c%s", q + i, buf);
        int len = strlen(buf);
        mask[i] = 0;
        forn(j, len) mask[i] |= 1 << (buf[j] - 'a');
    }
    bool done = false;
    int ans = 0;
    forn(i, n - 1) {
        if (done) {
            if (q[i] != '.') {
                ++ans;
            }
            continue;
        }
        if (q[i] == '!') {
            ++need;
            forn(j, 26) if (mask[i] & (1 << j)) {
                ++cnt[j];
            }
        } else {
            forn(j, 26) if (mask[i] & (1 << j)) {
                --cnt[j];
            }
        }
        int gcnt = 0;
        forn(j, 26) if (cnt[j] == need) {
            ++gcnt;
        }
        if (gcnt == 1) {
            done = true;
        }
    }
    cout << ans << endl;
    return 0;
}