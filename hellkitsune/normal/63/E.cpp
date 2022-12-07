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

bool d[1 << 19] = {};
int sz[15] = {3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3};
int pos[15][5] = {
    {0, 1, 2, -1, -1},
    {3, 4, 5, 6, -1},
    {7, 8, 9, 10, 11},
    {12, 13, 14, 15, -1},
    {16, 17, 18, -1, -1},
    {0, 3, 7, -1, -1},
    {1, 4, 8, 12, -1},
    {2, 5, 9, 13, 16},
    {6, 10, 14, 17, -1},
    {11, 15, 18, -1, -1},
    {2, 6, 11, -1, -1},
    {1, 5, 10, 15, -1},
    {0, 4, 9, 14, 18},
    {3, 8, 13, 17, -1},
    {7, 12, 16, -1, -1}
};

char s[5];

int main() {
    REP(mask, 1 << 19) if (!d[mask]) {
        REP(i, 15) REP(from, sz[i]) {
            int nmask = mask;
            for (int to = from; to < sz[i]; ++to) if (mask & (1 << pos[i][to])) {
                break;
            } else {
                nmask |= 1 << pos[i][to];
                d[nmask] = true;
            }
        }
    }
    int mask = 0;
    REP(i, 19) {
        scanf("%s", s);
        if (s[0] == 'O') mask |= 1 << i;
    }
    if (d[mask]) printf("Karlsson\n");
    else printf("Lillebror\n");
    return 0;
}