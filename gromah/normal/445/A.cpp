#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000 + 5
int n, m;
bool Map[N][N];
char ch;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            ch = '\n';
            while (ch != '.' && ch != '-') ch = getchar();
            if (ch == '-') Map[i][j] = 0;
                else Map[i][j] = 1;
        }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
            if (!Map[i][j]) printf("-");
            else
            {
                if ((i + j) & 1) printf("W");
                    else printf("B");
            }
        printf("\n");
    }
}