#include <bits/stdc++.h>

using namespace std;


bool good(int x0, int y0, int x1, int y1)
{
    if(x0==0 && y0==0)
        return true;
    if(y1==0 && y1==0)
        return false;
    while(1)
    {
        if(x0)
            x0--;
        else
            y0--;
        if((x0==0 && y0==0) || (x0-y0==x1-y1 && min(x0, y0)<min(x1, y1)))
            return true;
        x1=max(0, x1-1);
        y1=max(0, y1-1);
        if(x1==0 && y1==0)
            return false;
    }
    return false;
}

int main()
{
    int x0, y0, x1, y1;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    if(good(x0, y0, x1, y1) || good(y0, x0, y1, x1))
        printf("Polycarp\n");
    else
        printf("Vasiliy\n");
    return 0;
}