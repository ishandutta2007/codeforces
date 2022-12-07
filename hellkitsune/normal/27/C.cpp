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
int a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    int cur = 0, pos = -1;
    for (int i = 1; i < n; ++i) if (a[i] > a[i - 1]) {
        if (cur == 0) {
            cur = 1;
            pos = i;
        } else if (cur < 0) {
            cout << 3 << endl << pos << ' ' << i << ' ' << i + 1 << endl;
            return 0;
        }
    } else if (a[i] < a[i - 1]) {
        if (cur == 0) {
            cur = -1;
            pos = i;
        } else if (cur > 0) {
            cout << 3 << endl << pos << ' ' << i << ' ' << i + 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}