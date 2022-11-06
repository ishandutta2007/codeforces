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

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

int M[64][64];

int main(int argc, char ** argv)
{
    int n;

    scanf("%d", &n);
    
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            scanf("%d", &M[y][x]);

    int half = (n+1)/2;
    int best = -1000000000;

    for (int mask = 0; mask < (1<<half); mask++) {
        int ret = 0;

        for (int x = 0; x < half-1; x++)
            if (mask&(1<<x))
                for (int y = half-1; y < n; y++) {
                    M[y][x] = -M[y][x];
                    M[y][x+half] = -M[y][x+half];
                }
        if (mask&(1<<(half-1))) {
            for (int x = half-1; x < n; x++)
                for (int y = half-1; y < n; y++)
                    M[y][x] = -M[y][x];
        }

        for (int x = 0; x < n; x++)
            ret += M[half-1][x];

        for (int y = 0; y < half-1; y++) {
            int linebest = -1000000000;

            for (int rep = 0; rep < 2; rep++) {
                int lineval = 0;

                for (int x = 0; x < half-1; x++) {
                    int sum = M[y][x] + M[y][x+half] +
                        M[y+half][x] + M[y+half][x+half];
                    lineval += max(sum, -sum);
                }
                lineval += M[y][half-1] + M[y+half][half-1];

                linebest = max(linebest, lineval);

                for (int x = half-1; x < n; x++) {
                    M[y][x] = -M[y][x];
                    M[y+half][x] = -M[y+half][x];
                }
            }

            ret += linebest;
        }

        for (int x = 0; x < half-1; x++)
            if (mask&(1<<x))
                for (int y = half-1; y < n; y++) {
                    M[y][x] = -M[y][x];
                    M[y][x+half] = -M[y][x+half];
                }
        if (mask&(1<<(half-1))) {
            for (int x = half-1; x < n; x++)
                for (int y = half-1; y < n; y++)
                    M[y][x] = -M[y][x];
        }

        best = max(best, ret);
    }

    printf("%d\n", best);

    return 0;
}