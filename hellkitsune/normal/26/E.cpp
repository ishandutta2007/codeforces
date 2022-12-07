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

int n, w;
int a[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> w;
    REP(i, n) cin >> a[i];
    int sum = 0;
    REP(i, n) sum += a[i];
    int ind = -1;
    REP(i, n) if (a[i] == 1) ind = i;
    if (w > sum || w < 1 || (w == 1 && ind == -1)) {
        cout << "No\n";
        return 0;
    }
    if (n == 1) {
        if (w != a[0]) {
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
        REP(i, w * 2) cout << "1 ";
        cout << '\n';
        return 0;
    }
    cout << "Yes\n";
    if (ind == -1) {
        REP(i, n) if (a[i] + a[i + 1] < w) {
            REP(j, a[i]) cout << i + 1 << ' ' << i + 1 << ' ';
            w -= a[i];
        } else {
            while (w > 2) {
                if (a[i] > a[i + 1]) {
                    cout << i + 1 << ' ' << i + 1 << ' ';
                    --a[i];
                } else {
                    cout << i + 2 << ' ' << i + 2 << ' ';
                    --a[i + 1];
                }
                --w;
            }
            cout << i + 1 << ' ';
            for (int j = i + 2; j < n; ++j) REP(k, a[j])
                cout << j + 1 << ' ' << j + 1 << ' ';
            REP(j, a[i + 1] - 1)
                cout << i + 2 << ' ' << i + 2 << ' ';
            cout << i + 1 << ' ' << i + 2 << ' ';
            --a[i];
            REP(j, a[i])
                cout << i + 1 << ' ' << i + 1 << ' ';
            cout << i + 2 << '\n';
            break;
        }
    } else {
        REP(i, n) if (i != ind) REP(j, a[i]) {
            if (--w == 0) cout << ind + 1 << ' ';
            cout << i + 1 << ' ' << i + 1 << ' ';
        }
        if (w == 1) cout << ind + 1 << ' ';
        cout << ind + 1 << '\n';
    }
    return 0;
}