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
        bool flag=0;
        for(register int i=0;i<=n;i+=7)
        {
            for(register int j=0;j<=n-i;j+=5)
                if((n-i-j)%3==0)
                {
                    printf("%d %d %d\n",(n-i-j)/3,j/5,i/7);
                    flag=1;
                    break;
                }
            if(flag)
                break;
        }
        if(!flag)
            puts("-1");
    }
    return 0;
}