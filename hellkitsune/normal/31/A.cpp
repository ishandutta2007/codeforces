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
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) REP(j, n) if (j != i) REP(k, n) if (k != i && k != j) {
        if (a[i] == a[j] + a[k]) {
            cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}