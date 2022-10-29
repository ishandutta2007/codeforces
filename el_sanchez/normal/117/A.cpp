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

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, a, b, c, t, cur, ans;
    bool dir;
    scanf("%d%d\n", &n, &m);
    forn(i, n) {
        scanf("%d%d%d\n", &a, &b, &c);

        ans = c;
        t = c % (2 * m - 2);
        dir = (t < m - 1);
        if (dir)
            cur = t + 1;
        else
            cur = (2 * m - 2 - t + 1);

        if (a < b) { //need up
            if (dir) { //goes up
                if (cur > a)
                    ans += ((m - cur) + (m - 1) + (a - 1));
                else
                    ans += (a - cur);
            } else { //goes down
                ans += ((cur - 1) + (a - 1));
            }
            ans += (b - a);
        }
        if (a > b) { //needs down
            if (!dir) { //goes down
                if (cur < a)
                    ans += ((cur - 1) + (m - 1) + (m - a));
                else
                    ans += (cur - a);
            } else { //goes up
                ans += ((m - cur) + (m - a));
            }
            ans += (a - b);
        }
        printf("%d\n", ans);
    }

    return 0;
}