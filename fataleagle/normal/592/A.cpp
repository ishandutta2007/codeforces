#include <bits/stdc++.h>

using namespace std;

char grid[9][9];

int main()
{
    for(int i=0; i<8; i++)
        scanf("%s", grid[i]);
    int a=0x3f3f3f3f;
    for(int j=0; j<8; j++)
    {
        int p=0x3f3f3f3f;
        for(int i=0; i<8; i++)
        {
            if(grid[i][j]=='B')
                break;
            if(grid[i][j]=='W')
            {
                p=i;
                break;
            }
        }
        a=min(a, p);
    }
    int b=0x3f3f3f3f;
    for(int j=0; j<8; j++)
    {
        int p=0x3f3f3f3f;
        for(int i=7; i>=0; i--)
        {
            if(grid[i][j]=='W')
                break;
            if(grid[i][j]=='B')
            {
                p=7-i;
                break;
            }
        }
        b=min(b, p);
    }
    if(a<=b)
        printf("A\n");
    else
        printf("B\n");
    return 0;
}