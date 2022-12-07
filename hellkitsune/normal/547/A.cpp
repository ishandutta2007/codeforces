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

int x[2], y[2], h[2], a[2];
LL t[2];
int p[2];
int m;

int main() {
    cin >> m;
    REP(i, 2) cin >> h[i] >> a[i] >> x[i] >> y[i];
    REP(i, 2) {
        t[i] = -1;
        for (int j = 1; j <= m; ++j) {
            h[i] = (x[i] * (LL)h[i] + y[i]) % m;
            if (h[i] == a[i]) {
                t[i] = j;
                break;
            }
        }
        if (t[i] == -1) {
            cout << -1 << endl;
            return 0;
        }
        p[i] = -1;
        for (int j = 1; j <= m; ++j) {
            h[i] = (x[i] * (LL)h[i] + y[i]) % m;
            if (h[i] == a[i]) {
                p[i] = j;
                break;
            }
        }
    }
    int cnt = 0;
    while (t[0] != t[1]) {
        if (t[0] < t[1]) {
            if (p[0] == -1) {
                cout << -1 << endl;
                return 0;
            }
            t[0] += (t[1] - t[0]) - (t[1] - t[0]) % p[0];
            if (t[0] < t[1]) t[0] += p[0];
        } else {
            if (p[1] == -1) {
                cout << -1 << endl;
                return 0;
            }
            t[1] += (t[0] - t[1]) - (t[0] - t[1]) % p[1];
            if (t[1] < t[0]) t[1] += p[1];
        }
        if (++cnt == 5000000) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << t[0] << endl;
    return 0;
}