#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s, a, b, c;
int d[9][9][9][2], pi[9][9][9][2], pj[9][9][9][2], pk[9][9][9][2], pme[9][9][9][2];
int pid[9][9][9][2], pjd[9][9][9][2], pkd[9][9][9][2];
int al, bl, cl;
const int INF = 1e9;

int main() {
    cin >> s;
    for (char &c : s) if (c == '+' || c == '=') {
        c = ' ';
    }
    istringstream iss(s);
    iss >> a >> b >> c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    al = (int)a.length();
    bl = (int)b.length();
    cl = (int)c.length();
    REP(i, al + 2) REP(j, bl + 2) REP(k, cl + 2) REP(me, 2) {
        d[i][j][k][me] = INF;
    }
    d[0][0][0][0] = 0;
    REP(i, al + 2) REP(j, bl + 2) REP(k, cl + 2) REP(me, 2) {
        REP(ii, 11) REP(jj, 11) REP(kk, 11) {
            if (ii == 10 && i >= al) continue;
            if (jj == 10 && j >= bl) continue;
            if (kk == 10 && k >= cl) continue;
            if (ii > 0 && i > al) continue;
            if (jj > 0 && j > bl) continue;
            if (kk > 0 && k > cl) continue;
            if (ii != 10 && jj != 10 && kk != 10) continue;
            int id = ii == 10 ? (a[i] - '0') : ii;
            int jd = jj == 10 ? (b[j] - '0') : jj;
            int kd = kk == 10 ? (c[k] - '0') : kk;
            if ((id + jd + me) % 10 != kd) continue;
            int ni = i + (ii == 10);
            int nj = j + (jj == 10);
            int nk = k + (kk == 10);
            int nme = (id + jd + me) / 10;
            int mni, mxi, mnj, mxj, mnk, mxk;
            mni = mxi = ni;
            mnj = mxj = nj;
            mnk = mxk = nk;
            if (ni == al && ii == 0) ++mxi;
            if (nj == bl && jj == 0) ++mxj;
            if (nk == cl && kk == 0) ++mxk;
            for (int ci = mni; ci <= mxi; ++ci) {
                for (int cj = mnj; cj <= mxj; ++cj) {
                    for (int ck = mnk; ck <= mxk; ++ck) {
                        int newLen = d[i][j][k][me];
                        if (ci <= al) ++newLen;
                        if (cj <= bl) ++newLen;
                        if (ck <= cl) ++newLen;
                        if (d[ci][cj][ck][nme] > newLen) {
                            d[ci][cj][ck][nme] = newLen;
                            pi[ci][cj][ck][nme] = i;
                            pj[ci][cj][ck][nme] = j;
                            pk[ci][cj][ck][nme] = k;
                            pme[ci][cj][ck][nme] = me;
                            pid[ci][cj][ck][nme] = id;
                            pjd[ci][cj][ck][nme] = jd;
                            pkd[ci][cj][ck][nme] = kd;
                        }
                    }
                }
            }
        }
    }
    int best = INF, i = 0, j = 0, k = 0, me = 0;
    for (int ii = al; ii <= al + 1; ++ii) for (int jj = bl; jj <= bl + 1; ++jj) for (int kk = cl; kk <= cl + 1; ++kk) {
        if (d[ii][jj][kk][0] < best) {
            best = d[ii][jj][kk][0];
            i = ii;
            j = jj;
            k = kk;
        }
    }
    a = b = c = "";
    while (i || j || k || me) {
        if (i != al + 1) a += pid[i][j][k][me] + '0';
        if (j != bl + 1) b += pjd[i][j][k][me] + '0';
        if (k != cl + 1) c += pkd[i][j][k][me] + '0';
        int ni = pi[i][j][k][me];
        int nj = pj[i][j][k][me];
        int nk = pk[i][j][k][me];
        me = pme[i][j][k][me];
        i = ni;
        j = nj;
        k = nk;
    }
    cout << a << '+' << b << '=' << c << endl;
    return 0;
}