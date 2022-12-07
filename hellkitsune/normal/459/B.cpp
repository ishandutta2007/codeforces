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

int n, b[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> b[i];
    sort(b, b + n);
    int l = 1, r = n - 2;
    while (l < n && b[l] == b[0]) ++l;
    if (l == n) {
        cout << "0 " << ((LL)n * (n - 1ll)) / 2ll << '\n';
        return 0;
    }
    while (r >= 0 && b[r] == b[n - 1]) --r;
    cout << b[n - 1] - b[0] << ' ' << (LL)l * (n - 1ll - r) << '\n';
    return 0;
}