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
bool vis[1000] = {};

int main() {
    scanf("%d", &n);
    vis[0] = true;
    int pos = 0;
    for (int k = 1; k <= 2 * n + 3; ++k) {
        pos = (pos + k) % n;
        vis[pos] = true;
    }
    REP(i, n) if (!vis[i]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}