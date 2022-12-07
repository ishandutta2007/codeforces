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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int k;

int main() {
    scanf("%d", &k);
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            int a = i * j;
            if (a / k > 0) printf("%d", a / k);
            printf("%d", a % k);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}