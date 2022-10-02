#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>


using namespace std;
    

const int MaxN = 20;
const int MaxM = 150;
int n;
char s[MaxM][MaxN + 10];
long long d[(1 << MaxN)];
long double prob[MaxN + 10];
long double totalGuessed[MaxN + 10];


inline bool inMask(long long mask, int pos) {
    return (mask >> pos) & 1;
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    int m = strlen(s[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int same = 0;
            for (int k = 0; k < m; k++) {
                if (s[i][k] == s[j][k]) {
                    same |= (1 << k);
                }
            }
            d[same] |= (1LL << i);
        }
    }
    for (int mask = (1 << m) - 1; mask; mask--) {
        for (int i = 0; i < m; i++) {
            if (inMask(mask, i)) {
                d[mask ^ (1 << i)] |= d[mask];
            }   
        }
    }
    long double ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int moves = __builtin_popcount(mask) + 1;
        for (int i = 0; i < m; i++) {
            if (!inMask(mask, i)) {
                long long res = d[mask] ^ d[mask ^ (1 << i)];
                if (res == 0) {
                    continue;
                }
                int cntGuessed = __builtin_popcountll(res);
                totalGuessed[moves] += cntGuessed;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        long double val = totalGuessed[i] * i;
        for (int j = 0; j < i - 1; j++) {
            val *= (long double)(i - 1 - j) / (long double)(m - j);
        }
        ans += val / (long double)(m - i + 1);
    }
    ans /= (long double)(n);
    printf("%.15lf\n", (double)ans);
    return 0;
}