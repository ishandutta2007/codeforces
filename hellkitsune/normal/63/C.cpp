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
set<int> g, g2;

bool used[10] = {};
bool u[10];
int a[4], d[4], x, cntGood, cntWrong;
bool flag = false;

void gen(int pos) {
    if (pos == 4) {
        int res = 0;
        REP(i, 4) res = 10 * res + a[i];
        if (flag) {
            int curGood = 0, curWrong = 0;
            REP(i, 4) if (a[i] == d[i]) {
                ++curGood;
            }
            REP(i, 10) if (used[i] && u[i]) {
                ++curWrong;
            }
            curWrong -= curGood;
            if (curGood == cntGood && curWrong == cntWrong && g.count(res)) {
                g2.insert(res);
            }
        } else {
            g.insert(res);
        }
        return;
    }
    REP(i, 10) if (!used[i]) {
        used[i] = true;
        a[pos] = i;
        gen(pos + 1);
        used[i] = false;
    }
}

int main() {
    gen(0);
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d%d", &x, &cntGood, &cntWrong);
        int tmp = x;
        for (int i = 3; i >= 0; --i) {
            d[i] = tmp % 10;
            tmp /= 10;
        }
        REP(i, 10) u[i] = false;
        REP(i, 4) u[d[i]] = true;
        flag = true;
        g2.clear();
        gen(0);
        g = g2;
    }
    if ((int)g.size() == 0) printf("Incorrect data\n");
    else if ((int)g.size() == 1) {
        int x = *g.begin();
        for (int i = 3; i >= 0; --i) {
            d[i] = x % 10;
            x /= 10;
        }
        REP(i, 4) printf("%d", d[i]);
        printf("\n");
    } else {
        printf("Need more data\n");
    }
    return 0;
}