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

int n, x[100], d[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> x[i] >> d[i];
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}