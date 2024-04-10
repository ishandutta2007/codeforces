#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
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

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, a, b, ta, tb, sa, sb;
    cin >> n >> m >> a >> b;
    ta = (a - 1) % m + 1;
    tb = (b - 1) % m + 1;
    sa = (a - 1) / m + 1;
    sb = (b - 1) / m + 1;
    if (ta < tb) {
        if ((ta == 1) && (tb == m) || (ta == 1) && (b == n) || (sa == sb)) {
            cout << 1 << endl;
            return 0;
        }
        if ((ta == 1) || (tb == m) || (b == n) || (sa + 1 == sb)) {
            cout << 2 << endl;
            return 0;
        }
        cout << 3 << endl;
        return 0;
    }

    if (ta == tb) {
        if ((m == 1) || (a == b) || (ta == 1) && (b == n)) {
            cout << 1 << endl;
            return 0;
        }
        if ((ta == 1) || (tb == m) || (b == n) || (sa + 1 == sb)) {
            cout << 2 << endl;
            return 0;
        }
        cout << 3 << endl;
        return 0;
    }

    if ((sa + 1 == sb) || (tb + 1 == ta) || (b == n))
        cout << 2 << endl;
    else
        cout << 3 << endl;

    return 0;
}