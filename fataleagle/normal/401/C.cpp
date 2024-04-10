#include <iostream>
#include <cstdio>

using namespace std;

int zero, one, ozero, oone;
bool res[2000001];
int nres=0;

int main()
{
    scanf("%d%d", &ozero, &oone);
    zero=ozero;
    one=oone;
    while(zero>=1 && one>=2)
    {
        res[nres++]=1;
        res[nres++]=1;
        res[nres++]=0;
        zero--;
        one-=2;
    }
    if(zero==0 && one==0)
    {
        for(int i=0; i<nres; i++)
            putchar(res[i]+'0');
        putchar('\n');
    }
    else if(zero==0 && one==1)
    {
        for(int i=0; i<nres; i++)
            putchar(res[i]+'0');
        putchar('1');
        putchar('\n');
    }
    else if(zero==0 && one==2)
    {
        for(int i=0; i<nres; i++)
            putchar(res[i]+'0');
        putchar('1');
        putchar('1');
        putchar('\n');
    }
    else if(zero==0 && one>2)
    {
        puts("-1");
    }
    else if(one==0 && zero==1)
    {
        putchar('0');
        for(int i=0; i<nres; i++)
            putchar(res[i]+'0');
        putchar('\n');
    }
    else if(one==0 && zero>=2)
    {
        if(zero-1>nres/3)
            puts("-1");
        else
        {
            zero--;
            putchar('0');
            for(int i=0; i<nres; i++)
            {
                putchar(res[i]+'0');
                if(i%3==0 && zero)
                    putchar('0'), zero--;
            }
        }
    }
    else if(one==1 && zero==1)
    {
        putchar('1');
        putchar('0');
        for(int i=0; i<nres; i++)
            putchar(res[i]+'0');
        putchar('\n');
    }
    else if(one==1 && zero==2)
    {
        putchar('0');
        for(int i=0; i<nres; i++)
            putchar(res[i]+'0');
        putchar('1');
        putchar('0');
        putchar('\n');
    }
    else if(one==1 && zero>2)
    {
        if(zero-2>nres/3)
            puts("-1");
        else
        {
            zero-=2;
            putchar('0');
            for(int i=0; i<nres; i++)
            {
                putchar(res[i]+'0');
                if(i%3==0 && zero)
                    putchar('0'), zero--;
            }
            putchar('1');
            putchar('0');
            putchar('\n');
        }
    }

    return 0;
}