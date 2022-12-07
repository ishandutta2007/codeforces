#include <cstdio>
#include <cmath>
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

int n;
int c[1000], p[1000], match[1000];
bool used[1000], usedr[1000];
int k;
int r[1000];

int main() {
    cin >> n;
    REP(i, n) {
        cin >> c[i] >> p[i];
    }
    cin >> k;
    REP(i, k)
        cin >> r[i];
    REP(i, n) {
        used[i] = false;
        match[i] = -1;
    }
    REP(i, k)
        usedr[i] = false;
    int ans = 0, ansc = 0;
    REP(i, n) {
        int maxj = 0;
        REP(j, n)
            if (!used[j]) {
                maxj = j;
                break;
            }
        for (int j = maxj + 1; j < n; ++j)
            if (!used[j] && p[j] > p[maxj])
                maxj = j;
        used[maxj] = true;
        int minr = -1;
        REP(j, k)
            if (!usedr[j] && r[j] >= c[maxj] && (minr == -1 || r[j] < r[minr]))
                minr = j;
        if (minr != -1) {
            match[maxj] = minr;
            ans += p[maxj];
            ++ansc;
            usedr[minr] = true;
        }
    }
    cout << ansc << ' ' << ans << endl;
    REP(i, n)
        if (match[i] != -1)
            cout << i + 1 << ' ' << match[i] + 1 << endl;
    return 0;
}