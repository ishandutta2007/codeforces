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
int a[20];
bool b[5001] = {};

int main() {
    scanf("%d", &n);
    a[0] = 1, a[1] = 2;
    b[1] = b[2] = b[3] = true;
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j <= 1000; ++j) if (!b[j]) {
            bool ok = true;
            REP(k, i) if (b[j + a[k]]) {
                ok = false;
                break;
            }
            if (ok) {
                REP(k, i) b[j + a[k]] = true;
                b[j] = true;
                a[i] = j;
                break;
            }
        }
    }
    REP(i, n) {
        REP(j, n) if (j == i) {
            printf("0 ");
        } else {
            printf("%d ", a[i] + a[j]);
        }
        printf("\n");
    }
    return 0;
}