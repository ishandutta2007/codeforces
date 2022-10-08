#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long Int;

struct StandartStruct
{
    Int fours,sevens;
};

StandartStruct possible[1000001];

int main()
{
    Int i;
    Int sdigits,fdigits;
    Int n;
    
    scanf("%I64d",&n);
    
    possible[0].fours=0;
    possible[0].sevens=0;
    
    possible[1].fours=-1;
    possible[1].sevens=-1;
    
    possible[2].fours=-1;
    possible[2].sevens=-1;
    
    possible[3].fours=-1;
    possible[3].sevens=-1;
    
    possible[4].fours=1;
    possible[4].sevens=0;
    
    possible[5].fours=-1;
    possible[5].sevens=-1;
    
    possible[6].fours=-1;
    possible[6].sevens=-1;
    
    for (i=7;i<=1000000;i++)
    {
        fdigits=possible[i-4].fours+possible[i-4].sevens;
        sdigits=possible[i-7].fours+possible[i-7].sevens;
        
        if (fdigits==-2 && sdigits!=-2)
        {
            possible[i].fours=possible[i-7].fours;
            possible[i].sevens=possible[i-7].sevens+1;
            continue;
        }
        else if (fdigits!=-2 && sdigits==-2)
        {
            possible[i].fours=possible[i-4].fours+1;
            possible[i].sevens=possible[i-4].sevens;
            continue;
        }
        else if (fdigits==-2 && sdigits==-2)
        {
            possible[i].fours=-1;
            possible[i].sevens=-1;
            continue;
        }
        
        if (fdigits<=sdigits)
        {
            possible[i].fours=possible[i-4].fours+1;
            possible[i].sevens=possible[i-4].sevens;
        }
        else
        {
            possible[i].fours=possible[i-7].fours;
            possible[i].sevens=possible[i-7].sevens+1;
        }
    }
    if (possible[n].fours==-1)
    {
        printf("-1\n");
        return 0;
    }
    for (i=1;i<=possible[n].fours;i++)
    {
        printf("4");
    }
    for (i=1;i<=possible[n].sevens;i++)
    {
        printf("7");
    }
    printf("\n");
    return 0;
}