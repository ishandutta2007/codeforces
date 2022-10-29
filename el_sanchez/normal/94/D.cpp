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

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = (int)1E9;
const int MAXN = (int)1000100;
const double eps = 1e-9;

using namespace std;

double d[100][100];
int col[100], id[100][100];

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, w, m, milk, currk = 0;
    cin >> n >> w >> m;
    double allw = n * w;
    double kw = allw / m, currw, currb = 0;
    forn(i, n) {
        milk = 0;
        currw = w;
        while (currw > eps) {
            if (currb + currw > kw) {
                currw -= kw - currb;
                //add bottle
                milk++;
                id[currk][col[currk]] = i;
                d[currk][col[currk]] = kw - currb;
                currb = 0;
                col[currk]++;
                currk++;
            } else {
                milk++;
                currb += currw;
                id[currk][col[currk]] = i;
                d[currk][col[currk]] = currw;
                col[currk]++;
                currw = 0;
                if (kw - currb < eps) {
                    currk++;
                    currb = 0;
                }
            }
        }
        if (milk >= 3) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    forn(i, m) {
        forn(j, col[i])
            printf("%d %.6f ", id[i][j] + 1, d[i][j]);
        cout << endl;
    }

    return 0;
}