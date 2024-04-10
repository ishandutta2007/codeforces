#include<bits/stdc++.h>
using namespace std;

long long m=2100000000,n,i,b[12345];

void se(int x,int y,int z,int flag)
{
    if(x<0)
    {
        int t=int(sqrt(y));
        if(y==t*t&&m>z&&z!=i&&flag)m=z;
        return;
    }
    if(z>=m)return;
    if(!flag&&!b[x])
    {
        se(x-1,y,z+1,0);
    }
    else
    {
        se(x-1,y*10+b[x],z,1);
        se(x-1,y,z+1,flag);
    }
}

int main()
{
    scanf("%I64d",&n);
    while(n)
    {
        b[i++]=n%10;
        n=n/10;
    }
    se(i-1,0,0,0);
    if(m!=2100000000)
    {
        printf("%I64d",m);
    }
    else
    {
        printf("-1");
    }
    return 0;
}