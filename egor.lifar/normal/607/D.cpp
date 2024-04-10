#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;


#define MOD 1000000007


long long mul_inv(long long a, long long b) {
    long long b0 = b, t, q;
    long long x0 = 0, x1 = 1;
    if (b == 1) {
        return 1;
    }
    while (a > 1) {
        q = a / b;
        t = b;
        b = a % b;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) {
        x1 += b0;
    }
    return x1;
}


const int MaxN = 300000;
int n, m;
vector<int> edge[MaxN];
int ss;


struct NODE
{
    long long sum, lazy;
    long long ori;
} it[MaxN * 2];


int ord[MaxN];
int ordi;
pair<int, int> eu[MaxN];
long long a[MaxN];
int par[MaxN];
long long q[MaxN][3];
long long child[MaxN];


void back(int v, int parent) {
    ord[ordi++] = v;
    eu[v].first = ordi - 1;
    for(auto e : edge[v]) {
        if (e == parent) {
            continue;
        }
        back(e, v);
    }
    eu[v].second = ordi - 1;
}


void recalc(int v) {
    if (v >= ss) {
        it[v].sum = it[v].ori * it[v].lazy % MOD;
    } else {
        it[v].sum = (it[v * 2].sum + it[v * 2 + 1].sum) * it[v].lazy % MOD;
    }
}


void updateori(int x) {
    recalc(x);
    for (x /= 2; x > 0; x /= 2) {
        recalc(x);
    }
}


void update(int v, int vl, int vr, int l, int r, long long vv) {
    if (vl > vr) {
        return;
    }
    if (vl == l && vr == r) {
        it[v].lazy *= vv;
        it[v].lazy %= MOD;
        recalc(v);
        return;
    }
    it[v * 2].lazy *= it[v].lazy;
    it[v * 2 + 1].lazy *= it[v].lazy;
    it[v * 2].lazy %= MOD;
    it[v * 2 + 1].lazy %= MOD;
    it[v].lazy = 1;
    recalc(v * 2), recalc(v * 2 + 1);
    update(v * 2, vl, min(vr, (l + r) / 2), l, (l + r) / 2, vv);
    update(v * 2 + 1, max(vl, (l + r) / 2 + 1), vr, (l + r) / 2 + 1, r, vv);
    recalc(v);
}


long long getsum(int v, int vl, int vr, int l, int r) {
    if (vl > vr) {
        return 0;
    }
    if (vl == l && vr == r) {
        return it[v].sum;
    }
    it[v * 2].lazy *= it[v].lazy;
    it[v * 2 + 1].lazy *= it[v].lazy;
    it[v * 2].lazy %= MOD;
    it[v * 2 + 1].lazy %= MOD;
    it[v].lazy = 1;
    recalc(v * 2);
    recalc(v * 2 + 1);
    return (getsum(v * 2, vl, min(vr, (l + r) / 2), l, (l + r) / 2) + getsum(v * 2 + 1, max(vl, (l + r) / 2 + 1), vr, (l + r) / 2 + 1, r)) % MOD;
}


int main() {
    cin >> a[0] >> m;
    n = 1;
    for (int i = 0; i < m; i++) {
        scanf("%I64d", &q[i][0]);
        if (q[i][0] == 1) {
            scanf("%I64d %I64d", &q[i][1], &q[i][2]);
            q[i][1]--;
            a[n++] = q[i][2];
            par[n - 1] = q[i][1];
            edge[n - 1].push_back(q[i][1]);
            edge[q[i][1]].push_back(n - 1);
        } else {
            scanf("%I64d", &q[i][1]);
            q[i][1]--;
        }
    }
    back(0, -1);
    ss = 1;
    while (ss < n) {
        ss *= 2;
    }
    int xn = 1;
    child[0] = 1;
    for (int i = 0; i < ss * 2; i++) {
        it[i].lazy = 1;
    }
    it[ss + eu[0].first].ori = a[0];
    updateori(ss + eu[0].first);
    for (int i = 0; i < m; i++) {
        if (q[i][0] == 1) {
            int x = q[i][1];
            update(1, eu[x].first, eu[x].second, 0, ss - 1, mul_inv(child[x], MOD));
            child[x]++;
            it[ss + eu[xn].first].ori = a[xn];
            updateori(ss + eu[xn].first);
            update(1, eu[x].first, eu[x].second, 0, ss - 1, child[x]);
            child[xn] = 1;
            xn++;
        } else {
            int x = q[i][1];
            long long res = getsum(1, eu[x].first, eu[x].second, 0, ss - 1);
            long long res2 = 1;
            if (x != 0){
                res2 = getsum(1, eu[par[x]].first, eu[par[x]].first, 0, ss - 1);
                res2 *= mul_inv(a[par[x]], MOD);
                res2 %= MOD;
            }
            res *= mul_inv(res2, MOD);
            res %= MOD;
            printf("%I64d\n", res);
        }
    }
    return 0;
}