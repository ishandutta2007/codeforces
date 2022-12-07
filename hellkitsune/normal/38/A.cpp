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

int n, d[100];
int a, b;

int main() {
    scanf("%d", &n);
    REP(i, n - 1) scanf("%d", d + i);
    scanf("%d%d", &a, &b), --a, --b;
    int ans = 0;
    while (a < b) {
        ans += d[a];
        ++a;
    }
    printf("%d\n", ans);
    return 0;
}