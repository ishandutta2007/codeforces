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

const string name[] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
const int base = 3;
string s;
int k, n = 7, m, exper[3], cmd[3], pos[7], symp[7][7];
int ans[2], curr[2], a, b, mask, maxmask = 1;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> m;
    forn(i, m) {
        cin >> s;
        forn(j, n)
            if (s == name[j])
                a = j;
        cin >> s >> s;
        forn(j, n)
            if (s == name[j])
                b = j;
        symp[a][b] = 1;
    }

    forn(i, 3)
        cin >> exper[i];

    ans[0] = INF;
    ans[1] = -1;
    forn(i, n)
        maxmask *= base;
    forn(i, maxmask) {
        mask = i;
        ford(j, n) {
            pos[j] = mask % base;
            mask /= base;
        }

        forn(j, 3) cmd[j] = 0;
        forn(j, 7) cmd[pos[j]]++;
        if ((cmd[0] == 0) || (cmd[1] == 0) || (cmd[2] == 0)) continue;

        curr[0] = max(exper[0]/cmd[0], max(exper[1]/cmd[1], exper[2]/cmd[2]));
        curr[0] -= min(exper[0]/cmd[0], min(exper[1]/cmd[1], exper[2]/cmd[2]));
        curr[1] = 0;
        forn(j, n)
            forn(k, n)
                if ((symp[j][k]) && (pos[j] == pos[k]))
                    curr[1]++;

        if ((ans[0] > curr[0]) || ((ans[0] == curr[0]) && (ans[1] < curr[1]))) {
            ans[0] = curr[0];
            ans[1] = curr[1];
        }
    }

    cout << ans[0] << ' ' << ans[1] << endl;

    return 0;
}