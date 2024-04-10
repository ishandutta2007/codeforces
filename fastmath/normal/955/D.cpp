#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <random>
#include <time.h>
#include <queue>

using namespace std;
#define int long long

const int MAXN = 5e5 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 129;

int n, m;

int mod1(int n) {
    n %= MOD1;
    if (n < 0) return n + MOD1;
    return n;
}

int mod2(int n) {
    n %= MOD2;
    if (n < 0) return n + MOD2;
    return n;
}

int h1[MAXN], h2[MAXN];
int pw1[MAXN], pw2[MAXN];

int geth1(int l, int r) {
    return mod1(h1[r + 1] - h1[l] * pw1[r - l + 1]);
}

int geth2(int l, int r) {
    return mod2(h2[r + 1] - h2[l] * pw2[r - l + 1]);
}

int th1[MAXN], th2[MAXN];

bool check1(int i, int len) {
    return (geth1(i, i + len - 1) == th1[len] && geth2(i, i + len - 1) == th2[len]);
}

bool check2(int i, int len) {
    return (geth1(i - len + 1, i) == mod1(th1[m] - th1[m - len] * pw1[len]) && geth2(i - len + 1, i) == mod2(th2[m] - th2[m - len] * pw2[len])); 
}

int mxpref[MAXN], mxpost[MAXN];

int mmax1(int i, int j) {
    if (i == -1) return j;
    if (j == -1) return i;
    if (mxpost[i] >= mxpost[j]) return i;
    else return j;
}

int tree1[MAXN * 4];
void build1(int v, int tl, int tr) {
    if (tl == tr) {
        tree1[v] = tl;
        return;
    }

    int tm = (tl + tr) / 2;
    build1(v * 2 + 1, tl, tm);
    build1(v * 2 + 2, tm + 1, tr);
    tree1[v] = mmax1(tree1[v * 2 + 1], tree1[v * 2 + 2]);
}

int get1(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) return tree1[v];
    int tm = (tl + tr) / 2;
    return mmax1(get1(v * 2 + 1, tl, tm, l, r), get1(v * 2 + 2, tm + 1, tr, l, r));
}

int find1(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return -1;
    if (mxpost[tree1[v]] < x) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int lres = find1(v * 2 + 1, tl, tm, l, r, x);
    if (lres != -1) return lres;
    else return find1(v * 2 + 2, tm + 1, tr, l, r, x);
}

int mmax2(int i, int j) {
    if (i == -1) return j;
    if (j == -1) return i;
    if (mxpref[i] >= mxpref[j]) return i;
    else return j;
}

int tree2[MAXN * 4];
void build2(int v, int tl, int tr) {
    if (tl == tr) {
        tree2[v] = tl;
        return;
    }

    int tm = (tl + tr) / 2;
    build2(v * 2 + 1, tl, tm);
    build2(v * 2 + 2, tm + 1, tr);
    tree2[v] = mmax2(tree2[v * 2 + 1], tree2[v * 2 + 2]);
}

int get2(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) return tree2[v];
    int tm = (tl + tr) / 2;
    return mmax2(get2(v * 2 + 1, tl, tm, l, r), get2(v * 2 + 2, tm + 1, tr, l, r));
}

int find2(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return -1;
    if (mxpref[tree2[v]] < x) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int lres = find2(v * 2 + 1, tl, tm, l, r, x);
    if (lres != -1) return lres;
    else return find2(v * 2 + 2, tm + 1, tr, l, r, x);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pw1[i] = mod1(pw1[i - 1] * BASE);
        pw2[i] = mod2(pw2[i - 1] * BASE);
    }

    int k;
    cin >> n >> m >> k;

    string s, t;
    cin >> s >> t;
    
    for (int i = 0; i < n; ++i) {
        h1[i + 1] = mod1(h1[i] * BASE + s[i]);
        h2[i + 1] = mod2(h2[i] * BASE + s[i]);    
    }

    for (int i = 0; i < m; ++i) {
        th1[i + 1] = mod1(th1[i] * BASE + t[i]);
        th2[i + 1] = mod2(th2[i] * BASE + t[i]);        
    }

    for (int i = 0; i < n; ++i) {

        int l = 0;
        int r = min(n - i, m) + 1;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            if (check1(i, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        mxpref[i] = l;

        l = 0;
        r = min(i + 1, m) + 1;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            if (check2(i, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        mxpost[i] = l;
    }

    build1(0, 0, n - 1);
    build2(0, 0, n - 1);

    for (int i = 1; i <= min(k, m - 1); ++i) {
        int p1 = find2(0, 0, n - 1, k - i, n - 1, i);
        if (p1 == -1) continue;
        int r1 = p1 + i - 1;
        int ost = m - i;
        if (k < ost) continue;
        int rt = k - ost;
        int p2 = find1(0, 0, n - 1, r1 + ost, n - rt - 1, ost); 
        if (p2 == -1) continue;
        cout << "Yes\n";
        cout << r1 - k + 2 << ' ' << p2 - ost + 2 << '\n';
        return 0;
    }

    if (m <= k) {
        for (int i = 0; i + m - 1 < n; ++i) {
            if (geth1(i, i + m - 1) == th1[m] && geth2(i, i + m - 1) == th2[m]) {

                int l2 = min(n - k, i); 
                if (l2 >= k) {
                    cout << "Yes\n";
                    cout << "1 " << l2 + 1 << '\n';
                    return 0;
                }
                
                int r1 = max(k - 1, i + m - 1);
                if (n - r1 >= k) {
                    cout << "Yes\n";
                    cout << r1 - k + 2 << ' ' << r1 + 2 << '\n'; 
                    return 0;
                }
            }
        }
    }
    
    cout << "No\n";
    return 0;
}