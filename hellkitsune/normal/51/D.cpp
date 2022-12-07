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
int a[100000], z;
int b[100000];

bool solve(int ind) {
    REP(i, n - 1) if (i < ind) {
        b[i] = a[i];
    } else {
        b[i] = a[i + 1];
    }
    REP(i, n - 3) if (b[i + 2] * b[i] != b[i + 1] * b[i + 1]) {
        return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), z += a[i] == 0;
    if (z) {
        int nz = 0;
        for (int i = 1; i < n; ++i) {
            nz += a[i] != 0;
        }
        if (nz > 2) nz = 2;
        if (z == 1) {
            REP(i, n - 1) if (a[i] == 0) {
                swap(a[i], a[i + 1]);
            }
            --n;
            int cur = 1;
            REP(i, n - 2) if (a[i + 2] * a[i] != a[i + 1] * a[i + 1]) {
                cur = 2;
                break;
            }
            nz = min(nz, cur);
        }
        printf("%d\n", nz);
        return 0;
    }
    REP(i, n - 2) if (a[i] * a[i + 2] != a[i + 1] * a[i + 1]) {
        if (solve(i) || solve(i + 1) || solve(i + 2)) {
            printf("1\n");
        } else {
            printf("2\n");
        }
        return 0;
    }
    printf("0\n");
    return 0;
}