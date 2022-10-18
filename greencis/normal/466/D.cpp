#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007ll
using namespace std;

int n,h,a[2005],d[2005][2005];

int main()
{
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    if (a[1] == h || a[1] + 1 == h)
        d[1][0] = 1;
    if (a[1] + 1 == h)
        d[1][1] = 1;

    for (int i = 2; i <= n + 2; ++i) {
        for (int j = max(0, h - 1 - a[i]); j <= min(h - a[i], i); ++j) {
            d[i][j] = (d[i][j] + d[i-1][j]) % MOD;
            if (a[i] + j == h) {
                if (j > 0)
                    d[i][j] = (d[i][j] + d[i-1][j-1]) % MOD;
            } else if (a[i] + j + 1 == h) {
                d[i][j] = (d[i][j] + (d[i-1][j+1] * (long long)(j+1)) % MOD) % MOD;
                d[i][j] = (d[i][j] + (d[i-1][j] * (long long)(j)) % MOD) % MOD;
            }
        }
    }
    cout << d[n][0];

    return 0;
}