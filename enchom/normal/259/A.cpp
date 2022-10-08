#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

char table[9][9];

int main()
{
    Int i,j;
    
    for (i=1;i<=8;i++)
    {
        for (j=1;j<=8;j++)
        {
            cin>>table[i][j];
        }
    }
    for (i=1;i<=8;i++)
    {
        for (j=1;j<=7;j++)
        {
            if (table[i][j]==table[i][j+1])
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}