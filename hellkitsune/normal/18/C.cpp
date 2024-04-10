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
int a[100000];
LL sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) sum += a[i];
    if (sum % 2 != 0) {
        cout << "0\n";
        return 0;
    }
    sum /= 2;
    LL cur = 0;
    int ans = 0;
    REP(i, n - 1) {
        cur += a[i];
        if (cur == sum) ++ans;
    }
    cout << ans << endl;
    return 0;
}