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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, w[100][100];
LL a[100], b[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) REP(j, m) cin >> w[i][j];
    LL cur = -1;
    REP(i, n - 1) {
        int pos = 0, neg = 0;
        bool bpos = false, bneg = false;
        REP(j, m) {
            int val = w[i + 1][j] - w[i][j];
            if (val >= 0) {
                if (bpos && pos != val) {
                    cout << "NO\n";
                    return 0;
                }
                bpos = true;
                pos = val;
            } else {
                if (bneg && neg != val) {
                    cout << "NO\n";
                    return 0;
                }
                bneg = true;
                neg = val;
            }
        }
        if (bpos && bneg) {
            int val = pos - neg;
            if (cur != -1 && cur != val) {
                cout << "NO\n";
                return 0;
            }
            cur = val;
        }
        if (bpos) a[i + 1] = pos;
        else a[i + 1] = neg;
    }
    REP(j, m - 1) {
        int pos = 0, neg = 0;
        bool bpos = false, bneg = false;
        REP(i, n) {
            int val = w[i][j + 1] - w[i][j];
            if (val >= 0) {
                if (bpos && pos != val) {
                    cout << "NO\n";
                    return 0;
                }
                bpos = true;
                pos = val;
            } else {
                if (bneg && neg != val) {
                    cout << "NO\n";
                    return 0;
                }
                bneg = true;
                neg = val;
            }
        }
        if (bpos && bneg) {
            int val = pos - neg;
            if (cur != -1 && cur != val) {
                cout << "NO\n";
                return 0;
            }
            cur = val;
        }
        if (bpos) b[j + 1] = pos;
        else b[j + 1] = neg;
    }
    if (cur != -1) {
        REP(i, n) REP(j, m) if (w[i][j] >= cur) {
            cout << "NO\n";
            return 0;
        }
    }
    if (cur == -1) cur = 1e10;
    cout << "YES\n" << cur << '\n';
    a[0] = 0;
    b[0] = w[0][0];
    for (int i = 1; i < n; ++i) a[i] = (a[i - 1] + a[i] + cur) % cur;
    for (int i = 1; i < m; ++i) b[i] = (b[i - 1] + b[i] + cur) % cur;
    REP(i, n) cout << a[i] << ' ';
    cout << endl;
    REP(i, m) cout << b[i] << ' ';
    cout << endl;
    return 0;
}