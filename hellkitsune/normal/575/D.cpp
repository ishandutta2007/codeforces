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

int main() {
    printf("2000\n");
    for (int i = 1; i <= 1000; ++i) {
        printf("%d %d %d %d\n", i, 1, i, 2);
    }
    for (int i = 1000; i >= 1; --i) {
        printf("%d %d %d %d\n", i, 1, i, 2);
    }
    return 0;
}