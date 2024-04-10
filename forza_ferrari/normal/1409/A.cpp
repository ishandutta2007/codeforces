#include<iostream>
#include<cstdio>
using namespace std;
int t,a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a<b)
            a^=b^=a^=b;
        printf("%d\n",(a-b+9)/10);
    }
    return 0;
}