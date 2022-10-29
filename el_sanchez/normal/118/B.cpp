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

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = 1000000000;
const int MAXN = 100100;

int n;

void go(int v, int k, int spaces) {
    if (spaces > 0) {
        cout << "  ";
        go(v, k, spaces - 1);
    } else {
        if (k == v) {
            cout << k;
        } else {
            cout << v << ' ';
            go(v + 1, k, 0);
            cout << ' ' << v;
        }
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    cin >> n;
    forn(i, n + 1) {
        go(0, i, n - i);
        printf("\n");
    }
    ford(i, n) {
        go(0, i, n - i);
        printf("\n");
    }

    return 0;
}