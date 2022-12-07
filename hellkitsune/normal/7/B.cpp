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

int t, m;
int a[100] = {};
string q;
int nxt = 1;

int main() {
    scanf("%d%d", &t, &m);
    REP(i, t) {
        cin >> q;
        if (q[0] == 'a') {
            int x;
            cin >> x;
            bool suc = false;
            for (int i = 0; i < m - x + 1; ++i) {
                bool flag = true;
                REP(j, x) if (a[i + j]) {
                    flag = false;
                    break;
                }
                if (flag) {
                    REP(j, x) a[i + j] = nxt;
                    suc = true;
                    cout << nxt++ << endl;
                    break;
                }
            }
            if (!suc) cout << "NULL" << endl;
        } else if (q[0] == 'e') {
            int x;
            cin >> x;
            if (x == 0) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
                continue;
            }
            bool suc = false;
            REP(i, m) if (a[i] == x) {
                a[i] = 0;
                suc = true;
            }
            if (!suc) cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
        } else {
            int j = 0;
            for (int i = 0; i < m; ++i) {
                if (a[i] == 0) ++j;
                else a[i - j] = a[i];
            }
            for (int i = m - j; i < m; ++i) a[i] = 0;
        }
    }
    return 0;
}