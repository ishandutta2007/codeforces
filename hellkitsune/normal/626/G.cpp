#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n, t, qq;
int val[200000], cnt[200000], jo[200000];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        LL le = (LL)val[lhs] * cnt[lhs] * (cnt[rhs] + jo[rhs]) * (cnt[rhs] + jo[rhs] + 1);
        LL ri = (LL)val[rhs] * cnt[rhs] * (cnt[lhs] + jo[lhs]) * (cnt[lhs] + jo[lhs] + 1);
        if (le != ri) return le > ri;
        return lhs < rhs;
    }
};

struct Cmp2 {
    inline bool operator()(const int &lhs, const int &rhs) const {
        LL le = (LL)val[lhs] * cnt[lhs] * (cnt[rhs] + jo[rhs]) * (cnt[rhs] + jo[rhs] - 1);
        LL ri = (LL)val[rhs] * cnt[rhs] * (cnt[lhs] + jo[lhs]) * (cnt[lhs] + jo[lhs] - 1);
        if (le != ri) return le < ri;
        return lhs < rhs;
    }
};

set<int, Cmp> q;
set<int, Cmp2> q2;

Double ans;

void upd() {
    while (t > 0 && !q.empty()) {
        --t;
        int ind = *q.begin();
        q.erase(q.begin());
        if (jo[ind] > 0) {
            q2.erase(ind);
        }
        ans += (Double)val[ind] * cnt[ind] / (LL(cnt[ind] + jo[ind]) * (cnt[ind] + jo[ind] + 1));
        ++jo[ind];
        if (jo[ind] < cnt[ind]) {
            q.insert(ind);
        }
        q2.insert(ind);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &t, &qq);
    forn(i, n) scanf("%d", val + i);
    forn(i, n) scanf("%d", cnt + i);
    forn(i, n) {
        q.insert(i);
    }
    ans = 0;
    upd();
    forn(_, qq) {
        int qt, pos;
        scanf("%d%d", &qt, &pos), --pos;
        ans -= (Double)val[pos] * jo[pos] / (cnt[pos] + jo[pos]);
        q.erase(pos);
        q2.erase(pos);
        forn(__, 1) if (jo[pos] > 0) {
            --jo[pos];
            ++t;
        }
        if (qt == 1) {
            ++cnt[pos];
        } else {
            --cnt[pos];
        }
        forn(__, 1) if (!q2.empty()) {
            int ind = *q2.begin();
            if (jo[ind] < cnt[ind]) {
                q.erase(ind);
            }
            q2.erase(ind);
            --jo[ind];
            ++t;
            ans -= (Double)val[ind] * cnt[ind] / (LL(cnt[ind] + jo[ind]) * (cnt[ind] + jo[ind] + 1));
            q.insert(ind);
            if (jo[ind] > 0) {
                q2.insert(ind);
            }
        }
        if (jo[pos] < cnt[pos]) {
            q.insert(pos);
        }
        if (jo[pos] > 0) {
            q2.insert(pos);
        }
        ans += (Double)val[pos] * jo[pos] / (cnt[pos] + jo[pos]);
        upd();
        printf("%.12f\n", (double)ans);
    }
    return 0;
}