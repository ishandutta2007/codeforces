#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,w[999][999],a[999],b[999];
ll g = 0ll;

ll gcd(ll aa, ll bb) {
    return bb ? gcd(bb, aa % bb) : aa;
}

void fail() {
    printf("NO");
    exit(0);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            scanf("%d",&w[i][j]);
    }

    for (int i = 0; i < m; ++i)
        b[i] = w[0][i];
    for (int i = 1; i < n; ++i)
        a[i] = w[i][0] - w[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll cur = a[i] + b[j] - w[i][j];
            if (cur < 0) cur = -cur;
            g = gcd(g, cur);
        }
    }

    if (g) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((a[i] + b[j] + g + g + g) % g != ll(w[i][j])) fail();
            }
        }
    }

    printf("YES\n");
    if (g == 0) g = 1000000007;
    cout << g << endl;
    for (int i = 0; i < n; ++i)
        printf("%d ",int((a[i] + g + g + g) % g));
    printf("\n");
    for (int i = 0; i < m; ++i)
        printf("%d ",int((b[i] + g + g + g) % g));


    return 0;
}