#include<iostream>
#include<cstdio>
using namespace std;
int t,n,s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&s);
        printf("%d\n",s/(n-((n+1)>>1)+1));
    }
    return 0;
}