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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;
int hp[20] = {};
int d[10][17][17][17];
int preva[10][17][17][17], prevb[10][17][17][17], prevc[10][17][17][17], prevd[10][17][17][17];
int prev[10][17][17][17];
vector<int> ans;

const int INF = 1e9;

int main() {
    cin >> n >> a >> b;
    REP(i, n) cin >> hp[i], ++hp[i];
    while (hp[0]) {
        ans.pb(2);
        hp[0] = max(0, hp[0] - b);
        hp[1] = max(0, hp[1] - a);
        hp[2] = max(0, hp[2] - b);
    }
    while (hp[n - 1]) {
        ans.pb(n - 1);
        hp[n - 1] = max(0, hp[n - 1] - b);
        hp[n - 2] = max(0, hp[n - 2] - a);
        hp[n - 3] = max(0, hp[n - 3] - b);
    }
    int start = 0;
    while (start < n && hp[start] == 0) ++start;
    if (start == n) {
        cout << (int)ans.size() << endl;
        REP(i, ans.size())
            cout << ans[i] << ' ';
        cout << endl;
        return 0;
    }
    REP(i, n) REP(j, 17) REP(p, 17) REP(q, 17) d[i][j][p][q] = INF;
    d[start][hp[start]][hp[start + 1]][hp[start + 2]] = 0;
    prev[start][hp[start]][hp[start + 1]][hp[start + 2]] = -1;
    for (int i = start; i < n; ++i)
        for (int j = 16; j >= 1; --j)
            for (int p = 16; p >= 0; --p)
                for (int q = 16; q >= 0; --q) if (d[i][j][p][q] != INF) {
                    int ii = i, jj = j, pp = p, qq = q;
                    jj = max(0, jj - a);
                    pp = max(0, pp - b);
                    while (jj == 0 && ii < n - 1) {
                        jj = pp;
                        pp = qq;
                        qq = hp[ii + 3];
                        ++ii;
                    }
                    if (d[ii][jj][pp][qq] > d[i][j][p][q] + 1) {
                        d[ii][jj][pp][qq] = d[i][j][p][q] + 1;
                        prev[ii][jj][pp][qq] = i + 1;
                        preva[ii][jj][pp][qq] = i;
                        prevb[ii][jj][pp][qq] = j;
                        prevc[ii][jj][pp][qq] = p;
                        prevd[ii][jj][pp][qq] = q;
                    }
                    ii = i, jj = j, pp = p, qq = q;
                    jj = max(0, jj - b);
                    pp = max(0, pp - a);
                    qq = max(0, qq - b);
                    while (jj == 0 && ii < n - 1) {
                        jj = pp;
                        pp = qq;
                        qq = hp[ii + 3];
                        ++ii;
                    }
                    if (d[ii][jj][pp][qq] > d[i][j][p][q] + 1) {
                        d[ii][jj][pp][qq] = d[i][j][p][q] + 1;
                        prev[ii][jj][pp][qq] = i + 2;
                        preva[ii][jj][pp][qq] = i;
                        prevb[ii][jj][pp][qq] = j;
                        prevc[ii][jj][pp][qq] = p;
                        prevd[ii][jj][pp][qq] = q;
                    }
                }
    int i = n - 1, j = 0, p = 0, q = 0;
    while (prev[i][j][p][q] != -1) {
        ans.pb(prev[i][j][p][q]);
        int ii = preva[i][j][p][q], jj = prevb[i][j][p][q], pp = prevc[i][j][p][q], qq = prevd[i][j][p][q];
        i = ii, j = jj, p = pp, q = qq;
    }
    cout << (int)ans.size() << endl;
    REP(i, ans.size())
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}