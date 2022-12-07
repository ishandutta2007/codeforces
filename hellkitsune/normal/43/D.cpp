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

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 2) {
        printf("0\n1 1\n1 2\n1 1\n");
        return 0;
    }
    if (n == 2 && m == 1) {
        printf("0\n1 1\n2 1\n1 1\n");
        return 0;
    }
    if (n * m % 2 == 1 || n == 1 || m == 1) {
        printf("%d\n%d %d %d %d\n", 1, n, m, 1, 1);
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                for (int j = 1; j <= m; ++j) printf("%d %d\n", i, j);
            } else {
                for (int j = m; j > 0; --j) printf("%d %d\n", i, j);
            }
        }
        printf("%d %d\n", 1, 1);
    } else if (n % 2 == 0) {
        printf("0\n1 1\n");
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                for (int j = 2; j <= m; ++j) printf("%d %d\n", i, j);
            } else {
                for (int j = m; j > 1; --j) printf("%d %d\n", i, j);
            }
        }
        for (int i = n; i > 0; --i) printf("%d %d\n", i, 1);
    } else {
        printf("0\n1 1\n");
        for (int j = 1; j <= m; ++j) {
            if (j % 2 == 1) {
                for (int i = 2; i <= n; ++i) printf("%d %d\n", i, j);
            } else {
                for (int i = n; i > 1; --i) printf("%d %d\n", i, j);
            }
        }
        for (int j = m; j > 0; --j) printf("%d %d\n", 1, j);
    }
    return 0;
}