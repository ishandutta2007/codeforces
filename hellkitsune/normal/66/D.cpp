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

int main() {
    scanf("%d", &n);
    if (n == 2) {
        printf("-1\n");
        return 0;
    }
    printf("6\n");
    LL p2 = 2, p3 = 3;
    REP(i, n - 1) {
        if (!(i & 1)) {
            printf("%I64d\n", p2 * 5);
            p2 *= 2;
        } else {
            printf("%I64d\n", p3 * 5);
            p3 *= 3;
        }
    }
    return 0;
}