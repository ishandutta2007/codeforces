#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
const int N = 1e6;
int l[N], r[N];
char s[N];
int n, m, T;
int main()
{
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for ( int  i =1; i <= n ; i++) r[i] = 0;
        for ( int  i =1; i <= m ; i++) l[i] = 0;

        for (int i = 1; i <= n ; i ++)
            for (int j = 1; j <= m; j ++)  {
                scanf(" %c", &s[(i -1) * m + j]);
                l[j] += (s[(i - 1) * m + j] == '*');
                r[i] += (s[(i - 1) * m + j] == '*');
            }
        int ans = 1e6;
        for (int i = 1; i <= n;  i++ )
            for (int j = 1; j <= m ; j ++)
                ans = min(ans, n + m - 1 - (l[j] + r[i] -  (s[(i - 1) * m + j] == '*')));
        printf("%d\n", ans);
    }
    return 0;
}