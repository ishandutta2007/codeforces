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

int n, a[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    int oc = 0, ec = 0;
    REP(i, n) if (a[i] % 2 == 0) ++ec;
    else ++oc;
    if (ec == 1) {
        REP(i, n) if (a[i] % 2 == 0) cout << i + 1 << endl;
    } else {
        REP(i, n) if (a[i] % 2 == 1) cout << i + 1 << endl;
    }
    return 0;
}