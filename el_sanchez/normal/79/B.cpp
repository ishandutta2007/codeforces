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
const int MAXN = (int)1100;

int n, m, k, t, x, y, nw;
int w[MAXN][2];

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d %d %d\n", &n, &m, &k, &t);
    forn(i, k)
        scanf("%d %d\n", &w[i][0], &w[i][1]);
    forn(i, t) {
        scanf("%d %d\n", &x, &y);
        nw = 0;
        forn(j, k) {
            if ((w[j][0] < x) || ((w[j][0] == x) && (w[j][1] < y)))
                nw++;
            if ((w[j][0] == x) && (w[j][1] == y))
                nw = -INF;
        }
        if (nw < 0)
            cout << "Waste" << endl;
        else {
            nw = ((x - 1) * m + y - nw) % 3;
            switch (nw) {
                case 0: {cout << "Grapes" << endl; break;}
                case 1: {cout << "Carrots" << endl; break;}
                case 2: {cout << "Kiwis" << endl; break;}
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}