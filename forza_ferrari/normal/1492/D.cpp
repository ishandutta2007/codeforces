#include<iostream>
#include<cstdio>
using namespace std;
int a,b,k,x[200001],y[200001];
int main()
{
    scanf("%d%d%d",&a,&b,&k);
    if(!a)
    {
        if(k)
        {
            puts("No");
            return 0;
        }
        else
        {
            puts("Yes");
            for(register int i=1;i<=2;++i)
            {
                for(register int i=1;i<=b;++i)
                    putchar('1');
                puts("");
            }
            return 0;
        }
    }
    if(b==1)
    {
        if(k)
        {
            puts("No");
            return 0;
        }
        else
        {
            puts("Yes");
            for(register int i=1;i<=2;++i)
            {
                putchar('1');
                for(register int j=1;j<=a;++j)
                    putchar('0');
                puts("");
            }
            return 0;
        }
        return 0;
    }
    if(a+b-1<=k)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    x[k+1]=1;
    y[1]=1;
    int p=a-1,q=b-1;
    for(register int i=a+b;i>1;--i)
    {
        if(i==k+1||i==1)
            continue;
        if(q)
        {
            --q;
            x[i]=y[i]=1;
        }
    }
    for(register int i=a+b;i>=1;--i)
        printf("%d",x[i]);
    puts("");
    for(register int i=a+b;i>=1;--i)
        printf("%d",y[i]);
    puts("");
    return 0;
}