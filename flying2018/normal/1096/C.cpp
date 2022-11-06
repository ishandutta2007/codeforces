#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int th[N];
int main()
{
    int t;
    memset(th,0x3f,sizeof(th));
    scanf("%d",&t);
    for(int i=3;i<=360;i++)
        for(int j=1;j<=i-2;j++)
            if(180*j%i==0) th[180*j/i]=min(th[180*j/i],i);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",th[n]);
    }
    return 0;
}