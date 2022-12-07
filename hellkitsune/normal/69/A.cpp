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

int n, x, y, z;

int main() {
    x = y = z = 0;
    scanf("%d", &n);
    REP(i, n) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        x += a;
        y += b;
        z += c;
    }
    if (!x && !y && !z) printf("YES\n");
    else printf("NO\n");
    return 0;
}