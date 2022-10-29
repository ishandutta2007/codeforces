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
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 101000;

double n, r[2], w;

int main() {

        cin >> n >> r[0] >> r[1];
        if (r[0] < r[1]) {      
                cout << "NO";
                return 0;
        }
        if (abs(r[1] - r[0] / 2) < eps) {
                if (n <= 2)
                        cout << "YES";
                else
                        cout << "NO";
                return 0;
        }
        if (r[1] + eps > r[0] / 2) {
                if (abs(n - 1) < eps)
                        cout << "YES";
                else
                        cout << "NO";
                return 0;
        }
        w = asin(r[1] / (r[0] - r[1]));
        w *= 2;
        if (2 * pi / w >= n - eps)
                cout << "YES";
        else
                cout << "NO";

    return 0;
}