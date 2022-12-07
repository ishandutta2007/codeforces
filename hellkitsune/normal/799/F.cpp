#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef unsigned long long LL;
typedef pair<int, int> PII;

int n, m;
int l[200000], r[200000], p[200001];
vector<int> beg[200001], ed[200001];
map<LL, LL> cnt, sum;
LL h[200000], all;

mt19937_64 mt(time(0));

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    all = 0;
    forn(i, n) {
        scanf("%d%d", l + i, r + i);
        --l[i], --r[i];
        ++p[l[i]];
        --p[r[i] + 1];
        beg[l[i]].pb(i);
        ed[r[i] + 1].pb(i);
        h[i] = mt();
        all ^= h[i];
    }
    LL mask = 0, bmask = all, emask = 0, change = 0, ans = 0;
    forn(i, m + 1) {
        for (int x : ed[i]) {
            emask ^= h[x];
        }
        mask ^= change;
        ans += cnt[mask ^ all ^ bmask] * i - sum[mask ^ all ^ bmask];
        ++cnt[mask ^ emask];
        sum[mask ^ emask] += i;

        for (int x : beg[i]) {
            change ^= h[x];
            bmask ^= h[x];
        }
        for (int x : ed[i]) {
            change ^= h[x];
        }
    }
    int t = 0, c = 0;
    forn(i, m) {
        t += p[i];
        if (t > 0) {
            c = 0;
        } else {
            ++c;
            ans -= (LL)c * (c + 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}