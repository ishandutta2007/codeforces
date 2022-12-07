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
int ans[50];
int l, r;
LL m;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m, --m;
    l = 0, r = n - 1;
    for (LL i = n - 2; i >= 0; --i) {
        if ((1ll << i) & m) {
            ans[r--] = n - i - 1;
        } else {
            ans[l++] = n - i - 1;
        }
    }
    ans[l] = n;
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}