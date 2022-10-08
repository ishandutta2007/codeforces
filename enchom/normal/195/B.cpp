#include <iostream>
#include <stdio.h>
using namespace std;

int start[100001],sL=0;

int main()
{
    int n,m;
    int left,right;
    int ctr,uk;
    bool rightB;
    scanf("%d %d",&n,&m);
    sL=1;
    start[1]=(m+1)/2;
    left=start[1]-1;
    right=start[1]+1;
    
    if (m%2==0)
    rightB=true;
    else
    rightB=false;
    
    
    while (sL<m)
    {
        if (rightB)
        {
            sL++;
            start[sL]=right;
            right++;
            rightB=false;
        }
        else
        {
            sL++;
            start[sL]=left;
            left--;
            rightB=true;
        }
    }
    ctr=0;
    uk=1;
    while (ctr<n)
    {
        printf("%d\n",start[uk]);
        uk++;
        
        if (uk>sL)
        uk-=sL;
        
        ctr++;
    }
    return 0;
}