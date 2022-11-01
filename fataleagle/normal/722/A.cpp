#include <bits/stdc++.h>

using namespace std;

int N, H, M;

int main()
{
    scanf("%d%d:%d", &N, &H, &M);
    if(N==24)
    {
        if(H/10>=3)
            H%=10;
        if(H/10==2 && H%10>=4)
            H%=10;
    }
    else
    {
        if(H/10>=2)
        {
            if(H%10==0)
                H=H%10+10;
            else
                H%=10;
        }
        if(H/10==1 && H%10>=3)
            H=10;
        if(H==0)
            H=1;
    }
    if(M/10>=6)
        M%=10;
    printf("%02d:%02d\n", H, M);
    return 0;
}