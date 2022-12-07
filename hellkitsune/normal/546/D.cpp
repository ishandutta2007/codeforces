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

int t, a, b;
int cnt[5000001] = {}, pr[5000001] = {};

int main() {
    cnt[1] = 0;
    for (int i = 2; i <= 5000000; ++i) {
        if (pr[i] == 0) {
            for (int j = 2 * i; j <= 5000000; j += i)
                pr[j] = i;
            cnt[i] = 1;
        } else {
            cnt[i] = cnt[i / pr[i]] + 1;
        }
    }
    for (int i = 2; i <= 5000000; ++i)
        cnt[i] += cnt[i - 1];
    scanf("%d", &t);
    REP(test, t) {
        scanf("%d%d", &a, &b);
        printf("%d\n", cnt[a] - cnt[b]);
    }
    return 0;
}