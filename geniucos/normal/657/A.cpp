#include<iomanip>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, D, H;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &D, &H);
if (D == H && D == 1 && N > 2)
{
    printf ("-1\n");
    return 0;
}
if (D == H && D == 1 && N == 2)
{
    printf ("1 2\n");
    return 0;
}
if (H * 2 < D)
{
    printf ("-1\n");
    return 0;
}
for (int i=2; i<=H + 1; i++)
    printf ("%d %d\n", i - 1, i);
if (D - H >= 1)
{
    printf ("1 %d\n", H + 2);
    for (int i=H + 3; i<=D + 1; i++)
        printf ("%d %d\n", i - 1, i);
    for (int i=D + 2; i<=N; i++)
        printf ("1 %d\n", i);
    return 0;
}
for (int i=H + 2; i<=N; i++)
    printf ("%d %d\n", H, i);
return 0;
}