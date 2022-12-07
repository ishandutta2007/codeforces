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

int n, m;
int a[100000], le = 0, ri;
LL fen[100000];
bool rev = false;

LL fen_query(int pos) {
    LL ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ret += fen[pos];
    return ret;
}

void fen_add(int pos, int val) {
    for (; pos < n; pos |= pos + 1)
        fen[pos] += val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m, ri = n;
    REP(i, n) a[i] = 1, fen_add(i, 1);
    REP(q, m) {
        int x;
        cin >> x;
        if (x == 1) {
            int p;
            cin >> p;
            int mid = (ri - le) / 2;
            if (p > mid) {
                p = ri - le - p;
                rev = !rev;
            }
            if (rev) {
                REP(i, p) {
                    a[ri - 1 - p - i] += a[ri - p + i];
                    fen_add(ri - 1 - p - i, a[ri - p + i]);
                }
                ri -= p;
            } else {
                REP(i, p) {
                    a[le + p + i] += a[le + p - i - 1];
                    fen_add(le + p + i, a[le + p - i - 1]);
                }
                le += p;
            }
        } else {
            int l, r;
            cin >> l >> r;
            if (rev) cout << fen_query(ri - l - 1) - fen_query(ri - r - 1) << '\n';
            else cout << fen_query(r + le - 1) - fen_query(l + le - 1) << '\n';
        }
    }
    return 0;
}