#include <cstdio>
#include <cmath>
#include <cstring>
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

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n < 4) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n & 1) {
        cout << "5 + 3 = 8\n";
        cout << "4 - 2 = 2\n";
        cout << "2 + 1 = 3\n";
        cout << "3 * 8 = 24\n";
        for (int k = 6; k < n; k += 2) {
            cout << k + 1 << " - " << k << " = " << "1\n";
            cout << "24 * 1 = 24" << "\n";
        }
    } else {
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        for (int k = 5; k < n; k += 2) {
            cout << k + 1 << " - " << k << " = " << "1\n";
            cout << "24 * 1 = 24" << "\n";
        }
    }
    return 0;
}