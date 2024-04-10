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
int ans[100][100];

int main() {
    scanf("%d%d", &n, &m);
    if (n + m <= 4) {
        if (n == 1 && m == 1) {
            cout << 1 << endl;
            return 0;
        }
        printf("-1\n");
        return 0;
    }
    int cur = n * m;
    if (cur % 2 == 0) --cur;
    if (n >= m) {
        REP(i, n) REP(j, m) {
            ans[i][j] = cur;
            if (cur - 2 == -1) {
                cur = n * m;
                if (cur % 2 == 1) --cur;
            } else {
                cur -= 2;
            }
        }
    } else {
        REP(j, m) REP(i, n) {
            ans[i][j] = cur;
            if (cur - 2 == -1) {
                cur = n * m;
                if (cur % 2 == 1) --cur;
            } else {
                cur -= 2;
            }
        }
    }
    REP(i, n) {
        REP(j, m) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}