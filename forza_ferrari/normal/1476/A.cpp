#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k<n)
            printf("%d\n",(n%k!=0)+1);
        else
            printf("%d\n",k/n+(k%n!=0));
    }
    return 0;
}