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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string a;

int main() {
    cin >> a;
    n = (int)a.length();
    int d = a[n - 1] - '0';
    REP(i, n - 1) {
        int dig = a[i] - '0';
        if (dig % 2 == 0 && dig < d) {
            swap(a[i], a[n - 1]);
            cout << a << endl;
            return 0;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        int dig = a[i] - '0';
        if (dig % 2 == 0) {
            swap(a[i], a[n - 1]);
            cout << a << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}