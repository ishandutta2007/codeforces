#include<cstdio>
#include<cmath>
using namespace std;
int n,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n%2==1)
        {
            printf("NO\n");
            continue;
        }
        if(((int)(sqrt(n)+0.5))*((int)(sqrt(n)+0.5))==n) printf("YES\n");
        else if(((int)(sqrt(2*n)+0.5))*((int)(sqrt(2*n)+0.5))==2*n) printf("YES\n");
        else printf("NO\n");
    }
}