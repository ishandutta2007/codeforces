#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        puts("2");
        int tmp=n;
        for(register int i=n-1;i>=1;--i)
        {
            printf("%d %d\n",i,tmp);
            tmp=(i+tmp+1)>>1;
        }
    }
    return 0;
}