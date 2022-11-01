#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", N/2);
    if(N%2==1)
    {
        printf("3");
        for(int i=1; i<N/2; i++)
            printf(" 2");
        printf("\n");
    }
    else
    {
        for(int i=0; i<N/2; i++)
            printf("2 ");
        printf("\n");
    }
    return 0;
}