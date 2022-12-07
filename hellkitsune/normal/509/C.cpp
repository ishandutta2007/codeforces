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

int n, b[300];
int a[1305], a2[1305], sz, nsz;

bool go(int pos, int rem) {
    if (pos == sz) return false;
    if (rem <= a[pos]) return false;
    if (9 * (sz - pos) < rem) return false;
    a2[pos] = a[pos];
    if (go(pos + 1, rem - a[pos])) return true;
    if (a[pos] == 9) return false;
    a2[pos] = a[pos] + 1;
    rem -= a2[pos];
    for (int i = sz - 1; i > pos; --i) {
        a2[i] = min(9, rem);
        rem -= a2[i];
    }
    a2[pos] += rem;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> b[i];
    sz = 0;
    REP(i, n) {
        bool flag = true;
        int nsz = sz;
        if (sz * 9 < b[i]) flag = false, nsz = (b[i] + 8) / 9;
        if (flag && !go(0, b[i])) {
            flag = false;
            nsz = sz + 1;
        }
        if (!flag) {
            REP(i, nsz) a2[i] = 0;
            a2[0] = 1;
            --b[i];
            for (int j = nsz - 1; j >= 1; --j) {
                a2[j] = min(9, b[i]);
                b[i] -= a2[j];
            }
            a2[0] += b[i];
        }
        sz = nsz;
        REP(i, sz) a[i] = a2[i];
        REP(i, sz) cout << a[i];
        cout << endl;
    }
    return 0;
}