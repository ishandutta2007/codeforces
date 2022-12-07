#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[1000005];
vector<int> v;
bool was[1000005] = {};
int mn, mx;

bitset<1000001> b;

int cnt[101];
int got[101];

void solveMx() {
    int odd = 0;
    for (int x : v) {
        if (x % 2 == 1) {
            ++odd;
        }
    }
    int p = (n - odd) / 2;
    mx = 0;
    forn(i, k) {
        if (p) {
            --p;
            mx += 2;
        } else if (odd) {
            --odd;
            mx += 1;
        }
    }
}

vector<int> need;
bool nn[1000001] = {};

bool solveMn() {
    b.set(0);
    sort(v.begin(), v.end(), greater<int>());
    int sz = int(v.size());
    forn(i, min(sz, 10000)) {
        b |= b << v[i];
    }
    if (b.test(k) || b.test(n - k)) {
        return true;
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 10000; i < sz; ++i) {
        ++cnt[v[i]];
    }
    forn(i, max(k, n - k) + 1) {
        if (b.test(i)) {
            if (i <= k) {
                need.pb(k - i);
                nn[k - i] = true;
            }
            if (i <= n - k) {
                need.pb(n - k - i);
                nn[n - k - i] = true;
            }
        }
    }
    sort(need.begin(), need.end());
    mt19937 mt(time(NULL));
    while (clock() < 1.35 * CLOCKS_PER_SEC) {
        vector<int> rem;
        forn(i, 101) if (cnt[i]) {
            rem.pb(i);
        }
        memset(got, 0, sizeof got);
        int cur = 0;
        while (!rem.empty()) {
            int ind = mt() % int(rem.size());
            cur += rem[ind];
            if (nn[cur]) {
                return true;
            }
            if (++got[rem[ind]] == cnt[rem[ind]]) {
                for (int i = ind; i < int(rem.size()) - 1; ++i) {
                    rem[i] = rem[i + 1];
                }
                rem.pop_back();
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) {
        scanf("%d", a + i);
        --a[i];
    }
    forn(i, n) if (!was[i]) {
        int sz = 0;
        for (int j = i; !was[j]; j = a[j]) {
            was[j] = true;
            ++sz;
        }
        v.pb(sz);
    }

    solveMx();

    mn = k;
    if (!solveMn()) {
        ++mn;
    }

    cout << mn << ' ' << mx << endl;
    return 0;
}