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

long long n,a[101005],p[101005],d[101005][2];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++p[a[i]];
    }

    d[1][0] = 0;
    d[1][1] = 1ll * p[1];
    for (int i = 2; i <= 100000; ++i) {
        d[i][0] = max(d[i-1][0],d[i-1][1]);
        d[i][1] = i * p[i] + max(d[i-2][0],d[i-2][1]);
    }

    cout << max(d[100000][0],d[100000][1]);

    return 0;
}