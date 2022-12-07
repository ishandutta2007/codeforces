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

const int MX = 20000001;
bool p[MX] = {};
int n;
int ans[6000];

int main() {
    for (int i = 2; i < MX; ++i) p[i] = true;
    for (int i = 2; i < 10000; ++i) if (p[i]) {
        for (int j = i * i; j < MX; j += i) {
            p[j] = false;
        }
    }
    scanf("%d", &n);
    if (n == 1) {
        printf("-1\n");
        return 0;
    }
    if (n == 2) {
        printf("1 1\n");
        return 0;
    }
    REP(i, n) ans[i] = 1;
    int tot = n * (n + 1) / 2, val = -1;
    if (tot % 2 == 1) {
        if (p[tot - 2]) {
            ans[1] = 2;
            REP(i, n) printf("%d ", ans[i]);
            printf("\n");
            return 0;
        }
        ans[2] = 3;
        tot -= 3;
    }
    assert(tot % 2 == 0);
    for (int j = min(tot / 2, tot - 2); j >= 2; --j) {
        if (p[j] && p[tot - j]) {
            val = j;
            break;
        }
    }
    assert(val != -1);
    for (int i = n; i >= 1; --i) if (ans[i - 1] != 3 && i <= val) {
        val -= i;
        ans[i - 1] = 2;
    }
    assert(val == 0);
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}