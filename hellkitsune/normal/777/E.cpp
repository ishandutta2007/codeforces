#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    int a, b, h;

    inline bool operator < (const S &rhs) const {
        if (b != rhs.b) return b > rhs.b;
        if (a <= b && rhs.a <= b) return a > rhs.a;
        return a < rhs.a;
    }
};

int n;
S s[100000];
vector<int> all;
LL fen[200005] = {};

void fenUpd(int pos, LL h) {
    for (; pos < 200005; pos |= pos + 1) {
        fen[pos] = max(fen[pos], h);
    }
}

LL fenGet(int pos) {
    LL res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res = max(res, fen[pos]);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].h);
        ++s[i].a;
        all.pb(s[i].a);
        all.pb(s[i].b);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    forn(i, n) {
        s[i].a = lower_bound(all.begin(), all.end(), s[i].a) - all.begin();
        s[i].b = lower_bound(all.begin(), all.end(), s[i].b) - all.begin();
    }
    sort(s, s + n);
    LL ans = 0;
    forn(i, n) {
        LL val = fenGet(s[i].b) + s[i].h;
        fenUpd(s[i].a, val);
        ans = max(ans, val);
    }
    cout << ans << endl;
    return 0;
}