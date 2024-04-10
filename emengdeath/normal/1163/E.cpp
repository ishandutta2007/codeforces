#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;
const int N =1e6 + 1;
int s[N], v[N], ans[N];
int n;
pair<int, int>f[N];
map<int, int>help;
bool work(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n ; i ++)
        if (s[i] >= (1 << x))
            f[i]=make_pair(0, 0);
        else
            f[i] = make_pair(s[i], s[i]);
    for (int i = 1; i <= x ; i ++)
    {
        if (!(f[i].first & (1 << (i - 1))))
        {
            for (int j =  i + 1; j <= n ; j ++ )
                if (f[j].first & (1 << (i - 1)))
                {
                    swap(f[i] ,f[j]);
                    break;
                }
        }
        if (!(f[i].first & (1 << (i - 1)))) return 0;
        for (int j = i + 1 ; j <= n; j ++)
            if (f[j].first & (1 << (i - 1)))
            {
                f[j].first ^= f[i].first;
            }
    }
    cnt = x;
    return 1;
}
void build(int x)
{
    if (x == 0)
    {
        v[1] = 0;
        return;
    }
    build(x  -  1);
    for (int i = 1; i <= (1 << (x - 1)); i ++)
        v[i + (1 << (x - 1))] = v[(1 << (x - 1)) - i + 1] + (1 << (x - 1));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++)
        scanf("%d", &s[i]);
    sort(s + 1, s + n + 1);
 /*   for (int i = 1; i <= n ; i ++)
        printf("%d ", s[i]);
    printf("\n");*/
    int x = 20;
    for (int i = 0; i < 20; i ++)
        help[(1 << i)] =  i + 1;
    while (!work(x) && x) x --;
    if (!x)
    {
        printf("0\n0\n");
        return 0;
    }
    build(x);
    ans[1] = 0;
    for (int i = 2; i <= (1 << x); i ++){
        ans[i] = (ans[i - 1] ^ f[help[v[i] ^ v[i - 1]]].second);
    }
 /*   if (n == 13333)
    {
        for (int i = 1; i <= x ; i ++)
            printf("%d %d\n", f[i].first, f[i].second);
    }*/
   /* if (n == 13333) {
        sort(ans + 1, ans + (1 << x) + 1);
        printf("\n");
        for (int i = 1; i <= (1 << x); i++)
            printf("%d ", ans[i]);
        printf("\n");
        for (int i = 1; i < (1 << x); i++)
            printf("%d ", ans[i] ^ ans[i + 1]);
    }*/
    printf("%d\n", x);
    for (int i = 1; i <= (1 << x) ; i ++)
        printf("%d ", ans[i]);

}