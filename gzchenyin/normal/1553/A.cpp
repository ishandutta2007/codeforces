#include<cstdio>
using namespace std;
int n,t;
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("%d\n",(n+1)/10);
    }
}