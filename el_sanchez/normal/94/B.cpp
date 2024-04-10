#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <complex>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = (int)1E9;
const int MAXN = (int)1000100;
const double eps = 1e-9;
const int base = 2;

using namespace std;

bool g[5][5];
int m, a, b, q1, q2, q3;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> m;
    forn(i, m) {
        cin >> a >> b;
        g[a-1][b-1] = 1;
        g[b-1][a-1] = 1;
    }

    int pos[5], mask, el, maxmask = 1;

    forn(i, 5)
        maxmask *= base;
    forn(i, maxmask) {
        q1 = -1;
        q2 = -1;
        q3 = -1;
        mask = i;
        el = 0;
        ford(j, 5) {
            pos[j] = mask % base;
            mask /= base;
            if (pos[j]) el++;
        }
        if (el == 3) {
            forn(j, 5) {
                if (pos[j] && q1 == -1) {
                    q1 = j;
                    continue;
                }
                if (pos[j] && q2 == -1) {
                    q2 = j;
                    continue;
                }
                if (pos[j] && q3 == -1) {
                    q3 = j;
                    continue;
                }
            }
            if ((g[q1][q2] && g[q2][q3] && g[q1][q3]) || !(g[q1][q2] || g[q2][q3] || g[q1][q3])) {
                cout << "WIN" << endl;
                return 0;
            }
        }

    }

    cout << "FAIL" << endl;

    return 0;
}