#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)

typedef long long int64;

using namespace std;

const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;
const int MAXN = (int)110;

bool good;
int n, m;
char a[MAXN][MAXN];

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d\n", &n, &m);
    forn(i, n) {
        forn(j, m)
            scanf("%c", &a[i][j]);
        scanf("\n");
    }

    forn(i, n)
        forn(j, m) {
            good = 1;
            forn(k, n)
                if ((i != k) && (a[i][j] == a[k][j]))
                    good = 0;
            forn(k, m)
                if ((j != k) && (a[i][j] == a[i][k]))
                    good = 0;
            if (good)
                printf("%c", a[i][j]);
        }

    fclose(stdin);
    fclose(stdout);

    return 0;
}