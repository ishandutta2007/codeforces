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

int n, h[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    h[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    LL e = 0, ans = 0;
    REP(i, n) {
        if (h[i + 1] - h[i] > e) {
            ans += h[i + 1] - h[i] - e;
            e = 0;
        } else {
            e += h[i] - h[i + 1];
        }
    }
    cout << ans << endl;
    return 0;
}