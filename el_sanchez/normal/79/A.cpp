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

int a, b;
bool ciel = 1;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> a >> b;
    while ((100 * a + 10 * b >= 220) && (b >= 2)) {
        if (ciel) {
            if (a >= 2) {
                a -= 2;
                b -= 2;
            } else {
                if (a == 1) {
                    a--;
                    b -= 12;
                } else {
                    b -= 22;
                }
            }
        } else {
            if (b >= 22) {
                b -= 22;
            } else {
                if (b >= 12) {
                    a--;
                    b -= 12;
                } else {
                    a -= 2;
                    b -= 2;
                }
            }
        }
        ciel = !ciel;
    }

    if (!ciel)
        cout << "Ciel";
    else
        cout << "Hanako";

    fclose(stdin);
    fclose(stdout);

    return 0;
}