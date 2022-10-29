#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,mmin,mmax;
    scanf("%d%d",&n,&m);
    int ans=0;
    while(n>0&&m>0)
    {
        if(n==1&&m==1)break;
        if(n>m)
        {
            int a=n;
            n=m;
            m=a;
        }
        n+=1;
        m-=2;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}