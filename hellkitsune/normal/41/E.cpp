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
    printf("%d\n", n / 2 * (n - n / 2));
    int from = n / 2;
    REP(i, from) for (int j = from; j < n; ++j) {
        printf("%d %d\n", i + 1, j + 1);
    }
    return 0;
}