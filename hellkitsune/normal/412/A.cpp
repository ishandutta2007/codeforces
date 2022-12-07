#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
string s;

int main() {
    cin >> n >> m >> s;
    if (m - 1 < n - m) {
        while (m > 1) {
            cout << "LEFT\n";
            --m;
        }
        REP(i, n) {
            cout << "PRINT " << s[i] << "\n";
            if (i != n - 1)
                cout << "RIGHT\n";
        }
    } else {
        while (m < n) {
            cout << "RIGHT\n";
            ++m;
        }
        REP(i, n) {
            cout << "PRINT " << s[n - 1 - i] << "\n";
            if (i != n - 1)
                cout << "LEFT\n";
        }
    }
    return 0;
}