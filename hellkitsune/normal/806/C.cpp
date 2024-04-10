#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
int cnt[50], bcnt[50], mn[50];
vector<int> res;

int delta = 0;
bool solve(bool flag) {
    int j = 49;
    mn[0] = cnt[0];
    for (int i = 1; i <= 48; ++i) mn[i] = min(mn[i - 1], cnt[i]);
    for (int i = 48; i >= 0; --i) while (cnt[i + 1] > mn[i] || bcnt[i + 1] > 0) {
        ++delta;
        while (j >= 0 && cnt[j] == 0) --j;
        if (j < i + 1) {
            return false;
        }
        forn(k, j + 1) {
            if (--cnt[k] < 0) {
                return false;
            }
        }
        if (bcnt[i + 1] > 0) {
            --bcnt[i + 1];
        } else if (--cnt[i + 1] < 0) {
            return false;
        }
        mn[0] = cnt[0];
        for (int i = 1; i <= 48; ++i) mn[i] = min(mn[i - 1], cnt[i]);
    }
    if (flag) {
        if (cnt[0] == 0) {
            return false;
        }
        int pos = 0;
        while (cnt[pos + 1] == cnt[0]) {
            ++pos;
        }
        for (int i = pos; i >= 0; --i) {
            ++delta;
            while (j >= 0 && cnt[j] == 0) --j;
            if (j < 0) {
                return false;
            }
            forn(k, j + 1) {
                if (--cnt[k] < 0) {
                    return false;
                }
            }
            if (--cnt[i] < 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n) {
        LL x;
        cin >> x;
        LL b = 0;
        while ((1ll << b) < x) {
            ++b;
        }
        if ((1ll << b) == x) {
            ++cnt[b];
        } else {
            ++bcnt[b - 1];
        }
    }
    if (!solve(false)) {
        cout << -1 << endl;
        return 0;
    }
    res.pb(cnt[0] + delta);
    while (true) {
        if (!solve(true)) {
            break;
        }
        res.pb(cnt[0] + delta);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    if (res.empty()) res.pb(-1);
    for (int x : res) cout << x << ' ';
    cout << endl;
    return 0;
}