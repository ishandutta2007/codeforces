#include <iostream>
#include <fstream>
using namespace std;

int i, cnt1, cnt2, cnt, p1, p2, n, m;
int a[123456], b[123456];

int main()
{
    scanf ("%d%d", &n, &m);
    for (i = 0; i < n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    for (i = 0; i < m; i ++)
    {
        scanf ("%d", &b[i]);
    }
    cnt1 = a[p1];
    cnt2 = b[p2];
    p1 ++;
    p2 ++;
    cnt = 0;
    while (p1 < n || p2 < m)
    {
        if (cnt1 == cnt2)
        {
            cnt1 = a[p1];
            p1 ++;
            cnt2 = 0;
            cnt ++;
        }
        else if (cnt1 > cnt2)
        {
            cnt2 += b[p2];
            p2 ++;
        }
        else
        {
            cnt1 += a[p1];
            p1 ++;
        }
    }
    printf ("%d", cnt + 1);
    return 0;
}