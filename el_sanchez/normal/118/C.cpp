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

int i, n, k, ck, c[10], sn[10];
string s, gs[10];

bool compare(int a, int b) {
    if (abs(a - i) != abs(b - i))
        return abs(a - i) < abs(b - i);
    return (a > b);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

    scanf("%d%d\n", &n, &k);
    cin >> s;
    forn(q, 10)
        sn[q] = q;

    for (i = 0; i <= 9; i++) {
        sort(sn, sn + 10, compare);
        ck = k;
        gs[i] = s;

        forn(j, 10) {
            if (sn[j] > i) {
                forn(l, n) {
                    if (ck == 0) break;
                    if (char(sn[j] + '0') == gs[i][l]) {
                        gs[i][l] = i + '0';
                        c[i] += abs(i - sn[j]);
                        ck--;
                    }
                }
            } else {
                ford(l, n) {
                    if (ck == 0) break;
                    if (char(sn[j] + '0') == gs[i][l]) {
                        gs[i][l] = i + '0';
                        c[i] += abs(i - sn[j]);
                        ck--;
                    }
                }
            }
            if (ck == 0) break;
        }
        //cerr << gs[i] << endl;
    }

    ck = 0;
    forn(i, 10)
        if (c[ck] > c[i] || c[ck] == c[i] && gs[ck] > gs[i])
            ck = i;
    cout << c[ck] << endl;
    cout << gs[ck] << endl;

    return 0;
}