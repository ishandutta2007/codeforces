#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int n,maxx=-1e9,maxy=-1e9,minx=1e9,miny=1e9;
    scanf("%d",&n);
    while(n--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        maxx=max(maxx,x);
        maxy=max(maxy,y);
        minx=min(minx,x);
        miny=min(miny,y);
    }
    printf("%I64d",(long long)max(maxx-minx,maxy-miny)*max(maxx-minx,maxy-miny));

}