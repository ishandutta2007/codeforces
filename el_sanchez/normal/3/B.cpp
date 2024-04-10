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
#define all(x) (x).begin(), (x).end()
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

int i, j, n, m, sum, t[2], l[2];
vector<pair<int, int> > p[2];

void printw(int sum, int x, int y) {
    printf("%d\n", sum);
    forn(i, x)
        printf("%d ", p[0][i].se + 1);
    forn(i, y)
        printf("%d ", p[1][i].se + 1);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d\n", &n, &m);
    forn(i, n) {
        scanf("%d %d\n", &t[0], &t[1]);
        p[t[0]-1].push_back(make_pair(t[1], i));
        l[t[0]-1]++;
    }
    sort(all(p[0])); reverse(all(p[0])); p[0].push_back(make_pair(0, 0));
    sort(all(p[1])); reverse(all(p[1])); p[1].push_back(make_pair(0, 0));

    i = 0; j = 0;
    while (((i < l[0]) || (j < l[1])) && (m > 1)) {
        if (2 * p[0][i].fi >= p[1][j].fi) {
            sum += p[0][i].fi;
            i++;
            m--;
        } else {
            sum += p[1][j].fi;
            j++;
            m -= 2;
        }
    }

    if (m == 1) {
        if ((i != 0) && (j != l[1]) && (p[1][j].fi - p[0][i-1].fi > p[0][i].fi)) {
            printw(sum - p[0][i-1].fi + p[1][j].fi, i - 1, j + 1);
            return 0;
        }
        if (i != l[0]) {
            printw(sum + p[0][i].fi, i + 1, j);
            return 0;
        }
        printw(sum, i, j);
    } else
        printw(sum, i, j);

    return 0;
}