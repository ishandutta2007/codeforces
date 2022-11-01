#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);
    if(N&1)
    {
        for(int i=0; i<N; i++)
            printf("%d%c", i, " \n"[i==N-1]);
        for(int i=0; i<N; i++)
            printf("%d%c", i, " \n"[i==N-1]);
        for(int i=0; i<N; i++)
            printf("%d%c", i*2%N, " \n"[i==N-1]);
    }
    else
        printf("-1");
    return 0;
}