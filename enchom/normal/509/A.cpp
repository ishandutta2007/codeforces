#include <iostream>
#include <stdio.h>
using namespace std;

int n;

int F(int x,int y)
{
    if (x==1 || y==1)
    return 1;
    else
    return F(x-1,y)+F(x,y-1);
}


int main()
{
    scanf("%d",&n);

    printf("%d\n",F(n,n));

    return 0;
}