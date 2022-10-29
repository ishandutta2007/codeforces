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
#define FORN(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define sqr(x) (x)*(x)
#define odd(x) (x % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E3+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int n, curr, z[2], c2[MAXN][MAXN], c5[MAXN][MAXN];
char w2[MAXN][MAXN], w5[MAXN][MAXN];
bool isz;

void restore2(int x, int y) {
    if (w2[x][y] != '0') {
        if (w2[x][y] == 'R') {
            restore2(x, y-1);
        } else {
            restore2(x-1, y);
        }
        printf("%c", w2[x][y]);
    }
}

void restore5(int x, int y) {
    if (w5[x][y] != '0') {
        if (w5[x][y] == 'R') {
            restore5(x, y-1);
        } else {
            restore5(x-1, y);
        }
        printf("%c", w5[x][y]);
    }
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    scanf("%d", &n);

    forn(i, n) {
        forn(j, n) {
            scanf("%d", &curr);
            if (curr == 0) {
                isz = 1;
                z[0] = i;
                z[1] = j;
                c2[i][j] = 1;
                c5[i][j] = 1;
            } else {
                while (curr % 2 == 0) {
                    curr /= 2;
                    c2[i][j]++;
                }
                while (curr % 5 == 0) {
                    curr /= 5;
                    c5[i][j]++;
                }
            }
        }
    }

    w2[0][0] = '0';
    w5[0][0] = '0';
    FORN(i, 1, n) {
        c2[i][0] += c2[i-1][0];
        w2[i][0] = 'D';
        c2[0][i] += c2[0][i-1];
        w2[0][i] = 'R';

        c5[i][0] += c5[i-1][0];
        w5[i][0] = 'D';
        c5[0][i] += c5[0][i-1];
        w5[0][i] = 'R';
    }

    FORN(i, 1, n) {
        FORN(j, 1, n) {
            if (c2[i-1][j] < c2[i][j-1]) {
                c2[i][j] += c2[i-1][j];
                w2[i][j] = 'D';
            } else {
                c2[i][j] += c2[i][j-1];
                w2[i][j] = 'R';
            }

            if (c5[i-1][j] < c5[i][j-1]) {
                c5[i][j] += c5[i-1][j];
                w5[i][j] = 'D';
            } else {
                c5[i][j] += c5[i][j-1];
                w5[i][j] = 'R';
            }
        }
    }

    if (isz && (min(c2[n-1][n-1], c5[n-1][n-1]) > 0)) {
        printf("%d\n", 1);
        forn(i, z[0])
            printf("%c", 'D');
        forn(i, n-1)
            printf("%c", 'R');
        forn(i, n-z[0]-1)
            printf("%c", 'D');
    } else {
        if (c2[n-1][n-1] < c5[n-1][n-1]) {
            printf("%d\n", c2[n-1][n-1]);
            restore2(n-1, n-1);
        } else {
            printf("%d\n", c5[n-1][n-1]);
            restore5(n-1, n-1);
        }
    }
/*
    forn(i, n) {
        forn(j, n) {
            printf("%d", c2[i][j]);
        }
        printf("\n");
    }
    forn(i, n) {
        forn(j, n) {
            printf("%d", c5[i][j]);
        }
        printf("\n");
    }

    forn(i, n) {
        printf("%s\n", w2[i]);
    }
    forn(i, n) {
        printf("%s\n", w5[i]);
    }
*/
    return 0;
}