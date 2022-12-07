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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, a[100001], pos[100001];
int ans1[500000], ans2[500000], ansc = 0;
bool prime[100005];

void myswap(int x, int y) {
    swap(a[x], a[y]);
    ans2[ansc] = pos[a[x]] = x;
    ans1[ansc++] = pos[a[y]] = y;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    for (int i = 2; i <= n; ++i)
        prime[i] = true;
    for (int i = 2; i < sqrt(n) + 10; ++i)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
    for (int i = 1; i <= n; ++i)
        while (pos[i] > i) {
            int j;
            for (j = i; !prime[pos[i] - j + 1]; ++j);
            myswap(pos[i], j);
        }
    printf("%d\n", ansc);
    REP(i, ansc)
        printf("%d %d\n", ans1[i], ans2[i]);
    return 0;
}