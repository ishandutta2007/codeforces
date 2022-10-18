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
using namespace std;

int n,m,k;
long long a[9999],sum[9999];
long long d[5005][5005]; /// pos/cnt

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    for (int i = 0; i < 5005; ++i)
        for (int j = 1; j < 5005; ++j)
            d[i][j] = -9e18;

    for (int i = m; i <= n; ++i) {
        long long cur = sum[i] - sum[i-m];
        for (int j = 0; j <= k; ++j) {
            d[i][j+1] = max(d[i][j+1], d[i-m][j] + cur);
            d[i][j] = max(d[i][j], d[i-1][j]);
        }
    }
    cout << d[n][k];

    return 0;
}