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

int n, a[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) {
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
    }
    bool ok = true;
    REP(i, n - 1) if (a[i] != a[i + 1]) ok = false;
    if (ok) printf("Yes\n");
    else printf("No\n");
    return 0;
}