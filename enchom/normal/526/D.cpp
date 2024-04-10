#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
#define MOD 1000000009LL
#define B 211

int n,k;
char str[1000011];

Int Hashes[1000011];
Int BASE[10000011];

bool YES[1000011];

Int GetHash(int L,int R)
{
    Int ans=(Hashes[R]-(Hashes[L-1]*BASE[R-L+1])%MOD);

    if (ans<0)
    return ans+MOD;
    else
    return ans;
}

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    int i,j,in;
    Int Sample;
    Int Test;
    int lastdone=0;

    scanf("%d %d",&n,&k);
    scanf("%s",str+1);

    BASE[0]=1;
    for (i=1;i<=n;i++)
    {
        BASE[i]=BASE[i-1]*B;
        BASE[i]%=MOD;
    }

    for (i=1;i<=n;i++)
    {
        Hashes[i]=(Hashes[i-1]*B+str[i])%MOD;
    }

    for (i=1;i*k<=n;i++)
    {
        Sample=Hashes[i];
        for (j=1;j<k;j++)
        {
            Test=GetHash(j*i+1,(j+1)*i);

            if (Test!=Sample)
            break;
        }

        if (j==k)
        {
            YES[i*k]=true;

            for (in=MAX(i*k+1,lastdone);in<=i*k+i;in++)
            {
                if (str[in]==str[in-i*k])
                {
                    YES[in]=true;
                    lastdone=in;
                }
                else
                break;
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        if (YES[i])
        printf("1");
        else
        printf("0");
    }
    printf("\n");

    return 0;
}