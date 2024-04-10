#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef long long Int;

Int F[1000001];
char str[1000001];
Int sL=0;
vector<Int> pufix[1000001];

int main()
{
    Int i,j;
    string s;
    Int lookfor=1;
    Int precomputed;
    Int need;
    
    cin>>s;
    
    for (i=0;i<s.length();i++)
    {
        str[i+1]=s[i];
    }
    sL=s.length();
    
    F[0]=0;
    F[1]=0;
    for (i=2;i<=sL;i++)
    {
        if (str[i]==str[lookfor])
        {
            F[i]=lookfor;
            lookfor++;
        }
        else
        {
            precomputed=lookfor-1;
            while(precomputed!=0 && str[i]!=str[precomputed+1])
            {
                precomputed=F[precomputed];
            }
            if (precomputed==0)
            {
                if (str[i]==str[1])
                {
                    F[i]=1;
                    lookfor=2;
                }
                else
                {
                    F[i]=0;
                    lookfor=1;
                }
            }
            else
            {
                F[i]=precomputed+1;
                lookfor=F[i]+1;
            }
        }
        pufix[F[i]].push_back(i);
    }
    need=F[sL];
    while(need!=0)
    {
        for (i=0;i<pufix[need].size();i++)
        {
            if (pufix[need][i]!=sL)
            {
                for (j=1;j<=need;j++)
                {
                    printf("%c",str[j]);
                }
                printf("\n");
                return 0;
            }
        }
        need=F[need];
    }
    printf("Just a legend\n");
    return 0;
}