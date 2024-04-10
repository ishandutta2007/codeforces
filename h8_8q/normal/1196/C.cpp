#include<bits/stdc++.h>

using namespace std;

int q,n,x,y,f1,f2,f3,f4;

int main()
{
    scanf("%d",&q);
    while (q--)
	{
        scanf("%d",&n);
        int maxx=100000,maxy=100000;
        int minx=-100000,miny=-100000;
        while(n--)
		{
            scanf("%d%d%d%d%d%d",&x,&y,&f1,&f2,&f3,&f4);
            if(!f1)minx=max(minx,x);
            if(!f2)maxy=min(maxy,y);
            if(!f3)maxx=min(maxx,x);
            if(!f4)miny=max(miny,y);
        }
        if(minx<=maxx&&miny<=maxy)
            printf("1 %d %d\n",minx,miny);
        else cout << "0\n";
    }
    return 0;
}