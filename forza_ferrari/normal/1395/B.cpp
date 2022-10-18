#include<iostream>
#include<cstdio>
using namespace std;
int n,m,sx,sy,lst;
int main()
{
    scanf("%d%d%d%d",&n,&m,&sx,&sy);
    printf("%d %d\n",sx,sy);
    for(register int i=1;i<=m;++i)
        if(i!=sy)
            printf("%d %d\n",sx,i);
    for(register int i=1;i<=n;++i)
        if(i!=sx)
        {
            if(lst==1)
            {
                for(register int j=1;j<=m;++j)
                    printf("%d %d\n",i,j);
                lst=m;
            }
            else
            {
                for(register int j=m;j>=1;--j)
                    printf("%d %d\n",i,j);
                lst=1;
            }
        }
    return 0;
}