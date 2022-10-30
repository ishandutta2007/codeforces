#include <bits/stdc++.h>

using namespace std;

int N, D, H;

int main()
{
    scanf("%d%d%d", &N, &D, &H);
    if(D==1)
    {
        if(N!=2)
            printf("-1\n");
        else
            printf("%d %d\n", 1, 2);
        return 0;
    }
    int B=(D+1)/2;
    if(H<B)
        return printf("-1\n"), 0;
    if(H==B)
    {
        for(int i=0; i<B; i++)
            printf("%d %d\n", i+1, i+2);
        for(int i=0; i<D-B; i++)
            printf("%d %d\n", i==0?1:(i+B+1), i+B+2);
        for(int i=0; i<N-D-1; i++)
            printf("%d %d\n", 1, i+D+2);
    }
    else
    {
        for(int i=0; i<H; i++)
            printf("%d %d\n", i+1, i+2);
        for(int i=0; i<D-H; i++)
            printf("%d %d\n", i==0?1:(i+H+1), i+H+2);
        for(int i=0; i<N-D-1; i++)
            printf("%d %d\n", (H==D)?2:1, i+D+2);
    }
    return 0;
}