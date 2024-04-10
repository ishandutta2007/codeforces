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
const int INF = (int)1E9;
const int MAXN = (int)11000;

using namespace std;

int d[MAXN];

int dfs(int v) {
    if (d[v] == -1) return 1;
    return dfs(d[v]) + 1;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, mx = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }

    for (int i = 1; i <= n; i++) {
        mx = max(mx, dfs(i));
    }
    cout << mx << endl;

    return 0;
}