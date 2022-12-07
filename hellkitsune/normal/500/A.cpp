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

int n, t;
int a[100000];
bool b[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> t, --t;
    REP(i, n - 1) cin >> a[i];
    REP(i, n) b[i] = false;
    b[0] = true;
    REP(i, n - 1) if (b[i])
        b[i + a[i]] = true;
    if (b[t]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}