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

bool p[3001];

int main() {
    p[1] = p[0] = false;
    for (int i = 2; i <= 3000; ++i) p[i] = true;
    for (int i = 2; i <= 3000; ++i) if (p[i]) {
        for (int j = i * i; j <= 3000; j += i)
            p[j] = false;
    }
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        int cur = i;
        int cnt = 0;
        for (int j = 2; j <= cur; ++j) if (p[j] && cur % j == 0) {
            cur /= j;
            while (cur % j == 0) cur /= j;
            ++cnt;
        }
        if (cnt == 2) ++ans;
    }
    cout << ans << '\n';
    return 0;
}