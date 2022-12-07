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

int n, a, b, c;

int main() {
    cin >> n >> a >> b >> c;
    int ans = 0;
    REP(i, b + 1) REP(j, c + 1) {
        int cnt = n - i - 2 * j;
        if (cnt >= 0 && 2 * cnt <= a) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}