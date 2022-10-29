#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
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
const long double eps = 0.00000001;
const int INF = 1E9;
const int MAXN = 5000;

int open, w[30];
char c;

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

        open = 0;
        while (1) {
				scanf("%c", &c);
				if (c == '\n') break;
                scanf("%c", &c);
                if (c == '/') {
                        scanf("%c", &c);
                        open--;
                        forn(i, open) cout << "  ";
                        cout << '<' << '/' << c << '>';
                } else {
                        forn(i, open) cout << "  ";
                        cout << '<' << c << '>';
                        open++;
                }
                cout << endl;
                scanf("%c", &c);
        }

    return 0;
}