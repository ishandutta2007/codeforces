#include<iostream>
#include<fstream>
using namespace std;
int n,i,k,a,t;
int chk[12345],p[12345];
int main()
{
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(!chk[a])
        {
            chk[a]=1;
            p[t]=i;
            t++;
        }
    }
    if(t<k)puts("NO");
    else
    {
        puts("YES");
        for(i=0;i<k;i++)
            printf("%d ",p[i]);
    }
    return 0;
}