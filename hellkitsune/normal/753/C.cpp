#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a[4], b[4];
int res[5][5];
bool has[15];
int rem[5555][4];
int cnt;

void gen() {
    forn(i, 10) {
        forn(j, 10) {
            if (j == i) continue;
            forn(k, 10) {
                if (k == i || k == j) continue;
                forn(p, 10) {
                    if (p == i || p == j || p == k) continue;
                    rem[cnt][0] = i;
                    rem[cnt][1] = j;
                    rem[cnt][2] = k;
                    rem[cnt][3] = p;
                    ++cnt;
                }
            }
        }
    }
}

void cmp(int *a, int *b, int &aa, int &bb) {
    aa = 0, bb = 0;
    forn(i, 4) {
        bb += has[b[i]];
    }
    forn(i, 4) {
        aa += b[i] == a[i];
    }
    bb -= aa;
}

int check() {
    memset(res, 0, sizeof res);
    memset(has, 0, sizeof has);
    forn(i, 4) {
        has[a[i]] = true;
    }
    forn(z, cnt) {
        int aa, bb;
        cmp(a, rem[z], aa, bb);
        ++res[aa][bb];
    }
    int mx = 0;
    forn(i, 5) forn(j, 5) {
        mx = max(mx, res[i][j]);
    }
    if (mx == 1 && res[4][0] == 1) {
        mx = 0;
    }
    return mx;
}

int main() {
    gen();
    forn(times, 7) {
        int best = 12341234;
        for (a[0] = 0; a[0] < 10; ++a[0]) {
            for (a[1] = 0; a[1] < 10; ++a[1]) {
                for (a[2] = 0; a[2] < 10; ++a[2]) {
                    for (a[3] = 0; a[3] < 10; ++a[3]) {
                        int cur = check();
                        if (cur < best) {
                            best = cur;
                            forn(i, 4) {
                                b[i] = a[i];
                            }
                        }
                    }
                }
            }
        }
        forn(i, 4) cout << b[i];
        cout << endl;
        int aa, bb;
        cin >> aa >> bb;
        if (aa == 4) {
            return 0;
        }
        int ncnt = 0;
        memset(has, 0, sizeof has);
        forn(i, 4) {
            has[b[i]] = true;
        }
        forn(i, cnt) {
            int ca, cb;
            cmp(b, rem[i], ca, cb);
//            if (rem[i][0] == 1 && rem[i][1] == 3 && rem[i][2] == 5 && rem[i][3] == 7) {
//                cerr << "!" << endl;
//            }
            if (ca == aa && cb == bb) {
//                forn(j, 4) cerr << rem[i][j];
//                cerr << endl;
                forn(j, 4) rem[ncnt][j] = rem[i][j];
                ++ncnt;
            }
        }
        assert(ncnt != 0);
        cnt = ncnt;
    }
    assert(false);
    return 0;
}