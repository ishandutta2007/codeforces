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

int n, cur = 0;

int main() {
    scanf("%d", &n);
    REP(i, n - 1) {
        cur += i + 1;
        cur %= n;
        printf("%d ", cur + 1);
    }
    printf("\n");
    return 0;
}