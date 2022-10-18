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

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

ull ans = 1ull;
int n,a[1005],u[1005],looped[1005];

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);

    int curmove = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 400; ++j) u[j] = 0;
        int cur = i;
        do {
            if (u[cur]) {
                int oldv = cur;
                do {
                    looped[cur] = 1;
                    cur = a[cur];
                } while (cur != oldv);

                ans = lcm(ans, ull(curmove - u[oldv]));
                ++curmove;

                break;
            } else {
                u[cur] = curmove++;
                cur = a[cur];
            }
        } while (1);
    }

    int maxchain = 0;

    for (int i = 1; i <= n; ++i) {
        int curmax = 0;
        int cur = i;
        while (!looped[cur]) {
            ++curmax;
            cur = a[cur];
        }
        maxchain = max(maxchain, curmax);
    }

    ull ans2 = ans;
    while (ans2 < ull(maxchain)) ans2 += ans;
    cout << ans2;

    return 0;
}