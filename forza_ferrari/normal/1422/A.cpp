#include<iostream>
#include<cstdio>
using namespace std;
int t,a,b,c;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",max(a,max(b,c)));
    }
    return 0;
}