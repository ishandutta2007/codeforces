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

#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E5+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, p = 0;
    char x, t[110][110];
    map<char, int> a;
    scanf("%d %d %c\n", &n, &m, &x);
    forn(i, n) {
        forn(j, m)
            scanf("%c", &t[i][j]);
        scanf("\n");
    }

    a['.'] = 0;
    a[x] = 0;
    forn(i, n)
        forn(j, m)
            if (t[i][j] == x) {
                if ((i-1 >= 0) && (a.find(t[i-1][j]) == a.end())) {
                    p++;
                    a[t[i-1][j]] = 0;
                }
                if ((i+1 < n) && (a.find(t[i+1][j]) == a.end())) {
                    p++;
                    a[t[i+1][j]] = 0;
                }
                if ((j-1 >= 0) && (a.find(t[i][j-1]) == a.end())) {
                    p++;
                    a[t[i][j-1]] = 0;
                }
                if ((j+1 < m) && (a.find(t[i][j+1]) == a.end())) {
                    p++;
                    a[t[i][j+1]] = 0;
                }
            }

    printf("%d", p);

    return 0;
}