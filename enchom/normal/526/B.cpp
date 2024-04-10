#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int a[2500001];
int biggest[2500001];
int deep;
int lamps=0;

inline int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

void Deepest(int ver,int depth,int sum)
{
    if (depth==n)
    {
        biggest[ver]=sum;
        return;
    }

    Deepest(2*ver,depth+1,sum+a[2*ver]);
    Deepest(2*ver+1,depth+1,sum+a[2*ver+1]);

    biggest[ver]=MAX(biggest[2*ver],biggest[2*ver+1]);

    return;
}

void PutLamps(int ver,int depth,int added)
{
    int canadd=deep-(biggest[ver]+added);
    lamps+=canadd;

    if (depth==n)
    return;

    PutLamps(2*ver,depth+1,added+canadd);
    PutLamps(2*ver+1,depth+1,added+canadd);

    return;
}

int main()
{
    int i;

    scanf("%d",&n);

    for (i=2;i<=(1<<(n+1))-1;i++)
    {
        scanf("%d",&a[i]);
    }

    Deepest(1,0,0);

    deep=biggest[1];

    PutLamps(2,1,0);
    PutLamps(3,1,0);

    printf("%d\n",lamps);

    return 0;
}