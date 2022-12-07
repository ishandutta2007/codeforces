#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

unordered_map<LL, int> ma;

int n;
int a[25], b[25], c[25];
int aa = 0, bb = 0, cc = 0;
int rem[25], cur[25];
const int INF = 1e9;
int best = -INF;
LL bestPair;

int upto;

void go(int v) {
    if (v == upto) {
        LL ind = (LL(bb - aa + INF) << 32) | (cc - aa + INF);
        auto it = ma.find(ind);
        if (it == ma.end()) {
            ma[ind] = aa;
        } else if (it->second < aa) {
            it->second = aa;
        }
        return;
    }

    aa += a[v];
    bb += b[v];
    cc += c[v];

    aa -= a[v];
    go(v + 1);
    aa += a[v];

    bb -= b[v];
    go(v + 1);
    bb += b[v];

    cc -= c[v];
    go(v + 1);
    cc += c[v];

    aa -= a[v];
    bb -= b[v];
    cc -= c[v];
}

int bestVal;

void go3(int v) {
    if (v == upto) {
        LL ind = (LL(bb - aa + INF) << 32) | (cc - aa + INF);
        if (ind == bestPair && aa == bestVal) {
            REP(j, upto) rem[j] = cur[j];
            REP(j, n) if (rem[j] == 0) {
                printf("MW\n");
            } else if (rem[j] == 1) {
                printf("LW\n");
            } else {
                printf("LM\n");
            }
            exit(0);
        }
        return;
    }

    aa += a[v];
    bb += b[v];
    cc += c[v];

    cur[v] = 0;
    aa -= a[v];
    go3(v + 1);
    aa += a[v];

    cur[v] = 1;
    bb -= b[v];
    go3(v + 1);
    bb += b[v];

    cur[v] = 2;
    cc -= c[v];
    go3(v + 1);
    cc += c[v];

    aa -= a[v];
    bb -= b[v];
    cc -= c[v];
}

int upFrom;

void go2(int v) {
    if (v == upto) {
        LL ind = (LL(aa - bb + INF) << 32) | (aa - cc + INF);
        auto it = ma.find(ind);
        if (it != ma.end() && it->second + aa > best) {
            best = it->second + aa;
            bestPair = ind;
            for (int j = upFrom; j < upto; ++j) {
                rem[j] = cur[j];
            }
        }
        return;
    }

    aa += a[v];
    bb += b[v];
    cc += c[v];

    cur[v] = 0;
    aa -= a[v];
    go2(v + 1);
    aa += a[v];

    cur[v] = 1;
    bb -= b[v];
    go2(v + 1);
    bb += b[v];

    cur[v] = 2;
    cc -= c[v];
    go2(v + 1);
    cc += c[v];

    aa -= a[v];
    bb -= b[v];
    cc -= c[v];
}

int main() {
   // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d", a + i, b + i, c + i);
    upFrom = upto = n / 2;
    aa = bb = cc = 0;
    go(0);
    upto = n;
    aa = bb = cc = 0;
    go2(upFrom);
    if (best == -INF) {
        printf("Impossible\n");
        return 0;
    }
    upto = n / 2;
    aa = bb = cc = 0;
    bestVal = ma[bestPair];
    go3(0);
    return 0;
}