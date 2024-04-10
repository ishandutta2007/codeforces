#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int64 INF = 1000000000;
const int MAXN = (int)11000;

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int64 a, b, md;
    cin >> a >> b >> md;
    if (b >= (md - 1)) {
        printf("2\n");
        return 0;
    }
    int64 res, wh = min(md, a), cmod;
    for (int64 i = 0; i <= wh; i++) {
        res = INF * i;
        cmod = res % md;
        if ((cmod != 0) && (cmod + b < md)) {
            printf("1 %09I64d\n", i);
            return 0;
        }
    }

    printf("2\n");
    return 0;
}