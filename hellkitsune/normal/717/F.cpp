#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200000];
int st[2][1 << 18] = {}, sm[2][1 << 18] = {}, sp[2][1 << 18] = {};
const int off = 1 << 17;

void stBuild() {
    forn(tr, 2) for (int i = off - 1; i >= 1; --i) {
        sm[tr][i] = min(sm[tr][2 * i], sm[tr][2 * i + 1]);
    }
}

int stVal;
void stAdd(int tr, int v, int L, int R, int l, int r) {
    if (l > r) return;
    if (l == L && r == R) {
        st[tr][v] += stVal;
        return;
    }
    int mid = (L + R) >> 1;
    stAdd(tr, 2 * v, L, mid, l, min(r, mid));
    stAdd(tr, 2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

void smPush(int tr, int v) {
    for (int i = 2 * v; i <= 2 * v + 1; ++i) {
        sm[tr][i] += sp[tr][v];
        sp[tr][i] += sp[tr][v];
    }
    sp[tr][v] = 0;
}

void smAdd(int tr, int v, int L, int R, int l, int r) {
    if (l > r) return;
    if (l == L && r == R) {
        sm[tr][v] += stVal;
        sp[tr][v] += stVal;
        return;
    }
    if (sp[tr][v] != 0) {
        smPush(tr, v);
    }
    int mid = (L + R) >> 1;
    smAdd(tr, 2 * v, L, mid, l, min(r, mid));
    smAdd(tr, 2 * v + 1, mid + 1, R, max(l, mid + 1), r);
    sm[tr][v] = min(sm[tr][2 * v], sm[tr][2 * v + 1]);
}

int stGet(int tr, int pos) {
    int res = 0;
    for (pos += off; pos >= 1; pos >>= 1) {
        res += st[tr][pos];
    }
    return res;
}

const int INF = 2e9;

int smGet(int tr, int v, int L, int R, int l, int r) {
    if (l > r) return INF;
    if (l == L && r == R) {
        return sm[tr][v];
    }
    if (sp[tr][v] != 0) {
        smPush(tr, v);
    }
    int mid = (L + R) >> 1;
    return min(smGet(tr, 2 * v, L, mid, l, min(r, mid)),
        smGet(tr, 2 * v + 1, mid + 1, R, max(l, mid + 1), r));
}

int fen[200005] = {};

void fenAdd(int pos, int val) {
    for (; pos < 200005; pos |= pos + 1) {
        fen[pos] += val;
    }
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i), --a[i];
    int pre = 0;
    forn(i, n) {
        fenAdd(i, a[i] - pre);
        pre = a[i];
    }
    int sum = 0;
    forn(i, n) {
        if (i & 1) {
            sum -= a[i];
            st[1][off + i / 2] = -sum;
            sm[1][off + i / 2] += sum;

            sm[0][off + (i - 1) / 2] += a[i];
        } else {
            sum += a[i];
            st[0][off + i / 2] = sum;
            sm[0][off + i / 2] -= sum;
            if (i) {
                sm[1][off + (i - 1) / 2] += a[i];
            }
        }
    }
    stBuild();
    int qc;
    scanf("%d", &qc);
    forn(q, qc) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int from, to;
            scanf("%d%d%d", &from, &to, &stVal);
            fenAdd(from, stVal);
            fenAdd(to + 1, -stVal);
            if (from & 1) {
                stAdd(1, 1, 0, off - 1, from / 2, (to - 1) / 2);
                stVal *= -1;
                smAdd(1, 1, 0, off - 1, from / 2, (to - 1) / 2);
                stVal *= -1;
            } else {
                stAdd(0, 1, 0, off - 1, from / 2, to / 2);
                stVal *= -1;
                smAdd(0, 1, 0, off - 1, from / 2, to / 2);
                stVal *= -1;
            }
            if (!((to ^ from) & 1)) {
                forn(i, 2) {
                    int nfrom = to + 1;
                    int nto = n - 1;
                    if ((nfrom & 1) != i) ++nfrom;
                    if ((nto & 1) != i) --nto;
                    if (nto >= nfrom) {
                        stVal *= (((i ^ to) & 1) ? -1 : 1);
                        stAdd(i, 1, 0, off - 1, nfrom / 2, nto / 2);
                        stVal *= -1;
                        smAdd(i, 1, 0, off - 1, nfrom / 2, nto / 2);
                        stVal *= -1;
                        stVal *= (((i ^ to) & 1) ? -1 : 1);
                    }
                }
            }
            --from;
            --to;
            if (from < 0) ++from;
            forn(i, 2) {
                int nfrom = from;
                int nto = to;
                if ((nfrom & 1) != i) ++nfrom;
                if ((nto & 1) != i) --nto;
                if (nto >= nfrom) {
                    smAdd(i, 1, 0, off - 1, nfrom / 2, nto / 2);
                }
            }
        } else if (qt == 2) {

//            forn(i, n) {
//                cerr << smGet(i & 1, 1, 0, off - 1, i / 2, i / 2) << ' ';
//            }
//            cerr << endl;

            int from, to;
            scanf("%d%d", &from, &to);
            int toVal = fenGet(to);
            if (from == to) {
                if (toVal == 0) {
                    printf("1\n");
                } else {
                    printf("0\n");
                }
                continue;
            }
            LL prefVal = stGet((to - 1) & 1, (to - 1) / 2);
            if (from > 0) {
                prefVal += stGet((from - 1) & 1, (from - 1) / 2) * (((from ^ to) & 1) == 0 ? -1 : 1);
            }
            if (prefVal != toVal) {
                printf("0\n");
                continue;
            }
            bool ok = true;
            forn(i, 2) {
                int nfrom = from;
                int nto = to - 1;
                if ((nfrom & 1) != i) ++nfrom;
                if ((nto & 1) != i) --nto;
                if (nto >= nfrom) {
                    LL mn = smGet(i, 1, 0, off - 1, nfrom / 2, nto / 2);
                    if (from > 0) {
                        mn += stGet((from - 1) & 1, (from - 1) / 2) * (((from ^ i) & 1) == 0 ? -1 : 1);
                    }
                    if (mn < 0) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}