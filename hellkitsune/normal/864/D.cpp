#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200000];
int cnt[200000];
vector<int> have;
bool skipped[200000] = {};

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i), --a[i];
    forn(i, n) ++cnt[a[i]];
    for (int i = n - 1; i >= 0; --i) if (cnt[i] == 0) {
        have.pb(i);
    }
    int ans = (int)have.size();
    forn(i, n) if (cnt[a[i]] > 1) {
        if (have.back() < a[i] || skipped[a[i]]) {
            --cnt[a[i]];
            a[i] = have.back();
            have.pop_back();
        } else {
            skipped[a[i]] = true;
        }
    }
    assert(have.empty());
    printf("%d\n", ans);
    forn(i, n) printf("%d ", a[i] + 1);
    puts("");
    return 0;
}