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

int n, cnt[100001], tot[100001];
const int INF = 1e9;

int main() {
    scanf("%d", &n);
    REP(z, n) {
        int x;
        scanf("%d", &x);
        int i, j;
        bool flag = true;
        for (i = 0; x > 0; ++i, x >>= 1) {
            ++cnt[x];
            tot[x] += i;
            if (flag) {
                int y = x << 1;
                for (j = 1; y <= 100000; ++j, y <<= 1) {
                    ++cnt[y];
                    tot[y] += i + j;
                }
            }
            flag = (x & 1) > 0;
        }
        ++cnt[0];
        tot[0] += i;
    }
    int best = INF;
    REP(i, 100001) if (cnt[i] == n) {
        best = min(best, tot[i]);
    }
    printf("%d\n", best);
    return 0;
}