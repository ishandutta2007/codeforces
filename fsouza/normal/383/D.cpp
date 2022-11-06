#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

const int maxs = 10000, mod = 1000000007;
int _nway[2][2*maxs+1]; int &nway(int now, int s) {return _nway[now][s + maxs];}

void add(int &v, int x) {v += x; if (v >= mod) v -= mod;}

int main(int argc, char ** argv)
{
        int n, result = 0;

        scanf("%d", &n);

        int now = 0;

        for (int s = -maxs; s <= maxs; s++) nway(now, s) = 0;

        for (int i = 0; i < n; i++) {
                int v;
                scanf("%d", &v);

                for (int s = -maxs; s <= maxs; s++) nway(!now, s) = 0;
                for (int s = -maxs; s <= maxs; s++) {
                        if (s-v >= -maxs) add(nway(!now, s-v), nway(now, s));
                        if (s+v <= +maxs) add(nway(!now, s+v), nway(now, s));
                }
                add(nway(!now, -v), 1);
                add(nway(!now, +v), 1);
                now = !now;

                add(result, nway(now, 0));
        }

        printf("%d\n", result);

        return 0;
}