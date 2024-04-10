#include <bits/stdc++.h>
using namespace std;

int n, m, k, rj = 0;
char mat [2005] [2005];

int main()
{
    int br;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", mat [i]);
    }
    for (int i = 0; i < n; i++)
    {
        br = 0;
        for (int j = 0; j < m; j++)
        {
            if (mat [i] [j] == '.') br++;
            else br = 0;
            if (br >= k) rj++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        br = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat [j] [i] == '.') br++;
            else br = 0;
            if (br >= k) rj++;
        }
    }
    if (k > 1)
        printf("%d", rj);
    else printf("%d", rj / 2);
    return 0;
}