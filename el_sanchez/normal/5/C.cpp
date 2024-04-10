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

const int MAXN = (int)1E6+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int n, d[MAXN], maxs, num;
char w[MAXN];
string s;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%s", &w);
    s = w;
    n = s.length();

    d[n] = 0;
    d[n-1] = 0;
    ford(i, n-1) {
        if (s[i] == ')')
            d[i] = 0;
        else { //if ((
            if (s[i+1] == '(') {
                if (s[i + 1 + d[i+1]] == ')')
                    d[i] = d[i+1] + 2 + d[i + 1 + d[i+1] + 1];
                else
                    d[i] = 0;
            } else // if ()
                d[i] = d[i+2] + 2;
        }
    }

    maxs = -1;
    forn(i, n) {
        if (d[i] > maxs) {
            maxs = d[i];
            num = 0;
        }
        if (d[i] == maxs)
            num++;
    }

    if (maxs != 0)
        printf("%d %d", maxs, num);
    else
        printf("0 1");

    return 0;
}