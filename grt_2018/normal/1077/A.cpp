#include <iostream>
#include <cstdio>

using namespace std;

int z,a,b,k;
long long w;

int main()
{
    scanf("%d",&z);
    for(int i=0; i<z;i++)
    {
        scanf("%d %d %d",&a,&b,&k);
        w = (long long)(a-b)*(k/2);
        if(k%2==1)
            w+=a;
        printf("%I64d\n",w);
    }
    return 0;
}