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

int n, m, s;
LL ans = 1;

void solve(int n) {
    int best = 0, sum = 0;
    for (int i = 0; i < min(s, n); ++i) {
        int cnt = 0;
        for (int j = i; j < n; j += s) {
            ++cnt;
        }
        if (cnt > best) {
            best = sum = cnt;
        } else if (cnt == best) {
            sum += cnt;
        }
    }
    ans *= sum;
}

int main() {
    cin >> n >> m >> s;
    solve(n);
    solve(m);
    cout << ans << endl;
    return 0;
}