#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);
    if(N<4)
        printf("NO\n");
    else
    {
        printf("YES\n");
        if(N&1)
        {
            printf("5 * 4 = 20\n");
            printf("3 - 1 = 2\n");
            printf("2 * 2 = 4\n");
            printf("20 + 4 = 24\n");
        }
        else
        {
            printf("4 * 3 = 12\n");
            printf("12 * 2 = 24\n");
            printf("24 * 1 = 24\n");
        }
        for(int i=5+(N&1); i<=N; i+=2)
        {
            printf("%d - %d = 1\n", i+1, i);
            printf("24 * 1 = 24\n");
        }
    }
    return 0;
}