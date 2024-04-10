#include <bits/stdc++.h>
using namespace std;

int r, s;
char mat [510] [510];

int main()
{
    scanf("%d%d", &r, &s);
    for (int i = 0; i < r; i++)
    {
        scanf("%s", mat [i]);
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (mat [i] [j] == 'W')
            {
                if (i > 0 && mat [i - 1] [j] == 'S') {printf("No"); return 0;}
                if (i < r - 1 && mat [i + 1] [j] == 'S') {printf("No"); return 0;}
                if (j > 0 && mat [i] [j - 1] == 'S') {printf("No"); return 0;}
                if (j < s - 1 && mat [i] [j + 1] == 'S') {printf("No"); return 0;}
            }
        }
    }
    printf("Yes\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (mat [i] [j] == '.') printf("D");
            else printf("%c", mat [i] [j]);
        }
        printf("\n");
    }
    return 0;
}