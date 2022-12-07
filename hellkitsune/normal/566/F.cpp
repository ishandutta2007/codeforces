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
bool a[1000001] = {};
int d[1000001], pr[1000001];
const int MX = 1000001;
int dp[1000001] = {};

int main() {
    REP(i, MX) d[i] = -1;
    for (int i = 2; i < MX; ++i) if (d[i] == -1) {
        d[i] = i;
        pr[i] = 1;
        if (i > 10000) continue;
        for (int j = i * i; j < MX; j += i) {
            d[j] = i;
            pr[j] = j / i;
        }
    }
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        a[x] = true;
    }
    for (int i = MX - 1; i >= 1; --i) {
        if (a[i]) ++dp[i];
        if (i == 1) break;
        if (dp[i]) {
            for (int x = i; x > 1; x = pr[x]) {
                int j = i / d[x];
                dp[j] = max(dp[j], dp[i]);
            }
        }
    }
    printf("%d\n", dp[1]);
    return 0;
}