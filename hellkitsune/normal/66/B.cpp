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

int n;
int a[1000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int ans = 1;
    REP(i, n) {
        int cnt = 1;
        for (int j = i - 1; j >= 0 && a[j] <= a[j + 1]; --j) {
            ++cnt;
        }
        for (int j = i + 1; j < n && a[j] <= a[j - 1]; ++j) {
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}