#include <bits/stdc++.h>

using namespace std;

int N, K;
int sg[1000001];

int sgeven(int n)
{
    if(n<100)
        return sg[n];
    return 1^(n%2);
}

int sgodd(int n)
{
    if(n<100)
        return sg[n];
    if(n%2==0)
    {
        int x=sgodd(n/2);
        if(x!=1)
            return 1;
        return 2;
    }
    return 0;
}

int main()
{
    scanf("%d%d", &N, &K);
    K%=2;
    sg[0]=0;
    for(int i=1; i<1000001; i++)
    {
        if(i%2==1)
        {
            if(sg[i-1]==0)
                sg[i]=1;
            else
                sg[i]=0;
        }
        else
        {
            int a=sg[i-1];
            int b=sg[i/2];
            if(K%2==0)
                b=0;
            if(a!=0 && b!=0)
                sg[i]=0;
            else if(a!=1 && b!=1)
                sg[i]=1;
            else
                sg[i]=2;
        }
    }
    int x=0;
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d", &a);
        if(K==0)
            x^=sgeven(a);
        else
            x^=sgodd(a);
    }
    if(x==0)
        printf("Nicky\n");
    else
        printf("Kevin\n");
    return 0;
}