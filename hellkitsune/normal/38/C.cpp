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
typedef long long LL;
typedef pair<int, int> PII;

int n, l;
int a[100];

int main() {
    cin >> n >> l;
    REP(i, n) cin >> a[i];
    int ans = 0;
    for (; ; ++l) {
        int cnt = 0;
        REP(i, n) cnt += a[i] / l;
        if (cnt == 0) break;
        ans = max(ans, cnt * l);
    }
    cout << ans << endl;
    return 0;
}