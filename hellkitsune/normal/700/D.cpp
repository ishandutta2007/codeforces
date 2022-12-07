#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, qc;
int a[100005];
int freq[100005], ord[100005], inv[100005];
int cnt[100005] = {}, small[100005] = {};
int from[100005], to[100005];
const int ROOT = 320;
const int BIG_COUNT = 100;
const int SMALL = (100000 + BIG_COUNT - 1) / BIG_COUNT;

inline bool cmp(const int &lhs, const int &rhs) {
    return freq[lhs] > freq[rhs];
}

inline bool qcmp(const int &lhs, const int &rhs) {
    if (from[lhs] / ROOT != from[rhs] / ROOT) return from[lhs] < from[rhs];
    return to[lhs] < to[rhs];
}

int l = 0, r = -1;

void extendRight() {
    ++r;
    if (a[r] >= BIG_COUNT) {
        --small[cnt[a[r]]];
        ++small[cnt[a[r]] + 1];
    }
    ++cnt[a[r]];
}

void extendLeft() {
    --l;
    if (a[l] >= BIG_COUNT) {
        --small[cnt[a[l]]];
        ++small[cnt[a[l]] + 1];
    }
    ++cnt[a[l]];
}

void shrinkRight() {
    if (a[r] >= BIG_COUNT) {
        --small[cnt[a[r]]];
        ++small[cnt[a[r]] - 1];
    }
    --cnt[a[r]];
    --r;
}

void shrinkLeft() {
    if (a[l] >= BIG_COUNT) {
        --small[cnt[a[l]]];
        ++small[cnt[a[l]] - 1];
    }
    --cnt[a[l]];
    ++l;
}

priority_queue<int, vector<int>, greater<int> > q;
int c[SMALL + 1];
int res[100005];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), --a[i];
    REP(i, n) ++freq[a[i]];
    REP(i, 100000) ord[i] = i;
    sort(ord, ord + 100000, cmp);
    REP(i, 100000) inv[ord[i]] = i;
    REP(i, n) a[i] = inv[a[i]];
    scanf("%d", &qc);
    REP(i, qc) scanf("%d%d", from + i, to + i), --from[i], --to[i];
    REP(i, qc) ord[i] = i;
    sort(ord, ord + qc, qcmp);
    REP(ii, qc) {
        int i = ord[ii];
        while (r < to[i]) extendRight();
        while (l > from[i]) extendLeft();
        while (r > to[i]) shrinkRight();
        while (l < from[i]) shrinkLeft();
        for (int j = 1; j <= SMALL; ++j) {
            c[j] = small[j];
        }
        int ans = 0;
        int rem = -1;
        REP(i, BIG_COUNT) if (cnt[i] <= SMALL) {
            ++c[cnt[i]];
        } else {
            q.push(cnt[i]);
        }
        for (int j = 1; j <= SMALL; ++j) if (c[j]) {
            if (rem != -1) {
                --c[j];
                ans += j + rem;
                if (j + rem <= SMALL) {
                    ++c[j + rem];
                } else {
                    q.push(j + rem);
                }
            }
            ans += j * (c[j] & ~1);
            int nj = j << 1;
            if (nj <= SMALL) {
                c[nj] += c[j] >> 1;
            } else {
                REP(times, c[j] >> 1) {
                    q.push(nj);
                }
            }
            if (c[j] & 1) {
                rem = j;
            } else {
                rem = -1;
            }
        }
        if (rem != -1) {
            q.push(rem);
        }
        while ((int)q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            ans += a + b;
            q.push(a + b);
        }
        assert(!q.empty());
        q.pop();
        res[i] = ans;
    }
    REP(i, qc) {
        printf("%d\n", res[i]);
    }
    return 0;
}