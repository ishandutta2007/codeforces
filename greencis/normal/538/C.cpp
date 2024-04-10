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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,m,d[1001005],h[1001005];

void fail() {
    printf("IMPOSSIBLE");
    exit(0);
}

int main()
{
    int ans = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d",&d[i],&h[i]);

    ans = max(ans, max(h[0] + d[0] - 1, h[m-1] + n - d[m-1]));

    for (int i = 1; i < m; ++i) {
        if (d[i] - d[i-1] < abs(h[i] - h[i-1])) fail();
        ans = max(ans, max(h[i-1], h[i]));
        if (h[i-1] < h[i]) {
            int w1 = d[i-1] + h[i] - h[i-1];
            ans = max(ans, h[i] + abs(d[i] - w1) / 2);
        } else {
            int w2 = d[i] - (h[i-1] - h[i]);
            ans = max(ans, h[i-1] + abs(d[i-1] - w2) / 2);
        }
    }

    printf("%d",ans);

    return 0;
}