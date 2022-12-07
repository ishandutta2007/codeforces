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

int cnt[101] = {};
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    int ans = 0;
    while (cnt[k] < n) {
        for (int i = k - 1; i > 0; --i) if (cnt[i]) {
            --cnt[i];
            ++cnt[i + 1];
        }
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}