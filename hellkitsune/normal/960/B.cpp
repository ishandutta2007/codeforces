#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, kk;
int a[1000], b[1000];
multiset<int> q;

int main() {
    scanf("%d%d%d", &n, &k, &kk);
    k += kk;
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", b + i);
    forn(i, n) if (a[i] != b[i]) {
        q.insert(-abs(a[i] - b[i]));
    }
    forn(i, k) {
        if (q.empty()) {
            q.insert(-1);
        } else {
            int val = *q.begin();
            q.erase(q.begin());
            if (++val != 0) {
                q.insert(val);
            }
        }
    }
    LL ans = 0;
    for (int x : q) {
        ans += (LL)x * x;
    }
    cout << ans << endl;
    return 0;
}