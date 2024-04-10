//copied from https://www.luogu.com.cn/blog/1973224568qq/kao-shi-2021-coe-iii-d

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0, _n = n; i < _n; i++)
#define pb push_back
typedef vector <int> vi;
typedef vector <vi> vii;

vii A[15];

void gA(int m) {
    if (m == 0) {
        A[0] = {{1}};
        return ;
    }
    vii &L = A[m - 1], &R = A[m];
    forn(i, L.size()) {
        vi t;
        forn(j, L[i].size()) t.pb(L[i][j]);
        forn(j, L[i].size()) t.pb(-L[i][j]);
        forn(j, L.size()) t.pb(i == j);
        R.pb(t);
    }
    forn(i, L.size()) {
        vi t;
        forn(j, L[i].size()) t.pb(L[i][j]);
        forn(j, L[i].size()) t.pb(L[i][j]);
        forn(j, L.size()) t.pb(0);
        R.pb(t);
    }
}

vi operator + (vi x, vi y) {
    x.insert(x.end(), y.begin(), y.end());
    return x;
}

vi dA(int m, vi r) {
    if (m == 0) {
        return r;
    }
    int l = A[m - 1].size();
    vi x, y, z;
    for (int i = 0; i < l; i++) {
        z.pb(((r[i] + r[l + i]) % 2 + 2) % 2);
        x.pb((r[l + i] + (r[i] - z[i])) / 2);
        y.pb((r[l + i] - (r[i] - z[i])) / 2);
    }
    return dA(m - 1, x) + dA(m - 1, y) + z;
}

vii B[15];

void gB(int m) {
    if (m == 1) {
        B[1] = {{1}, {0}};
        return ;
    }
    vii &L = B[m - 1], &V = A[m - 1], &R = B[m];
    forn(i, L.size()) {
        vi t;
        forn(j, L[i].size()) t.pb(L[i][j]);
        forn(j, V[i].size()) t.pb(V[i][j] == 1);
        R.pb(t);
    }
    forn(i, L.size()) {
        vi t;
        forn(j, L[i].size()) t.pb(L[i][j]);
        forn(j, V[i].size()) t.pb(V[i][j] == -1);
        R.pb(t);
    }
}

vi dB(int m, vi r) {
    if (m == 1) {
        return {r[0]};
    }
    int l = B[m - 1].size();
    vi x, y;
    for (int i = 0; i < l; i++) {
        x.pb(r[i] - r[l + i]);
    }
    x = dA(m - 1, x);
    for (int i = 0; i < l; i++) {
        int t = r[i];
        for (int j = 0; j < (int)x.size(); j++) {
            t -= x[j] * (A[m - 1][i][j] == 1);
        }
        y.pb(t);
    }
    y = dB(m - 1, y);
    return y + x;
}

int n;
double K;

int query(vi A) {
    string S;
    for (int i = 0; i < n; i++)
        S += "TF"[A[i]];
    printf("%s\n", S.c_str());
    fflush(stdout);

    int res;
    scanf("%d", &res);
    if (res == n) exit(0);
    return res;
}

int popcnt(vi x) {
    int c = 0;
    for (auto i : x) c += i;
    return c;
}

int main() {
    cin >> n;
    for (int i = 0; i < 11; i++) gA(i);
    for (int i = 1; i < 11; i++) gB(i);
    int c = 1;
    while (B[c][0].size() < n) c++;

    vi ret;
    ret.clear();
    for (int i = 0; i < B[c].size(); i++) {
        ret.pb(query(B[c][i]));
    }
    int lst = ret.back();
    for (int i = 0; i < B[c].size(); i++) {
        ret[i] = (ret[i] - lst + popcnt(B[c][i])) / 2;
    }

    vi ans = dB(c, ret);
    query(ans);
    return 0;
}